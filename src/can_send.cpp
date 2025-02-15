#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <sensor_msgs/msg/joy.hpp>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "robomas_plugins/msg/frame.hpp"
#include "can_conection/can_conection_utils.hpp"

using std::placeholders::_1;

class Can_send : public rclcpp::Node
{
private:
  void controller_callback(const sensor_msgs::msg::Joy & msg) const
  {
    if(msg.buttons[7]){
      can_setting_->publish(can_conection::solenoid_utils::to_can_mode(0x250,1,0));
    }
    if(msg.buttons[6]){
      can_setting_->publish(can_conection::solenoid_utils::to_can_mode(0x250,0,1));
    }
    if(msg.buttons[2] == true){
      can_setting_->publish(can_conection::solenoid_utils::to_can_mode(0x251,1,0));
    }//エアシリンダー
    if(msg.buttons[3] == true){
      can_setting_->publish(can_conection::solenoid_utils::to_can_mode(0x251,0,1));
    }//エアシリンダー
    if(msg.buttons[10] == true){
      can_setting_->publish(can_conection::solenoid_utils::to_can_mode(0x252,1,0));
    }//LED
    if(msg.buttons[9] == true){
      can_setting_->publish(can_conection::solenoid_utils::to_can_mode(0x252,0,1));
    }//LED
  } 
  

public:
  Can_send()
  : Node("can_send")
  {
    this->controller_ = this->create_subscription<sensor_msgs::msg::Joy>("joy", 10, std::bind(&Can_send::controller_callback, this, std::placeholders::_1));
    this->can_setting_ = this->create_publisher<robomas_plugins::msg::Frame>("robomas_can_tx", 10);
  }

  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr controller_;
  rclcpp::Publisher<robomas_plugins::msg::Frame>::SharedPtr can_setting_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Can_send>());
  rclcpp::shutdown();
  return 0;
}
