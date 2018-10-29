// Copyright 2015-2018 Elviss Strazdins. All rights reserved.

#pragma once

#if !defined(__OBJC__)
#include <objc/objc.h>
#endif

#include "core/Engine.hpp"

namespace ouzel
{
    class EngineMacOS final: public Engine
    {
    public:
        EngineMacOS(int argc, char* argv[]);
        virtual ~EngineMacOS();

        void run();

        void executeOnMainThread(const std::function<void(void)>& func) override;

        void openURL(const std::string& url) override;

        void setScreenSaverEnabled(bool newScreenSaverEnabled) override;

        void executeAll();

    private:
        void main() override;

        std::queue<std::function<void(void)>> executeQueue;
        std::mutex executeMutex;

        uint32_t noSleepAssertionID = 0;
        id executeHanlder = nil;
    };
}
