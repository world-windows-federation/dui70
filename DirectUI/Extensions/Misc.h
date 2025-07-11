#pragma once

namespace DirectUI
{
	enum DUSER_MSG_FLAG : UINT32
	{
		GMF_DIRECT = 0x00000000, // OnMessage
		GMF_ROUTED = 0x00000001, // PreviewMessage
		GMF_BUBBLED = 0x00000002, // PostMessage
		GMF_EVENT = 0x00000003, // Message -> Event
		GMF_DESTINATION = 0x00000003, // Message reach dest (same as event)
	};

	enum DUSER_INPUT_DEVICE : UINT32
	{
		GINPUT_MOUSE = 0,
		GINPUT_KEYBOARD = 1,
		GINPUT_JOYSTICK = 2,
	};

	enum DUSER_INPUT_CODE : UINT32
	{
		GMOUSE_MOVE = 0,
		GMOUSE_DOWN = 1,
		GMOUSE_UP = 2,
		GMOUSE_DRAG = 3,
		GMOUSE_HOVER = 4,
		GMOUSE_WHEEL = 5,
		GMOUSE_MAX = 5,

		GBUTTON_NONE = 0,
		GBUTTON_LEFT = 1,
		GBUTTON_RIGHT = 2,
		GBUTTON_MIDDLE = 3,
		GBUTTON_MAX = 3,
	};

	// bitflags
	enum DUSER_INPUT_MODIFIERS : UINT32
	{
		GMODIFIER_NONE = 0x00000000,

		GMODIFIER_LCONTROL = 0x00000001,
		GMODIFIER_RCONTROL = 0x00000002,
		GMODIFIER_LSHIFT = 0x00000004,
		GMODIFIER_RSHIFT = 0x00000008,
		GMODIFIER_LALT = 0x00000010,
		GMODIFIER_RALT = 0x00000020,
		GMODIFIER_LBUTTON = 0x00000040,
		GMODIFIER_RBUTTON = 0x00000080,
		GMODIFIER_MBUTTON = 0x00000100,

		GMODIFIER_CONTROL = (GMODIFIER_LCONTROL | GMODIFIER_RCONTROL),
		GMODIFIER_SHIFT = (GMODIFIER_LSHIFT | GMODIFIER_RSHIFT),
		GMODIFIER_ALT = (GMODIFIER_LALT | GMODIFIER_RALT),
	};

	enum TOUCHTOOLTIP_CREATE_FLAGS
	{
		TTTCF_DEFAULT = 0x0,
		TTTCF_DESKTOP_DPI = 0x1,
		TTTCF_CONSTRAIN_TO_WORKSPACE = 0x2,
		TTTCF_CONSTRAIN_TO_MONITOR = 0x4,
	};

	enum TOUCHTOOLTIP_OPTION_FLAGS
	{
		TTTOF_DEFAULT = 0x0,
		TTTOF_LAST_LINE_SUBTITLE = 0x1,
		TTTOF_SLIDER = 0x2,
		TTTOF_NO_WRAP = 0x4,
		TTTOF_NO_UIA_OPENED_EVENT = 0x8,
		TTTOF_SCALE_WITH_OWNER = 0x10,
	};

	enum TOUCHTOOLTIP_INPUT
	{
		TTTI_PROGRAMMATIC = 0,
		TTTI_KEYBOARD = 1,
		TTTI_MOUSE = 2,
		TTTI_POINTER = 3,
		TTTI_COUNT = 4,
	};

	enum TOUCHTOOLTIP_PLACEMENT
	{
		TTTP_ABOVE = 0,
		TTTP_BELOW = 1,
		TTTP_LEFT = 2,
		TTTP_RIGHT = 3,
		TTTP_COUNT = 4,
	};

	enum TOUCHTOOLTIP_TYPE
	{
		TTTT_TEXT = 0,
		TTTT_RICH = 1,
		TTTT_COUNT = 2,
	};

	enum TOUCHTOOLTIP_DELAY
	{
		TTTD_NORMAL = 0,
		TTTD_RESHOW = 1,
		TTTD_COUNT = 2,
	};

	enum TOUCHTOOLTIP_LAYOUT_DIRECTION
	{
		TTTLD_INHERIT = 0,
		TTTLD_LTR = 1,
		TTTLD_RTL = 2,
		TTTLD_COUNT = 3,
	};

	enum ActiveState
	{
		AS_HIDDEN = 0,
		AS_REST = 1,
		AS_MOUSE = 2,
		AS_PAN = 3,
	};
} // namespace DirectUI
