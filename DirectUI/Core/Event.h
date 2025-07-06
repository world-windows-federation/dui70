#pragma once

namespace DirectUI
{
	struct Event
	{
		Element* peTarget;
		UID uidType;
		bool fHandled;
		DUSER_MSG_FLAG nStage;
		bool fUIAHandled;
	};

	struct InputEvent
	{
		Element* peTarget;
		bool fHandled;
		DUSER_MSG_FLAG nStage;
		DUSER_INPUT_DEVICE nDevice;
		DUSER_INPUT_CODE nCode;
		DUSER_INPUT_MODIFIERS uModifiers;
	};

	struct PointerEvent : InputEvent
	{
		POINT ptClientPxl;
		UINT nPointerID;
		BOOL fPrimary;
	};

	struct PointerTapEvent : PointerEvent
	{
		UINT cTaps;
		BOOL fPressAndTap;
		BOOL fWithin;
		UINT nFlags;
		BOOL fPressAndHold;
	};

	struct PointerEnterEvent : PointerEvent
	{
	};

	struct PointerLeaveEvent : PointerEvent
	{
	};

	struct PointerCancelEvent : PointerEvent
	{
		UINT nCancelReason;
	};

	struct PointerManipulationEvent : PointerEvent
	{
		UINT nBeginDuringEnd;
		SIZE szOffsetFromPanStart;
		float fltZoom;
		float fltExpansion;
		float fltRotation;
		UINT nFlags;
	};

	struct PointerDragEvent : PointerEvent
	{
		SIZE sizeDelta;
		BOOL fWithin;
	};

	struct MouseEvent : InputEvent
	{
		POINT ptClientPxl;
		BYTE bButton;
		UINT nFlags;
	};

	struct MouseWheelEvent : MouseEvent
	{
		short sWheel;
	};

	struct MouseDragEvent : MouseEvent
	{
		SIZE sizeDelta;
		BOOL fWithin;
	};

	struct MouseClickEvent : MouseEvent
	{
		UINT cClicks;
	};

	struct KeyboardEvent : InputEvent
	{
		WCHAR ch;
		WORD cRep;
		WORD wFlags;
	};

	struct KeyboardNavigateEvent : Event
	{
		int iNavDir;
		bool fSetFocus;
	};

	struct AnimateScrollEvent : Event
	{
		int dDistance;
		bool fVertical;
	};
}
