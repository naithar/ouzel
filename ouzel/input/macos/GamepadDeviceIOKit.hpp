// Copyright 2015-2018 Elviss Strazdins. All rights reserved.

#pragma once

#include <unordered_map>
#include <IOKit/hid/IOHIDManager.h>

#include "input/macos/GamepadDeviceMacOS.hpp"
#include "input/Gamepad.hpp"

namespace ouzel
{
    namespace input
    {
        class GamepadDeviceIOKit: public GamepadDeviceMacOS
        {
        public:
            GamepadDeviceIOKit(InputSystem& initInputSystem,
                               uint32_t initId,
                               IOHIDDeviceRef initDevice);

            inline IOHIDDeviceRef getDevice() const { return device; }

            void handleInput(IOHIDValueRef value);

        private:
            void handleAxisChange(CFIndex oldValue, CFIndex newValue,
                                  CFIndex min, CFIndex range,
                                  Gamepad::Button negativeButton,
                                  Gamepad::Button positiveButton);

            IOHIDDeviceRef device = nullptr;

            IOHIDElementRef hatElement = nullptr;
            CFIndex hatValue = 8;

            struct Button
            {
                Gamepad::Button button = Gamepad::Button::NONE;
                CFIndex value = 0;
            };

            std::unordered_map<IOHIDElementRef, Button> buttons;

            struct Axis
            {
                Gamepad::Axis axis = Gamepad::Axis::NONE;
                CFIndex min = 0;
                CFIndex max = 0;
                CFIndex range = 0;
                CFIndex value = 0;
                Gamepad::Button negativeButton = Gamepad::Button::NONE;
                Gamepad::Button positiveButton = Gamepad::Button::NONE;
            };

            std::unordered_map<IOHIDElementRef, Axis> axes;

            bool hasLeftTrigger = false;
            bool hasRightTrigger = false;
        };
    } // namespace input
} // namespace ouzel
