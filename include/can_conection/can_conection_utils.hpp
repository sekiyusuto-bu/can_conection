#include <cstdint>
#include <robomas_plugins/msg/frame.hpp>

namespace can_conection::solenoid_utils{
    inline auto to_high_mode(std::uint16_t can_index) -> robomas_plugins::msg::Frame{
    robomas_plugins::msg::Frame message{};
    message.id = 0x250;
    message.is_rtr = false;
    message.is_extended = false;
    message.is_error = false;
    message.dlc = 2;
    message.data[can_index] = 0;
    return message;
    }

    inline auto to_low_mode() -> robomas_plugins::msg::Frame {
    robomas_plugins::msg::Frame message{};
    message.id = 0x250;
    message.is_rtr = false;
    message.is_extended = false;
    message.is_error = false;
    message.dlc = 0;
    return message;
    }
}