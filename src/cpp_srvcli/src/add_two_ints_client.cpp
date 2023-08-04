#include <chrono>
#include <cstdlib>
#include <memory>

#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class AdditionClient : public rclcpp::Node {
private:
    rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client_;

public:
    AdditionClient() : Node("addition_client") {
        client_ = this->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");
    }

    void call_service(long first, long second) {
        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a = first;
        request->b = second;

        while (!client_->wait_for_service(1s)) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "AdditionClient: Interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "AdditionClient: Service not available, waiting again...");
        }

        // Wait for the result.
        auto result = client_->async_send_request(request);
        if (rclcpp::spin_until_future_complete(shared_from_this(), result) == rclcpp::FutureReturnCode::SUCCESS) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "AdditionClient: Sum: %ld", result.get()->sum);
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "AdditionClient: Failed to call service add_two_ints");
        }
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    if (argc != 3) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: add_two_ints_client X Y");
        return -1;
    }

    std::shared_ptr<AdditionClient> clientNode = std::make_shared<AdditionClient>();
    clientNode->call_service(atoll(argv[1]), atoll(argv[2]));

    rclcpp::shutdown();
    return 0;
}
