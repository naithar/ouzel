// Copyright 2015-2018 Elviss Strazdins. All rights reserved.

#pragma once

#include "input/InputDevice.hpp"
#include "input/Keyboard.hpp"

namespace ouzel
{
    namespace input
    {
        class InputSystemMacOS;

        class KeyboardMacOS: public InputDevice
        {
        public:
            KeyboardMacOS(InputSystemMacOS& initInputSystemMacOS,
                          uint32_t initDeviceId):
                InputDevice(initDeviceId),
                inputSystemMacOS(initInputSystemMacOS)
            {
            }

            virtual ~KeyboardMacOS() {}

            void handleKeyPress(Keyboard::Key key, uint32_t modifiers);
            void handleKeyRelease(Keyboard::Key key, uint32_t modifiers);

        private:
            InputSystemMacOS& inputSystemMacOS;
        };
    } // namespace input
} // namespace ouzel
