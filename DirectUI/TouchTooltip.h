#pragma once

namespace DirectUI
{
    enum TOUCHTOOLTIP_INPUT
    {
        TTTI_PROGRAMMATIC = 0,
        TTTI_KEYBOARD = 1,
        TTTI_MOUSE = 2,
        TTTI_POINTER = 3,
        TTTI_COUNT = 4
    };

    enum TOUCHTOOLTIP_TYPE
    {
        TTTT_TEXT = 0,
        TTTT_RICH = 1,
        TTTT_COUNT = 2
    };

    enum TOUCHTOOLTIP_DELAY
    {
        TTTD_NORMAL = 0,
        TTTD_RESHOW = 1,
        TTTD_COUNT = 2
    };

    class TouchTooltip
    {
    };
}
