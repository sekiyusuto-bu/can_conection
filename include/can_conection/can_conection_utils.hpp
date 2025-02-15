#include <cstdint>
#include <robomas_plugins/msg/frame.hpp>

namespace can_conection::solenoid_utils{
    inline auto to_can_mode(uint32_t solenoid_id, uint8_t solenoid_data0, uint8_t solenoid_data1) -> robomas_plugins::msg::Frame{
    robomas_plugins::msg::Frame message{};
    message.id = solenoid_id;
    message.is_rtr = false;
    message.is_extended = false;
    message.is_error = false;
    message.dlc = 8;
    message.data[0] = solenoid_data0;
    message.data[1] = solenoid_data1;
    return message;
    }
}
