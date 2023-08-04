#include <functional>
#include <memory>

#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::placeholders;
class AdditionServer : public rclcpp::Node {
private:
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service_;

    void add_callback(const std::shared_ptr<rmw_request_id_t> request_header,
                      const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
                      std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response) {
        (void)request_header;
        response->sum = request->a + request->b;
        RCLCPP_INFO(this->get_logger(), "AdditionServer: Incoming request\na: %ld b: %ld",
                    (long)request->a, (long)request->b);
        RCLCPP_INFO(this->get_logger(), "AdditionServer: sending back response: [%ld]",
                    (long)response->sum);
    }

public:
    AdditionServer() : Node("addition_server") {
        service_ = this->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints",
                                                                             std::bind(&AdditionServer::add_callback, this, _1, _2, _3));
        RCLCPP_INFO(this->get_logger(), "AdditionServer: Ready to add two ints.");
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AdditionServer>());
    rclcpp::shutdown();
    return 0;
}
