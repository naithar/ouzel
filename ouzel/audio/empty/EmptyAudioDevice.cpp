// Copyright 2015-2019 Elviss Strazdins. All rights reserved.

#include "EmptyAudioDevice.hpp"

namespace ouzel
{
    namespace audio
    {
        namespace empty
        {
            AudioDevice::AudioDevice(uint32_t initBufferSize,
                                     uint32_t initSampleRate,
                                     uint16_t initChannels,
                                     const std::function<void(uint32_t frames,
                                                              uint16_t channels,
                                                              uint32_t sampleRate,
                                                              std::vector<float>& samples)>& initDataGetter):
                audio::AudioDevice(Driver::EMPTY, initBufferSize, initSampleRate, initChannels, initDataGetter)
            {
            }
        } // namespace empty
    } // namespace audio
} // namespace ouzel
