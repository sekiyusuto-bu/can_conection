#include <cstdint>
#include <robomas_plugins/msg/frame.hpp>

namespace can_conection::solenoid_utils{
    inline auto to_high_mode() -> robomas_plugins::msg::Frame{
    robomas_plugins::msg::Frame message{};
    message.id = 0x250;
    message.is_rtr = false;
    message.is_extended = false;
    message.is_error = false;
    message.dlc = 8;
    message.data[0] = 1;
    return message;
    }

    inline auto to_low_mode() -> robomas_plugins::msg::Frame {
    robomas_plugins::msg::Frame message{};
    message.id = 0x250;
    message.is_rtr = false;
    message.is_extended = false;
    message.is_error = false;
    message.dlc = 8;
    message.data[1] = 1;
    return message;
    }

    inline auto to_air_mode() -> robomas_plugins::msg::Frame{
    robomas_plugins::msg::Frame message{};
    message.id = 0x251;
    message.is_rtr = false;
    message.is_extended = false;
    message.is_error = false;
    message.dlc = 8;
    message.data[0] = 1;
    return message;
    }
    
    inline auto to_right_mode() -> robomas_plugins::msg::Frame {
    robomas_plugins::msg::Frame message{};
    message.id = 0x251;
    message.is_rtr = false;
    message.is_extended = false;
    message.is_error = false;
    message.dlc = 8;
    message.data[1] = 1;
    return message;
    }
}