// Copyright 2015-2020 Elviss Strazdins. All rights reserved.

#ifndef OUZEL_GRAPHICS_RENDERER_CAMERA_HPP
#define OUZEL_GRAPHICS_RENDERER_CAMERA_HPP

namespace ouzel::graphics::renderer
{
    class Camera final
    {
    public:
        enum class ProjectionMode
        {
            custom,
            orthographic,
            perspective
        };

        enum class ScaleMode
        {
            noScale,
            exactFit,
            noBorder,
            showAll
        };

        Camera() noexcept = default;
    };
}

#endif // OUZEL_GRAPHICS_RENDERER_CAMERA_HPP