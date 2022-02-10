#include "mvBasicWidgets.h"
#include "AppItems/mvFontItems.h"
#include "AppItems/mvThemes.h"
#include "AppItems/containers/mvDragPayload.h"
#include "mvPyObject.h"
#include "AppItems/mvItemHandlers.h"
#include "mvPythonExceptions.h"
#include <misc/cpp/imgui_stdlib.h>

//-----------------------------------------------------------------------------
// [SECTION] get_item_configuration(...) specifics
//-----------------------------------------------------------------------------

void
DearPyGui::fill_configuration_dict(const mvButtonConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	mvPyObject py_small = ToPyBool(inConfig.small_button);
	mvPyObject py_arrow = ToPyBool(inConfig.arrow);
	mvPyObject py_direction = ToPyInt(inConfig.direction);

	PyDict_SetItemString(outDict, "small", py_small);
	PyDict_SetItemString(outDict, "arrow", py_arrow);
	PyDict_SetItemString(outDict, "direction", py_direction);
}

void
DearPyGui::fill_configuration_dict(const mvComboConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		mvPyObject py_value = ToPyBool(flags & flag);
		PyDict_SetItemString(outDict, keyword, py_value);
	};
	checkbitset("popup_align_left", ImGuiComboFlags_PopupAlignLeft, inConfig.flags);
	checkbitset("no_arrow_button", ImGuiComboFlags_NoArrowButton, inConfig.flags);
	checkbitset("no_preview", ImGuiComboFlags_NoPreview, inConfig.flags);

	mvUUID mode = (long)mvComboHeightMode::mvComboHeight_Largest;
	if (inConfig.flags & ImGuiComboFlags_HeightSmall) mode = (long)mvComboHeightMode::mvComboHeight_Small;
	else if (inConfig.flags & ImGuiComboFlags_HeightRegular) mode = (long)mvComboHeightMode::mvComboHeight_Regular;
	else if (inConfig.flags & ImGuiComboFlags_HeightLarge) mode = (long)mvComboHeightMode::mvComboHeight_Large;

	mvPyObject py_height_mode = ToPyLong(mode);
	mvPyObject py_items = ToPyList(inConfig.items);
	PyDict_SetItemString(outDict, "height_mode", py_height_mode);
	PyDict_SetItemString(outDict, "items", py_items);
}

void
DearPyGui::fill_configuration_dict(const mvDragFloatConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	mvPyObject py_format = ToPyString(inConfig.format);
	mvPyObject py_speed = ToPyFloat(inConfig.speed);
	mvPyObject py_min_value = ToPyFloat(inConfig.minv);
	mvPyObject py_max_value = ToPyFloat(inConfig.maxv);

	PyDict_SetItemString(outDict, "format", py_format);
	PyDict_SetItemString(outDict, "speed", py_speed);
	PyDict_SetItemString(outDict, "min_value", py_min_value);
	PyDict_SetItemString(outDict, "max_value", py_max_value);

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		mvPyObject py_result = ToPyBool(flags & flag);
		PyDict_SetItemString(outDict, keyword, py_result);
	};

	// window flags
	checkbitset("clamped", ImGuiSliderFlags_ClampOnInput, inConfig.flags);
	checkbitset("no_input", ImGuiSliderFlags_NoInput, inConfig.flags);
}

void
DearPyGui::fill_configuration_dict(const mvDragIntConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	mvPyObject py_format = ToPyString(inConfig.format);
	mvPyObject py_speed = ToPyFloat(inConfig.speed);
	mvPyObject py_min_value = ToPyInt(inConfig.minv);
	mvPyObject py_max_value = ToPyInt(inConfig.maxv);

	PyDict_SetItemString(outDict, "format", py_format);
	PyDict_SetItemString(outDict, "speed", py_speed);
	PyDict_SetItemString(outDict, "min_value", py_min_value);
	PyDict_SetItemString(outDict, "max_value", py_max_value);

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		mvPyObject py_result = ToPyBool(flags & flag);
		PyDict_SetItemString(outDict, keyword, py_result);
	};

	// window flags
	checkbitset("clamped", ImGuiSliderFlags_ClampOnInput, inConfig.flags);
	checkbitset("no_input", ImGuiSliderFlags_NoInput, inConfig.flags);
}

void
DearPyGui::fill_configuration_dict(const mvDragIntMultiConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	mvPyObject py_format = ToPyString(inConfig.format);
	mvPyObject py_speed = ToPyFloat(inConfig.speed);
	mvPyObject py_min_value = ToPyInt(inConfig.minv);
	mvPyObject py_max_value = ToPyInt(inConfig.maxv);
	mvPyObject py_size = ToPyInt(inConfig.size);

	PyDict_SetItemString(outDict, "format", py_format);
	PyDict_SetItemString(outDict, "speed", py_speed);
	PyDict_SetItemString(outDict, "min_value", py_min_value);
	PyDict_SetItemString(outDict, "max_value", py_max_value);
	PyDict_SetItemString(outDict, "size", py_size);

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		mvPyObject py_result = ToPyBool(flags & flag);
		PyDict_SetItemString(outDict, keyword, py_result);
	};

	// window flags
	checkbitset("clamped", ImGuiSliderFlags_ClampOnInput, inConfig.flags);
	checkbitset("no_input", ImGuiSliderFlags_NoInput, inConfig.flags);
}

void
DearPyGui::fill_configuration_dict(const mvDragFloatMultiConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	mvPyObject py_format = ToPyString(inConfig.format);
	mvPyObject py_speed = ToPyFloat(inConfig.speed);
	mvPyObject py_min_value = ToPyFloat(inConfig.minv);
	mvPyObject py_max_value = ToPyFloat(inConfig.maxv);
	mvPyObject py_size = ToPyInt(inConfig.size);

	PyDict_SetItemString(outDict, "format", py_format);
	PyDict_SetItemString(outDict, "speed", py_speed);
	PyDict_SetItemString(outDict, "min_value", py_min_value);
	PyDict_SetItemString(outDict, "max_value", py_max_value);
	PyDict_SetItemString(outDict, "size", py_size);

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		mvPyObject py_result = ToPyBool(flags & flag);
		PyDict_SetItemString(outDict, keyword, py_result);
	};

	// window flags
	checkbitset("clamped", ImGuiSliderFlags_ClampOnInput, inConfig.flags);
	checkbitset("no_input", ImGuiSliderFlags_NoInput, inConfig.flags);
}

void
DearPyGui::fill_configuration_dict(const mvSliderIntConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	PyDict_SetItemString(outDict, "format", mvPyObject(ToPyString(inConfig.format)));
	PyDict_SetItemString(outDict, "vertical", mvPyObject(ToPyBool(inConfig.vertical)));
	PyDict_SetItemString(outDict, "min_value", mvPyObject(ToPyInt(inConfig.minv)));
	PyDict_SetItemString(outDict, "max_value", mvPyObject(ToPyInt(inConfig.maxv)));

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		PyDict_SetItemString(outDict, keyword, mvPyObject(ToPyBool(flags & flag)));
	};

	// window flags
	checkbitset("clamped", ImGuiSliderFlags_ClampOnInput, inConfig.flags);
	checkbitset("no_input", ImGuiSliderFlags_NoInput, inConfig.flags);
}

void
DearPyGui::fill_configuration_dict(const mvSliderIntMultiConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	PyDict_SetItemString(outDict, "format", mvPyObject(ToPyString(inConfig.format)));
	PyDict_SetItemString(outDict, "min_value", mvPyObject(ToPyInt(inConfig.minv)));
	PyDict_SetItemString(outDict, "max_value", mvPyObject(ToPyInt(inConfig.maxv)));
	PyDict_SetItemString(outDict, "size", mvPyObject(ToPyInt(inConfig.size)));

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		PyDict_SetItemString(outDict, keyword, mvPyObject(ToPyBool(flags & flag)));
	};

	// window flags
	checkbitset("clamped", ImGuiSliderFlags_ClampOnInput, inConfig.flags);
	checkbitset("no_input", ImGuiSliderFlags_NoInput, inConfig.flags);
}

void
DearPyGui::fill_configuration_dict(const mvSliderFloatConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	PyDict_SetItemString(outDict, "format", mvPyObject(ToPyString(inConfig.format)));
	PyDict_SetItemString(outDict, "vertical", mvPyObject(ToPyBool(inConfig.vertical)));
	PyDict_SetItemString(outDict, "min_value", mvPyObject(ToPyFloat(inConfig.minv)));
	PyDict_SetItemString(outDict, "max_value", mvPyObject(ToPyFloat(inConfig.maxv)));

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		PyDict_SetItemString(outDict, keyword, mvPyObject(ToPyBool(flags & flag)));
	};

	// window flags
	checkbitset("clamped", ImGuiSliderFlags_ClampOnInput, inConfig.flags);
	checkbitset("no_input", ImGuiSliderFlags_NoInput, inConfig.flags);
}

void
DearPyGui::fill_configuration_dict(const mvSliderFloatMultiConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	PyDict_SetItemString(outDict, "format", mvPyObject(ToPyString(inConfig.format)));
	PyDict_SetItemString(outDict, "min_value", mvPyObject(ToPyFloat(inConfig.minv)));
	PyDict_SetItemString(outDict, "max_value", mvPyObject(ToPyFloat(inConfig.maxv)));
	PyDict_SetItemString(outDict, "size", mvPyObject(ToPyInt(inConfig.size)));

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		PyDict_SetItemString(outDict, keyword, mvPyObject(ToPyBool(flags & flag)));
	};

	// window flags
	checkbitset("clamped", ImGuiSliderFlags_ClampOnInput, inConfig.flags);
	checkbitset("no_input", ImGuiSliderFlags_NoInput, inConfig.flags);
}

void
DearPyGui::fill_configuration_dict(const mvListboxConfig& inConfig, PyObject* outDict)
{
    if (outDict == nullptr)
        return;
    PyDict_SetItemString(outDict, "items", mvPyObject(ToPyList(inConfig.names)));
    PyDict_SetItemString(outDict, "num_items", mvPyObject(ToPyInt(inConfig.itemsHeight)));
}

void
DearPyGui::fill_configuration_dict(const mvRadioButtonConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	PyDict_SetItemString(outDict, "items", mvPyObject(ToPyList(inConfig.itemnames)));
	PyDict_SetItemString(outDict, "horizontal", mvPyObject(ToPyBool(inConfig.horizontal)));
}

void
DearPyGui::fill_configuration_dict(const mvInputTextConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	PyDict_SetItemString(outDict, "hint", mvPyObject(ToPyString(inConfig.hint)));
	PyDict_SetItemString(outDict, "multline", mvPyObject(ToPyBool(inConfig.multiline)));

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		PyDict_SetItemString(outDict, keyword, mvPyObject(ToPyBool(flags & flag)));
	};

	// window flags
	checkbitset("no_spaces", ImGuiInputTextFlags_CharsNoBlank, inConfig.flags);
	checkbitset("uppercase", ImGuiInputTextFlags_CharsUppercase, inConfig.flags);
	checkbitset("decimal", ImGuiInputTextFlags_CharsDecimal, inConfig.flags);
	checkbitset("hexadecimal", ImGuiInputTextFlags_CharsHexadecimal, inConfig.flags);
	checkbitset("readonly", ImGuiInputTextFlags_ReadOnly, inConfig.flags);
	checkbitset("password", ImGuiInputTextFlags_Password, inConfig.flags);
	checkbitset("on_enter", ImGuiInputTextFlags_EnterReturnsTrue, inConfig.flags);
	checkbitset("scientific", ImGuiInputTextFlags_CharsScientific, inConfig.flags);
	checkbitset("tab_input", ImGuiInputTextFlags_AllowTabInput, inConfig.flags);
}

void
DearPyGui::fill_configuration_dict(const mvInputIntConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	PyDict_SetItemString(outDict, "on_enter", mvPyObject(ToPyBool(inConfig.flags & ImGuiInputTextFlags_EnterReturnsTrue)));
	PyDict_SetItemString(outDict, "readonly", mvPyObject(ToPyBool(inConfig.flags & ImGuiInputTextFlags_ReadOnly)));
	PyDict_SetItemString(outDict, "step", mvPyObject(ToPyInt(inConfig.step)));
	PyDict_SetItemString(outDict, "step_fast", mvPyObject(ToPyInt(inConfig.step_fast)));
	PyDict_SetItemString(outDict, "min_value", mvPyObject(ToPyInt(inConfig.minv)));
	PyDict_SetItemString(outDict, "max_value", mvPyObject(ToPyInt(inConfig.maxv)));
	PyDict_SetItemString(outDict, "min_clamped", mvPyObject(ToPyBool(inConfig.min_clamped)));
	PyDict_SetItemString(outDict, "max_clamped", mvPyObject(ToPyBool(inConfig.max_clamped)));
}

void
DearPyGui::fill_configuration_dict(const mvInputFloatConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	PyDict_SetItemString(outDict, "format", mvPyObject(ToPyString(inConfig.format)));
	PyDict_SetItemString(outDict, "step", mvPyObject(ToPyFloat(inConfig.step)));
	PyDict_SetItemString(outDict, "step_fast", mvPyObject(ToPyFloat(inConfig.step_fast)));
	PyDict_SetItemString(outDict, "min_value", mvPyObject(ToPyFloat(inConfig.minv)));
	PyDict_SetItemString(outDict, "max_value", mvPyObject(ToPyFloat(inConfig.maxv)));
	PyDict_SetItemString(outDict, "min_clamped", mvPyObject(ToPyBool(inConfig.min_clamped)));
	PyDict_SetItemString(outDict, "max_clamped", mvPyObject(ToPyBool(inConfig.max_clamped)));

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		PyDict_SetItemString(outDict, keyword, mvPyObject(ToPyBool(flags & flag)));
	};

	// window flags
	checkbitset("on_enter", ImGuiInputTextFlags_EnterReturnsTrue, inConfig.flags);
	checkbitset("readonly", ImGuiInputTextFlags_ReadOnly, inConfig.flags);
}

void
DearPyGui::fill_configuration_dict(const mvInputFloatMultiConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	PyDict_SetItemString(outDict, "format", mvPyObject(ToPyString(inConfig.format)));
	PyDict_SetItemString(outDict, "min_value", mvPyObject(ToPyFloat(inConfig.minv)));
	PyDict_SetItemString(outDict, "max_value", mvPyObject(ToPyFloat(inConfig.maxv)));
	PyDict_SetItemString(outDict, "min_clamped", mvPyObject(ToPyBool(inConfig.min_clamped)));
	PyDict_SetItemString(outDict, "max_clamped", mvPyObject(ToPyBool(inConfig.max_clamped)));
	PyDict_SetItemString(outDict, "size", mvPyObject(ToPyInt(inConfig.size)));

	// helper to check and set bit
	auto checkbitset = [outDict](const char* keyword, int flag, const int& flags)
	{
		PyDict_SetItemString(outDict, keyword, mvPyObject(ToPyBool(flags & flag)));
	};

	// window flags
	checkbitset("on_enter", ImGuiInputTextFlags_EnterReturnsTrue, inConfig.flags);
	checkbitset("readonly", ImGuiInputTextFlags_ReadOnly, inConfig.flags);
}

void
DearPyGui::fill_configuration_dict(const mvInputIntMultiConfig& inConfig, PyObject* outDict)
{
	if (outDict == nullptr)
		return;

	PyDict_SetItemString(outDict, "on_enter", mvPyObject(ToPyBool(inConfig.flags & ImGuiInputTextFlags_EnterReturnsTrue)));
	PyDict_SetItemString(outDict, "readonly", mvPyObject(ToPyBool(inConfig.flags & ImGuiInputTextFlags_ReadOnly)));
	PyDict_SetItemString(outDict, "min_value", mvPyObject(ToPyInt(inConfig.minv)));
	PyDict_SetItemString(outDict, "max_value", mvPyObject(ToPyInt(inConfig.maxv)));
	PyDict_SetItemString(outDict, "min_clamped", mvPyObject(ToPyBool(inConfig.min_clamped)));
	PyDict_SetItemString(outDict, "max_clamped", mvPyObject(ToPyBool(inConfig.max_clamped)));
	PyDict_SetItemString(outDict, "size", mvPyObject(ToPyInt(inConfig.size)));
}

//-----------------------------------------------------------------------------
// [SECTION] configure_item(...) specifics
//-----------------------------------------------------------------------------

void
DearPyGui::set_configuration(PyObject* inDict, mvButtonConfig& outConfig)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "small")) outConfig.small_button = ToBool(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "arrow")) outConfig.arrow = ToBool(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "direction")) outConfig.direction = ToInt(item);
}

void
DearPyGui::set_configuration(PyObject* inDict, mvComboConfig& outConfig)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "items")) outConfig.items = ToStringVect(item);

	if (PyObject* item = PyDict_GetItemString(inDict, "height_mode"))
	{
		long height_mode = (long)ToUUID(item);
		if (height_mode == (long)mvComboHeightMode::mvComboHeight_Small) outConfig.flags = ImGuiComboFlags_HeightSmall;
		else if (height_mode == (long)mvComboHeightMode::mvComboHeight_Regular) outConfig.flags = ImGuiComboFlags_HeightRegular;
		else if (height_mode == (long)mvComboHeightMode::mvComboHeight_Large) outConfig.flags = ImGuiComboFlags_HeightLarge;
		else outConfig.flags = ImGuiComboFlags_HeightLargest;
	}

	// helpers for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{ if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;};

	flagop("popup_align_left", ImGuiComboFlags_PopupAlignLeft, outConfig.flags);
	flagop("no_arrow_button", ImGuiComboFlags_NoArrowButton, outConfig.flags);
	flagop("no_preview", ImGuiComboFlags_NoPreview, outConfig.flags);
}

void
DearPyGui::set_configuration(PyObject* inDict, mvDragFloatConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "format")) outConfig.format = ToString(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "speed")) outConfig.speed = ToFloat(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "min_value")) outConfig.minv = ToFloat(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_value")) outConfig.maxv = ToFloat(item);

	// helper for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{
		if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
	};

	// flags
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.flags);
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.stor_flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.stor_flags);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiSliderFlags_NoInput;
	}
}

void
DearPyGui::set_configuration(PyObject* inDict, mvDragIntConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "format")) outConfig.format = ToString(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "speed")) outConfig.speed = ToFloat(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "min_value")) outConfig.minv = ToInt(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_value")) outConfig.maxv = ToInt(item);

	// helper for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{
		if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
	};

	// flags
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.flags);
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.stor_flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.stor_flags);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiSliderFlags_NoInput;
	}
}

void
DearPyGui::set_configuration(PyObject* inDict, mvDragIntMultiConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "format")) outConfig.format = ToString(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "speed")) outConfig.speed = ToFloat(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "min_value")) outConfig.minv = ToInt(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_value")) outConfig.maxv = ToInt(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "size")) outConfig.size = ToInt(item);

	// helper for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{
		if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
	};

	// flags
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.flags);
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.stor_flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.stor_flags);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiSliderFlags_NoInput;
	}
}

void
DearPyGui::set_configuration(PyObject* inDict, mvDragFloatMultiConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "format")) outConfig.format = ToString(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "speed")) outConfig.speed = ToFloat(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "min_value")) outConfig.minv = ToFloat(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_value")) outConfig.maxv = ToFloat(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "size")) outConfig.size = ToInt(item);

	// helper for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{
		if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
	};

	// flags
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.flags);
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.stor_flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.stor_flags);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiSliderFlags_NoInput;
	}
}

void
DearPyGui::set_configuration(PyObject* inDict, mvSliderIntConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "format")) outConfig.format = ToString(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "vertical")) outConfig.vertical = ToBool(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "min_value")) outConfig.minv = ToInt(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_value")) outConfig.maxv = ToInt(item);

	// helper for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{
		if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
	};

	// flags
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.flags);
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.stor_flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.stor_flags);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiSliderFlags_NoInput;
	}
}

void
DearPyGui::set_configuration(PyObject* inDict, mvSliderIntMultiConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "format"))    outConfig.format = ToString(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "min_value")) outConfig.minv = ToInt(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_value")) outConfig.maxv = ToInt(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "size"))      outConfig.size = ToInt(item);

	// helper for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{
		if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
	};

	// flags
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.flags);
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.stor_flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.stor_flags);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiSliderFlags_NoInput;
	}
}

void
DearPyGui::set_configuration(PyObject* inDict, mvSliderFloatConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "format")) outConfig.format = ToString(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "vertical")) outConfig.vertical = ToBool(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "min_value")) outConfig.minv = ToFloat(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_value")) outConfig.maxv = ToFloat(item);

	// helper for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{
		if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
	};

	// flags
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.flags);
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.stor_flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.stor_flags);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiSliderFlags_NoInput;
	}
}

void
DearPyGui::set_configuration(PyObject* inDict, mvSliderFloatMultiConfig& outConfig, mvAppItemInfo& info)
{

	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "format"))    outConfig.format = ToString(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "min_value")) outConfig.minv = ToFloat(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_value")) outConfig.maxv = ToFloat(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "size"))      outConfig.size = ToInt(item);

	// helper for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{
		if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
	};

	// flags
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.flags);
	flagop("clamped", ImGuiSliderFlags_ClampOnInput, outConfig.stor_flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.flags);
	flagop("no_input", ImGuiSliderFlags_NoInput, outConfig.stor_flags);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiSliderFlags_NoInput;
	}

}

void
DearPyGui::set_configuration(PyObject* inDict, mvListboxConfig& outConfig, mvAppItemInfo& info)
{
    if (inDict == nullptr)
        return;

    if (PyObject* item = PyDict_GetItemString(inDict, "num_items")) outConfig.itemsHeight = ToInt(item);
    if (PyObject* item = PyDict_GetItemString(inDict, "items"))
    {
        outConfig.names = ToStringVect(item);
        outConfig.charNames.clear();
        for (const std::string& name : outConfig.names)
            outConfig.charNames.emplace_back(name.c_str());

        outConfig.index = 0;
        outConfig.disabledindex = 0;

        int index = 0;
        for (const auto& name : outConfig.names)
        {
            if (name == *outConfig.value)
            {
                outConfig.index = index;
                outConfig.disabledindex = index;
                break;
            }
            index++;
        }
    }

    if(outConfig.value->empty())
    {
        if(!outConfig.names.empty())
            *outConfig.value = outConfig.names[0];
    }
}

void
DearPyGui::set_configuration(PyObject* inDict, mvRadioButtonConfig& outConfig)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "items"))
	{
		outConfig.itemnames = ToStringVect(item);

		// update index
		outConfig.index = 0;
		outConfig.disabledindex = 0;

		int index = 0;
		for (const auto& name : outConfig.itemnames)
		{
			if (name == *outConfig.value)
			{
				outConfig.index = index;
				outConfig.disabledindex = index;
				break;
			}
			index++;
		}

	}
	if (PyObject* item = PyDict_GetItemString(inDict, "horizontal")) outConfig.horizontal = ToBool(item);
}

void
DearPyGui::set_configuration(PyObject* inDict, mvInputTextConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "hint")) outConfig.hint = ToString(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "multiline")) outConfig.multiline = ToBool(item);

	// helper for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{
		if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
	};

	// flags
	flagop("no_spaces", ImGuiInputTextFlags_CharsNoBlank, outConfig.flags);
	flagop("uppercase", ImGuiInputTextFlags_CharsUppercase, outConfig.flags);
	flagop("decimal", ImGuiInputTextFlags_CharsDecimal, outConfig.flags);
	flagop("hexadecimal", ImGuiInputTextFlags_CharsHexadecimal, outConfig.flags);
	flagop("readonly", ImGuiInputTextFlags_ReadOnly, outConfig.flags);
	flagop("password", ImGuiInputTextFlags_Password, outConfig.flags);
	flagop("on_enter", ImGuiInputTextFlags_EnterReturnsTrue, outConfig.flags);
	flagop("scientific", ImGuiInputTextFlags_CharsScientific, outConfig.flags);
	flagop("tab_input", ImGuiInputTextFlags_AllowTabInput, outConfig.flags);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiInputTextFlags_ReadOnly;
		outConfig.flags &= ~ImGuiInputTextFlags_EnterReturnsTrue;
	}
}

void
DearPyGui::set_configuration(PyObject* inDict, mvInputIntConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "on_enter")) ToBool(item) ? outConfig.flags |= ImGuiInputTextFlags_EnterReturnsTrue : outConfig.flags &= ~ImGuiInputTextFlags_EnterReturnsTrue;
	if (PyObject* item = PyDict_GetItemString(inDict, "on_enter")) ToBool(item) ? outConfig.stor_flags |= ImGuiInputTextFlags_EnterReturnsTrue : outConfig.stor_flags &= ~ImGuiInputTextFlags_EnterReturnsTrue;
	if (PyObject* item = PyDict_GetItemString(inDict, "readonly")) ToBool(item) ? outConfig.flags |= ImGuiInputTextFlags_ReadOnly : outConfig.flags &= ~ImGuiInputTextFlags_ReadOnly;
	if (PyObject* item = PyDict_GetItemString(inDict, "readonly")) ToBool(item) ? outConfig.stor_flags |= ImGuiInputTextFlags_ReadOnly : outConfig.stor_flags &= ~ImGuiInputTextFlags_ReadOnly;
	if (PyObject* item = PyDict_GetItemString(inDict, "step")) outConfig.step = ToInt(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "step_fast")) outConfig.step_fast = ToInt(item);

	if (PyObject* item = PyDict_GetItemString(inDict, "min_value"))
	{
		outConfig.minv = ToInt(item);
		outConfig.min_clamped = true;
	}

	if (PyObject* item = PyDict_GetItemString(inDict, "max_value"))
	{
		outConfig.maxv = ToInt(item);
		outConfig.max_clamped = true;
	}

	if (PyObject* item = PyDict_GetItemString(inDict, "min_clamped")) outConfig.min_clamped = ToBool(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_clamped")) outConfig.max_clamped = ToBool(item);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiInputTextFlags_ReadOnly;
		outConfig.flags &= ~ImGuiInputTextFlags_EnterReturnsTrue;
	}
}

void
DearPyGui::set_configuration(PyObject* inDict, mvInputFloatConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "format")) outConfig.format = ToString(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "step")) outConfig.step = ToFloat(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "step_fast")) outConfig.step_fast = ToFloat(item);


	if (PyObject* item = PyDict_GetItemString(inDict, "min_value"))
	{
		outConfig.minv = ToFloat(item);
		outConfig.min_clamped = true;
	}

	if (PyObject* item = PyDict_GetItemString(inDict, "max_value"))
	{
		outConfig.maxv = ToFloat(item);
		outConfig.max_clamped = true;
	}


	if (PyObject* item = PyDict_GetItemString(inDict, "min_clamped")) outConfig.min_clamped = ToBool(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_clamped")) outConfig.max_clamped = ToBool(item);

	// helper for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{
		if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
	};

	// flags
	flagop("on_enter", ImGuiInputTextFlags_EnterReturnsTrue, outConfig.flags);
	flagop("on_enter", ImGuiInputTextFlags_EnterReturnsTrue, outConfig.stor_flags);
	flagop("readonly", ImGuiInputTextFlags_ReadOnly, outConfig.flags);
	flagop("readonly", ImGuiInputTextFlags_ReadOnly, outConfig.stor_flags);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiInputTextFlags_ReadOnly;
		outConfig.flags &= ~ImGuiInputTextFlags_EnterReturnsTrue;
	}
}

void
DearPyGui::set_configuration(PyObject* inDict, mvInputFloatMultiConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "format")) outConfig.format = ToString(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "size")) outConfig.size = ToInt(item);

	if (PyObject* item = PyDict_GetItemString(inDict, "min_value"))
	{
		outConfig.minv = ToFloat(item);
		outConfig.min_clamped = true;
	}

	if (PyObject* item = PyDict_GetItemString(inDict, "max_value"))
	{
		outConfig.maxv = ToFloat(item);
		outConfig.max_clamped = true;
	}

	if (PyObject* item = PyDict_GetItemString(inDict, "min_clamped")) outConfig.min_clamped = ToBool(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_clamped")) outConfig.max_clamped = ToBool(item);

	// helper for bit flipping
	auto flagop = [inDict](const char* keyword, int flag, int& flags)
	{
		if (PyObject* item = PyDict_GetItemString(inDict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
	};

	// flags
	flagop("on_enter", ImGuiInputTextFlags_EnterReturnsTrue, outConfig.flags);
	flagop("on_enter", ImGuiInputTextFlags_EnterReturnsTrue, outConfig.stor_flags);
	flagop("readonly", ImGuiInputTextFlags_ReadOnly, outConfig.flags);
	flagop("readonly", ImGuiInputTextFlags_ReadOnly, outConfig.stor_flags);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiInputTextFlags_ReadOnly;
		outConfig.flags &= ~ImGuiInputTextFlags_EnterReturnsTrue;
	}
}

void
DearPyGui::set_configuration(PyObject* inDict, mvInputIntMultiConfig& outConfig, mvAppItemInfo& info)
{
	if (inDict == nullptr)
		return;

	if (PyObject* item = PyDict_GetItemString(inDict, "on_enter")) ToBool(item) ? outConfig.flags |= ImGuiInputTextFlags_EnterReturnsTrue : outConfig.flags &= ~ImGuiInputTextFlags_EnterReturnsTrue;
	if (PyObject* item = PyDict_GetItemString(inDict, "on_enter")) ToBool(item) ? outConfig.stor_flags |= ImGuiInputTextFlags_EnterReturnsTrue : outConfig.stor_flags &= ~ImGuiInputTextFlags_EnterReturnsTrue;
	if (PyObject* item = PyDict_GetItemString(inDict, "readonly")) ToBool(item) ? outConfig.flags |= ImGuiInputTextFlags_ReadOnly : outConfig.flags &= ~ImGuiInputTextFlags_ReadOnly;
	if (PyObject* item = PyDict_GetItemString(inDict, "readonly")) ToBool(item) ? outConfig.stor_flags |= ImGuiInputTextFlags_ReadOnly : outConfig.stor_flags &= ~ImGuiInputTextFlags_ReadOnly;
	if (PyObject* item = PyDict_GetItemString(inDict, "size")) outConfig.size = ToInt(item);

	if (PyObject* item = PyDict_GetItemString(inDict, "min_value"))
	{
		outConfig.minv = ToInt(item);
		outConfig.min_clamped = true;
	}

	if (PyObject* item = PyDict_GetItemString(inDict, "max_value"))
	{
		outConfig.maxv = ToInt(item);
		outConfig.max_clamped = true;
	}

	if (PyObject* item = PyDict_GetItemString(inDict, "min_clamped")) outConfig.min_clamped = ToBool(item);
	if (PyObject* item = PyDict_GetItemString(inDict, "max_clamped")) outConfig.max_clamped = ToBool(item);

	if (info.enabledLastFrame)
	{
		info.enabledLastFrame = false;
		outConfig.flags = outConfig.stor_flags;
	}

	if (info.disabledLastFrame)
	{
		info.disabledLastFrame = false;
		outConfig.stor_flags = outConfig.flags;
		outConfig.flags |= ImGuiInputTextFlags_ReadOnly;
		outConfig.flags &= ~ImGuiInputTextFlags_EnterReturnsTrue;
	}
}

//-----------------------------------------------------------------------------
// [SECTION] positional args specifics
//-----------------------------------------------------------------------------

void
DearPyGui::set_positional_configuration(PyObject* inDict, mvComboConfig& outConfig)
{
	if (!VerifyPositionalArguments(GetParsers()[GetEntityCommand(mvAppItemType::mvCombo)], inDict))
		return;

	for (int i = 0; i < PyTuple_Size(inDict); i++)
	{
		PyObject* item = PyTuple_GetItem(inDict, i);
		switch (i)
		{
		case 0:
			outConfig.items = ToStringVect(item);
			break;

		default:
			break;
		}
	}
}

void
DearPyGui::set_positional_configuration(PyObject* inDict, mvListboxConfig& outConfig)
{
    if (!VerifyPositionalArguments(GetParsers()[GetEntityCommand(mvAppItemType::mvListbox)], inDict))
        return;
    for (int i = 0; i < PyTuple_Size(inDict); i++)
    {
        switch (i)
        {
            case 0:
                outConfig.names = ToStringVect(PyTuple_GetItem(inDict, 0));
                outConfig.charNames.clear();
                for (const std::string& item : outConfig.names)
                    outConfig.charNames.emplace_back(item.c_str());
                break;
            default:
                break;
        }
    }
}

void
DearPyGui::set_positional_configuration(PyObject* inDict, mvRadioButtonConfig& outConfig)
{
	if (!VerifyPositionalArguments(GetParsers()[GetEntityCommand(mvAppItemType::mvRadioButton)], inDict))
		return;

	for (int i = 0; i < PyTuple_Size(inDict); i++)
	{
		PyObject* item = PyTuple_GetItem(inDict, i);
		switch (i)
		{
		case 0:
			outConfig.itemnames = ToStringVect(item);
			break;

		default:
			break;
		}
	}
}

//-----------------------------------------------------------------------------
// [SECTION] data sources
//-----------------------------------------------------------------------------

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvComboConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<std::string>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvCheckboxConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<bool>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvDragFloatConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* scrItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!scrItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(scrItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<float>*>(scrItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvDragIntConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<int>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvDragIntMultiConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<std::array<int, 4>>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvDragFloatMultiConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<std::array<float, 4>>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvSliderFloatConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<float>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvSliderFloatMultiConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<std::array<float, 4>>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvSliderIntConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<int>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvSliderIntMultiConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<std::array<int, 4>>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvListboxConfig& outConfig)
{
    if (dataSource == item.config.source) return;
    item.config.source = dataSource;

    mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
    if (!srcItem)
    {
        mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
                           "Source item not found: " + std::to_string(dataSource), &item);
        return;
    }
    if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
    {
        mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
                           "Values types do not match: " + std::to_string(dataSource), &item);
        return;
    }
    outConfig.value = *static_cast<std::shared_ptr<std::string>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvRadioButtonConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<std::string>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvInputTextConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<std::string>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvInputIntConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<int>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvInputFloatConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<float>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvInputFloatMultiConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<std::array<float, 4>>*>(srcItem->getValue());
}

void
DearPyGui::set_data_source(mvAppItem& item, mvUUID dataSource, mvInputIntMultiConfig& outConfig)
{
	if (dataSource == item.config.source) return;
	item.config.source = dataSource;

	mvAppItem* srcItem = GetItem((*GContext->itemRegistry), dataSource);
	if (!srcItem)
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotFound, "set_value",
			"Source item not found: " + std::to_string(dataSource), &item);
		return;
	}
	if (DearPyGui::GetEntityValueType(srcItem->type) != DearPyGui::GetEntityValueType(item.type))
	{
		mvThrowPythonError(mvErrorCode::mvSourceNotCompatible, "set_value",
			"Values types do not match: " + std::to_string(dataSource), &item);
		return;
	}
	outConfig.value = *static_cast<std::shared_ptr<std::array<int, 4>>*>(srcItem->getValue());
}


//-----------------------------------------------------------------------------
// [SECTION] template specifics
//-----------------------------------------------------------------------------

void
DearPyGui::apply_template(const mvButtonConfig& sourceConfig, mvButtonConfig& dstConfig)
{
	dstConfig.direction = sourceConfig.direction;
	dstConfig.small_button = sourceConfig.small_button;
	dstConfig.arrow = sourceConfig.arrow;
}

void
DearPyGui::apply_template(const mvComboConfig& sourceConfig, mvComboConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value = sourceConfig.disabled_value;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.items = sourceConfig.items;
	dstConfig.popup_align_left = sourceConfig.popup_align_left;
	dstConfig.no_preview = sourceConfig.no_preview;
}

void
DearPyGui::apply_template(const mvCheckboxConfig& sourceConfig, mvCheckboxConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value = sourceConfig.disabled_value;
}

void
DearPyGui::apply_template(const mvDragFloatConfig& sourceConfig, mvDragFloatConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value = sourceConfig.disabled_value;
	dstConfig.speed = sourceConfig.speed;
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.format = sourceConfig.format;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
}

void
DearPyGui::apply_template(const mvDragIntConfig& sourceConfig, mvDragIntConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value = sourceConfig.disabled_value;
	dstConfig.speed = sourceConfig.speed;
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.format = sourceConfig.format;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
}

void
DearPyGui::apply_template(const mvDragIntMultiConfig& sourceConfig, mvDragIntMultiConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value[0] = sourceConfig.disabled_value[0];
	dstConfig.disabled_value[1] = sourceConfig.disabled_value[1];
	dstConfig.disabled_value[2] = sourceConfig.disabled_value[2];
	dstConfig.disabled_value[3] = sourceConfig.disabled_value[3];
	dstConfig.speed = sourceConfig.speed;
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.format = sourceConfig.format;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
	dstConfig.size = sourceConfig.size;
}

void
DearPyGui::apply_template(const mvDragFloatMultiConfig& sourceConfig, mvDragFloatMultiConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value[0] = sourceConfig.disabled_value[0];
	dstConfig.disabled_value[1] = sourceConfig.disabled_value[1];
	dstConfig.disabled_value[2] = sourceConfig.disabled_value[2];
	dstConfig.disabled_value[3] = sourceConfig.disabled_value[3];
	dstConfig.speed = sourceConfig.speed;
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.format = sourceConfig.format;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
	dstConfig.size = sourceConfig.size;
}

void
DearPyGui::apply_template(const mvSliderFloatConfig& sourceConfig, mvSliderFloatConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value = sourceConfig.disabled_value;
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.format = sourceConfig.format;
	dstConfig.vertical = sourceConfig.vertical;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
}

void
DearPyGui::apply_template(const mvSliderFloatMultiConfig& sourceConfig, mvSliderFloatMultiConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value[0] = sourceConfig.disabled_value[0];
	dstConfig.disabled_value[1] = sourceConfig.disabled_value[1];
	dstConfig.disabled_value[2] = sourceConfig.disabled_value[2];
	dstConfig.disabled_value[3] = sourceConfig.disabled_value[3];
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.format = sourceConfig.format;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
	dstConfig.size = sourceConfig.size;
}

void
DearPyGui::apply_template(const mvSliderIntConfig& sourceConfig, mvSliderIntConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value = sourceConfig.disabled_value;
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.format = sourceConfig.format;
	dstConfig.vertical = sourceConfig.vertical;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
}

void
DearPyGui::apply_template(const mvSliderIntMultiConfig& sourceConfig, mvSliderIntMultiConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value[0] = sourceConfig.disabled_value[0];
	dstConfig.disabled_value[1] = sourceConfig.disabled_value[1];
	dstConfig.disabled_value[2] = sourceConfig.disabled_value[2];
	dstConfig.disabled_value[3] = sourceConfig.disabled_value[3];
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.format = sourceConfig.format;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
	dstConfig.size = sourceConfig.size;
}

void
DearPyGui::apply_template(const mvListboxConfig& sourceConfig, mvListboxConfig& dstConfig)
{
    dstConfig.value = sourceConfig.value;
    dstConfig.disabled_value = sourceConfig.disabled_value;
    dstConfig.names = sourceConfig.names;
    dstConfig.itemsHeight = sourceConfig.itemsHeight;
    dstConfig.charNames = sourceConfig.charNames;
    dstConfig.index = sourceConfig.index;
    dstConfig.disabledindex = sourceConfig.disabledindex;
}

void
DearPyGui::apply_template(const mvRadioButtonConfig& sourceConfig, mvRadioButtonConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value = sourceConfig.disabled_value;
	dstConfig.itemnames = sourceConfig.itemnames;
	dstConfig.horizontal = sourceConfig.horizontal;
	dstConfig.index = sourceConfig.index;
	dstConfig.disabledindex = sourceConfig.disabledindex;
}

void
DearPyGui::apply_template(const mvInputTextConfig& sourceConfig, mvInputTextConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value = sourceConfig.disabled_value;
	dstConfig.hint = sourceConfig.hint;
	dstConfig.multiline = sourceConfig.multiline;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
}

void
DearPyGui::apply_template(const mvInputIntConfig& sourceConfig, mvInputIntConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value = sourceConfig.disabled_value;
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.min_clamped = sourceConfig.min_clamped;
	dstConfig.max_clamped = sourceConfig.max_clamped;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
	dstConfig.last_value = sourceConfig.last_value;
	dstConfig.step = sourceConfig.step;
	dstConfig.step_fast = sourceConfig.step_fast;
}

void
DearPyGui::apply_template(const mvInputFloatConfig& sourceConfig, mvInputFloatConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value = sourceConfig.disabled_value;
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.min_clamped = sourceConfig.min_clamped;
	dstConfig.max_clamped = sourceConfig.max_clamped;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.format = sourceConfig.format;
	dstConfig.stor_flags = sourceConfig.stor_flags;
	dstConfig.last_value = sourceConfig.last_value;
	dstConfig.step = sourceConfig.step;
	dstConfig.step_fast = sourceConfig.step_fast;
}

void
DearPyGui::apply_template(const mvInputFloatMultiConfig& sourceConfig, mvInputFloatMultiConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value[0] = sourceConfig.disabled_value[0];
	dstConfig.disabled_value[1] = sourceConfig.disabled_value[1];
	dstConfig.disabled_value[2] = sourceConfig.disabled_value[2];
	dstConfig.disabled_value[3] = sourceConfig.disabled_value[3];
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.min_clamped = sourceConfig.min_clamped;
	dstConfig.max_clamped = sourceConfig.max_clamped;
	dstConfig.format = sourceConfig.format;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
	dstConfig.last_value = sourceConfig.last_value;
	dstConfig.size = sourceConfig.size;
}

void
DearPyGui::apply_template(const mvInputIntMultiConfig& sourceConfig, mvInputIntMultiConfig& dstConfig)
{
	dstConfig.value = sourceConfig.value;
	dstConfig.disabled_value[0] = sourceConfig.disabled_value[0];
	dstConfig.disabled_value[1] = sourceConfig.disabled_value[1];
	dstConfig.disabled_value[2] = sourceConfig.disabled_value[2];
	dstConfig.disabled_value[3] = sourceConfig.disabled_value[3];
	dstConfig.minv = sourceConfig.minv;
	dstConfig.maxv = sourceConfig.maxv;
	dstConfig.min_clamped = sourceConfig.min_clamped;
	dstConfig.max_clamped = sourceConfig.max_clamped;
	dstConfig.flags = sourceConfig.flags;
	dstConfig.stor_flags = sourceConfig.stor_flags;
	dstConfig.last_value = sourceConfig.last_value;
	dstConfig.size = sourceConfig.size;
}

//-----------------------------------------------------------------------------
// [SECTION] draw commands
//-----------------------------------------------------------------------------

void
DearPyGui::draw_button(ImDrawList* drawlist, mvAppItem& item, const mvButtonConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{
		// push imgui id to prevent name collisions
		ScopedID id(item.uuid);

		bool activated = false;

		if (config.small_button)
			activated = ImGui::SmallButton(item.info.internalLabel.c_str());

		else if (config.arrow)
			activated = ImGui::ArrowButton(item.info.internalLabel.c_str(), config.direction);

		else
			activated = ImGui::Button(item.info.internalLabel.c_str(), ImVec2((float)item.config.width, (float)item.config.height));

		if (activated)
		{
			if (item.config.alias.empty())
				mvAddCallback(item.getCallback(false), item.uuid, nullptr, item.config.user_data);
			else
				mvAddCallback(item.getCallback(false), item.config.alias, nullptr, item.config.user_data);
		}
	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_combo(ImDrawList* drawlist, mvAppItem& item, mvComboConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{
		ScopedID id(item.uuid);

		static std::vector<std::string> disabled_items{};

		// The second parameter is the label previewed before opening the combo.
		bool activated = ImGui::BeginCombo(item.info.internalLabel.c_str(), config.value->c_str(), config.flags);
		UpdateAppItemState(item.state);

		if (activated)
		{

			for (const auto& name : item.config.enabled ? config.items : disabled_items)
			{
				bool is_selected = (*config.value == name);
				if (ImGui::Selectable((name).c_str(), is_selected))
				{
					if (item.config.enabled) { *config.value = name; }

					auto value = *config.value;

					if (item.config.alias.empty())
						mvSubmitCallback([&item, value]() {mvAddCallback(item.getCallback(false), item.uuid, ToPyString(value), item.config.user_data);});
					else
						mvSubmitCallback([&item, value]() { mvAddCallback(item.getCallback(false), item.config.alias, ToPyString(value), item.config.user_data);});
				}

				item.state.edited = ImGui::IsItemEdited();
				item.state.deactivated = ImGui::IsItemDeactivated();
				item.state.deactivatedAfterEdit = ImGui::IsItemDeactivatedAfterEdit();

				// Set the initial focus when opening the combo (scrolling + for keyboard navigation support in the upcoming navigation branch)
				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}

			ImGui::EndCombo();
		}
	}

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_checkbox(ImDrawList* drawlist, mvAppItem& item, mvCheckboxConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{
		// push imgui id to prevent name collisions
		ScopedID id(item.uuid);

		if (!item.config.enabled) config.disabled_value = *config.value;

		if (ImGui::Checkbox(item.info.internalLabel.c_str(), item.config.enabled ? config.value.get() : &config.disabled_value))
		{
			bool value = *config.value;

			if (item.config.alias.empty())
				mvSubmitCallback([&item, value]() { mvAddCallback(item.getCallback(false), item.uuid, ToPyBool(value), item.config.user_data);});
			else
				mvSubmitCallback([&item, value]() { mvAddCallback(item.getCallback(false), item.config.alias, ToPyBool(value), item.config.user_data);});
		}
	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_drag_float(ImDrawList* drawlist, mvAppItem& item, mvDragFloatConfig& config)
{
	ScopedID id(item.uuid);

	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{

		if (!item.config.enabled) config.disabled_value = *config.value;

		if (ImGui::DragFloat(item.info.internalLabel.c_str(), 
			item.config.enabled ? config.value.get() : &config.disabled_value, 
			config.speed, config.minv, config.maxv, config.format.c_str(), config.flags))
		{
			auto value = *config.value;

			if (item.config.alias.empty())
				mvSubmitCallback([&item, value]() {mvAddCallback(item.getCallback(false), item.uuid, ToPyFloat(value), item.config.user_data);});
			else
				mvSubmitCallback([&item, value]() { mvAddCallback(item.getCallback(false), item.config.alias, ToPyFloat(value), item.config.user_data);});
		}
	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_drag_int(ImDrawList* drawlist, mvAppItem& item, mvDragIntConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{

		ScopedID id(item.uuid);

		if (!item.config.enabled) config.disabled_value = *config.value;

		if (ImGui::DragInt(item.info.internalLabel.c_str(), 
			item.config.enabled ? config.value.get() : &config.disabled_value, config.speed,
			config.minv, config.maxv, config.format.c_str(), config.flags))
		{
			auto value = *config.value;
			if (item.config.alias.empty())
				mvSubmitCallback([&item, value]() {
				mvAddCallback(item.getCallback(false), item.uuid, ToPyInt(value), item.config.user_data);
					});
			else
				mvSubmitCallback([&item, value]() {
				mvAddCallback(item.getCallback(false), item.config.alias, ToPyInt(value), item.config.user_data);
					});
		}
	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_drag_intx(ImDrawList* drawlist, mvAppItem& item, mvDragIntMultiConfig& config)
{
	//-----------------------------------------------------------------------------
// pre draw
//-----------------------------------------------------------------------------

// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);


	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{

		ScopedID id(item.uuid);

		bool activated = false;

		if (!item.config.enabled) std::copy(config.value->data(), config.value->data() + 2, config.disabled_value);

		switch (config.size)
		{
		case 2:
			activated = ImGui::DragInt2(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.speed, config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		case 3:
			activated = ImGui::DragInt3(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.speed, config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		case 4:
			activated = ImGui::DragInt4(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.speed, config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		default:
			break;
		}

		if (activated)
		{
			auto value = *config.value;
			if (item.config.alias.empty())
				mvSubmitCallback([&item, value]() {
				mvAddCallback(item.getCallback(false), item.uuid, ToPyIntList(value.data(), (int)value.size()), item.config.user_data);
					});
			else
				mvSubmitCallback([&item, value]() {
				mvAddCallback(item.getCallback(false), item.config.alias, ToPyIntList(value.data(), (int)value.size()), item.config.user_data);
					});
		}
	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_drag_floatx(ImDrawList* drawlist, mvAppItem& item, mvDragFloatMultiConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{
		ScopedID id(item.uuid);

		bool activated = false;

		if (!item.config.enabled) std::copy(config.value->data(), config.value->data() + 2, config.disabled_value);

		switch (config.size)
		{
		case 2:
			activated = ImGui::DragFloat2(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.speed, config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		case 3:
			activated = ImGui::DragFloat3(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.speed, config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		case 4:
			activated = ImGui::DragFloat4(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.speed, config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		default:
			break;
		}

		if (activated)
		{
			auto value = *config.value;
			if (item.config.alias.empty())
				mvSubmitCallback([&item, value]() {
				mvAddCallback(item.getCallback(false), item.uuid, ToPyFloatList(value.data(), (int)value.size()), item.config.user_data);
					});
			else
				mvSubmitCallback([&item, value]() {
				mvAddCallback(item.getCallback(false), item.config.alias, ToPyFloatList(value.data(), (int)value.size()), item.config.user_data);
					});
		}
	}
	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_slider_float(ImDrawList* drawlist, mvAppItem& item, mvSliderFloatConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{
		ScopedID id(item.uuid);

		if (!item.config.enabled) config.disabled_value = *config.value;

		if (config.vertical)
		{
			if ((float)item.config.height < 1.0f)
				item.config.height = 100;
			if ((float)item.config.width < 1.0f)
				item.config.width = 20;

			if (ImGui::VSliderFloat(item.info.internalLabel.c_str(), ImVec2((float)item.config.width, (float)item.config.height), item.config.enabled ? config.value.get() : &config.disabled_value, config.minv, config.maxv, config.format.c_str()))
			{
				auto value = *config.value;

				if (item.config.alias.empty())
					mvSubmitCallback([&item, value]() { mvAddCallback(item.getCallback(false), item.uuid, ToPyFloat(value), item.config.user_data);});
				else
					mvSubmitCallback([&item, value]() { mvAddCallback(item.getCallback(false), item.config.alias, ToPyFloat(value), item.config.user_data);});
			}

		}
		else
		{
			if (ImGui::SliderFloat(item.info.internalLabel.c_str(), item.config.enabled ? config.value.get() : &config.disabled_value, config.minv, config.maxv, config.format.c_str(), config.flags))
			{
				auto value = *config.value;
				if (item.config.alias.empty())
					mvSubmitCallback([&item, value]() {mvAddCallback(item.getCallback(false), item.uuid, ToPyFloat(value), item.config.user_data);});
				else
					mvSubmitCallback([&item, value]() {mvAddCallback(item.getCallback(false), item.config.alias, ToPyFloat(value), item.config.user_data);});
			}

		}
	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_slider_floatx(ImDrawList* drawlist, mvAppItem& item, mvSliderFloatMultiConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{
		ScopedID id(item.uuid);

		bool activated = false;

		if (!item.config.enabled) std::copy(config.value->data(), config.value->data() + 4, config.disabled_value);

		switch (config.size)
		{
		case 2:
			activated = ImGui::SliderFloat2(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		case 3:
			activated = ImGui::SliderFloat3(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		case 4:
			activated = ImGui::SliderFloat4(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		default:
			break;
		}

		if (activated)
		{
			auto value = *config.value;

			if (item.config.alias.empty())
				mvSubmitCallback([&item, value]() {mvAddCallback(item.getCallback(false), item.uuid, ToPyFloatList(value.data(), (int)value.size()), item.config.user_data);});
			else
				mvSubmitCallback([&item, value]() {mvAddCallback(item.getCallback(false), item.config.alias, ToPyFloatList(value.data(), (int)value.size()), item.config.user_data);});
		}
	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_slider_int(ImDrawList* drawlist, mvAppItem& item, mvSliderIntConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{
		ScopedID id(item.uuid);

		if (!item.config.enabled) config.disabled_value = *config.value;

		if (config.vertical)
		{
			if ((float)item.config.height < 1.0f)
				item.config.height = 100;
			if ((float)item.config.width < 1.0f)
				item.config.width = 20;

			if (ImGui::VSliderInt(item.info.internalLabel.c_str(), ImVec2((float)item.config.width, (float)item.config.height), item.config.enabled ? config.value.get() : &config.disabled_value, config.minv, config.maxv, config.format.c_str()))
			{
				auto value = *config.value;

				if (item.config.alias.empty())
					mvSubmitCallback([&item, value]() { mvAddCallback(item.getCallback(false), item.uuid, ToPyInt(value), item.config.user_data);});
				else
					mvSubmitCallback([&item, value]() { mvAddCallback(item.getCallback(false), item.config.alias, ToPyInt(value), item.config.user_data);});
			}

		}
		else
		{
			if (ImGui::SliderInt(item.info.internalLabel.c_str(), item.config.enabled ? config.value.get() : &config.disabled_value, config.minv, config.maxv, config.format.c_str(), config.flags))
			{
				auto value = *config.value;
				if (item.config.alias.empty())
					mvSubmitCallback([&item, value]() {mvAddCallback(item.getCallback(false), item.uuid, ToPyInt(value), item.config.user_data);});
				else
					mvSubmitCallback([&item, value]() {mvAddCallback(item.getCallback(false), item.config.alias, ToPyInt(value), item.config.user_data);});
			}

		}
	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_slider_intx(ImDrawList* drawlist, mvAppItem& item, mvSliderIntMultiConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{
		ScopedID id(item.uuid);

		bool activated = false;

		if (!item.config.enabled) std::copy(config.value->data(), config.value->data() + 4, config.disabled_value);

		switch (config.size)
		{
		case 2:
			activated = ImGui::SliderInt2(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		case 3:
			activated = ImGui::SliderInt3(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		case 4:
			activated = ImGui::SliderInt4(item.info.internalLabel.c_str(), item.config.enabled ? config.value->data() : &config.disabled_value[0], config.minv, config.maxv, config.format.c_str(), config.flags);
			break;
		default:
			break;
		}

		if (activated)
		{
			auto value = *config.value;

			if (item.config.alias.empty())
				mvSubmitCallback([&item, value]() {mvAddCallback(item.getCallback(false), item.uuid, ToPyIntList(value.data(), (int)value.size()), item.config.user_data); });
			else
				mvSubmitCallback([&item, value]() {mvAddCallback(item.getCallback(false), item.config.alias, ToPyIntList(value.data(), (int)value.size()), item.config.user_data); });
		}
	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_listbox(ImDrawList *drawlist, mvAppItem &item, mvListboxConfig &config)
{
    //-----------------------------------------------------------------------------
    // pre draw
    //-----------------------------------------------------------------------------

    // show/hide
    if (!item.config.show)
        return;

    // focusing
    if (item.info.focusNextFrame)
    {
        ImGui::SetKeyboardFocusHere();
        item.info.focusNextFrame = false;
    }

    // cache old cursor position
    ImVec2 previousCursorPos = ImGui::GetCursorPos();

    // set cursor position if user set
    if (item.info.dirtyPos)
        ImGui::SetCursorPos(item.state.pos);

    // update widget's position state
    item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

    // set item width
    if (item.config.width != 0)
        ImGui::SetNextItemWidth((float)item.config.width);

    // set indent
    if (item.config.indent > 0.0f)
        ImGui::Indent(item.config.indent);

    // push font if a font object is attached
    if (item.font)
    {
        ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
        ImGui::PushFont(fontptr);
    }

    // themes
    apply_local_theming(&item);

    //-----------------------------------------------------------------------------
    // draw
    //-----------------------------------------------------------------------------
    {

        ScopedID id(item.uuid);

        if(!item.config.enabled)
        {
            config.disabled_value = *config.value;
            config.disabledindex = config.index;
        }

        // remap Header to FrameBgActive
        ImGuiStyle* style = &ImGui::GetStyle();
        ImGui::PushStyleColor(ImGuiCol_Header, style->Colors[ImGuiCol_FrameBgActive]);

        if (ImGui::ListBox(item.info.internalLabel.c_str(), item.config.enabled ? &config.index : &config.disabledindex, config.charNames.data(), (int)config.names.size(), config.itemsHeight))
        {
            *config.value = config.names[config.index];
            config.disabled_value = config.names[config.index];
            auto value = *config.value;

            if(item.config.alias.empty())
                mvSubmitCallback([&item, value]() {
                    mvAddCallback(item.getCallback(false), item.uuid, ToPyString(value), item.config.user_data);
                });
            else
                mvSubmitCallback([&item, value]() {
                    mvAddCallback(item.getCallback(false), item.config.alias, ToPyString(value), item.config.user_data);
                });
        }

        ImGui::PopStyleColor();
    }

    //-----------------------------------------------------------------------------
    // update state
    //-----------------------------------------------------------------------------
    UpdateAppItemState(item.state);

    //-----------------------------------------------------------------------------
    // post draw
    //-----------------------------------------------------------------------------

    // set cursor position to cached position
    if (item.info.dirtyPos)
        ImGui::SetCursorPos(previousCursorPos);

    if (item.config.indent > 0.0f)
        ImGui::Unindent(item.config.indent);

    // pop font off stack
    if (item.font)
        ImGui::PopFont();

    // handle popping themes
    cleanup_local_theming(&item);

    if (item.handlerRegistry)
        item.handlerRegistry->checkEvents(&item.state);

    // handle drag & drop if used
    apply_drag_drop(&item);
}

void
DearPyGui::draw_radio_button(ImDrawList* drawlist, mvAppItem& item, mvRadioButtonConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{

		ImGui::BeginGroup();

		ScopedID id(item.uuid);

		if (!item.config.enabled)
		{
			config.disabled_value = *config.value;
			config.disabledindex = config.index;
		}

		for (size_t i = 0; i < config.itemnames.size(); i++)
		{
			if (config.horizontal && i != 0)
				ImGui::SameLine();

			if (ImGui::RadioButton(config.itemnames[i].c_str(), item.config.enabled ? &config.index : &config.disabledindex, (int)i))
			{
				*config.value = config.itemnames[config.index];
				config.disabled_value = config.itemnames[config.index];
				auto value = *config.value;

				if (item.config.alias.empty())
					mvSubmitCallback([&item, value]() {mvAddCallback(item.getCallback(false), item.uuid, ToPyString(value), item.config.user_data);});
				else
					mvSubmitCallback([&item, value]() { mvAddCallback(item.getCallback(false), item.config.alias, ToPyString(value), item.config.user_data);});
			}

			item.state.edited = ImGui::IsItemEdited();
		}

		ImGui::EndGroup();

	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	item.state.lastFrameUpdate = GContext->frame;
	item.state.hovered = ImGui::IsItemHovered();
	item.state.active = ImGui::IsItemActive();
	item.state.focused = ImGui::IsItemFocused();
	item.state.leftclicked = ImGui::IsItemClicked();
	item.state.rightclicked = ImGui::IsItemClicked(1);
	item.state.middleclicked = ImGui::IsItemClicked(2);
	item.state.visible = ImGui::IsItemVisible();
	item.state.activated = ImGui::IsItemActivated();
	item.state.deactivated = ImGui::IsItemDeactivated();
	item.state.deactivatedAfterEdit = ImGui::IsItemDeactivatedAfterEdit();
	item.state.toggledOpen = ImGui::IsItemToggledOpen();
	item.state.rectMin = { ImGui::GetItemRectMin().x, ImGui::GetItemRectMin().y };
	item.state.rectMax = { ImGui::GetItemRectMax().x, ImGui::GetItemRectMax().y };
	item.state.rectSize = { ImGui::GetItemRectSize().x, ImGui::GetItemRectSize().y };
	item.state.contextRegionAvail = { ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y };

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_input_text(ImDrawList* drawlist, mvAppItem& item, mvInputTextConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{

		ScopedID id(item.uuid);

		bool activated = false;

		if (config.multiline)
			config.hint.clear();

		if (config.hint.empty())
		{
			if (config.multiline)
				activated = ImGui::InputTextMultiline(item.info.internalLabel.c_str(), config.value.get(), ImVec2((float)item.config.width, (float)item.config.height), config.flags);
			else
				activated = ImGui::InputText(item.info.internalLabel.c_str(), config.value.get(), config.flags);
		}
		else
			activated = ImGui::InputTextWithHint(item.info.internalLabel.c_str(), config.hint.c_str(), config.value.get(), config.flags);

		if (activated)
		{
			auto value = *config.value;
			if (item.config.alias.empty())
				mvSubmitCallback([&item, value]() {
				mvAddCallback(item.getCallback(false), item.uuid, ToPyString(value), item.config.user_data);
					});
			else
				mvSubmitCallback([&item, value]() {
				mvAddCallback(item.getCallback(false), item.config.alias, ToPyString(value), item.config.user_data);
					});
		}

	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_input_int(ImDrawList* drawlist, mvAppItem& item, mvInputIntConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{

		ScopedID id(item.uuid);

		if (ImGui::InputInt(item.info.internalLabel.c_str(), config.value.get(), config.step, config.step_fast, config.flags))
		{
			// determines clamped cases
			if (config.min_clamped && config.max_clamped)
			{
				if (*config.value < config.minv) *config.value = config.minv;
				else if (*config.value > config.maxv) *config.value = config.maxv;
			}
			else if (config.min_clamped)
			{
				if (*config.value < config.minv) *config.value = config.minv;
			}
			else if (config.max_clamped)
			{
				if (*config.value > config.maxv) *config.value = config.maxv;
			}

			// If the widget is edited through ctrl+click mode the active value will be entered every frame.
			// If the value is out of bounds the value will be overwritten with max or min so each frame the value will be switching between the
			// ctrl+click value and the bounds value until the widget is not in ctrl+click mode. To prevent the callback from running every 
			// frame we check if the value was already submitted.
			if (config.last_value != *config.value)
			{
				config.last_value = *config.value;
				auto value = *config.value;

				if (item.config.alias.empty())
					mvSubmitCallback([&item, value]() {
					mvAddCallback(item.getCallback(false), item.uuid, ToPyInt(value), item.config.user_data);
						});
				else
					mvSubmitCallback([&item, value]() {
					mvAddCallback(item.getCallback(false), item.config.alias, ToPyInt(value), item.config.user_data);
						});
			}
		}

	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_input_floatx(ImDrawList* drawlist, mvAppItem& item, mvInputFloatMultiConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{

		ScopedID id(item.uuid);

		bool res = false;

		switch (config.size)
		{
		case 2:
			res = ImGui::InputFloat2(item.info.internalLabel.c_str(), config.value->data(), config.format.c_str(), config.flags);
			break;
		case 3:
			res = ImGui::InputFloat3(item.info.internalLabel.c_str(), config.value->data(), config.format.c_str(), config.flags);
			break;
		case 4:
			res = ImGui::InputFloat4(item.info.internalLabel.c_str(), config.value->data(), config.format.c_str(), config.flags);
			break;
		default:
			break;
		}

		if (res)
		{
			auto inital_value = *config.value;
			// determines clamped cases
			if (config.min_clamped && config.max_clamped)
			{
				for (int i = 0; i < 4; i++)
				{
					if (config.value->data()[i] < config.minv) config.value->data()[i] = config.minv;
					else if (config.value->data()[i] > config.maxv) config.value->data()[i] = config.maxv;
				}
			}
			else if (config.min_clamped)
			{
				for (int i = 0; i < 4; i++)
				{
					if (config.value->data()[i] < config.minv) config.value->data()[i] = config.minv;
				}
			}
			else if (config.max_clamped)
			{
				for (int i = 0; i < 4; i++)
				{
					if (config.value->data()[i] > config.maxv) config.value->data()[i] = config.maxv;
				}
			}

			// If the widget is edited through ctrl+click mode the active value will be entered every frame.
			// If the value is out of bounds the value will be overwritten with max or min so each frame the value will be switching between the
			// ctrl+click value and the bounds value until the widget is not in ctrl+click mode. To prevent the callback from running every 
			// frame we check if the value was already submitted.
			if (config.last_value != *config.value)
			{
				config.last_value = *config.value;
				auto value = *config.value;

				if (item.config.alias.empty())
					mvSubmitCallback([&item, value]() {
					mvAddCallback(item.getCallback(false), item.uuid, ToPyFloatList(value.data(), (int)value.size()), item.config.user_data);
						});
				else
					mvSubmitCallback([&item, value]() {
					mvAddCallback(item.getCallback(false), item.config.alias, ToPyFloatList(value.data(), (int)value.size()), item.config.user_data);
						});
			}
		}

	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);

}

void
DearPyGui::draw_input_float(ImDrawList* drawlist, mvAppItem& item, mvInputFloatConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{

		ScopedID id(item.uuid);

		if (ImGui::InputFloat(item.info.internalLabel.c_str(), config.value.get(), config.step, config.step_fast, config.format.c_str(), config.flags))
		{
			// determines clamped cases
			if (config.min_clamped && config.max_clamped)
			{
				if (*config.value < config.minv) *config.value = config.minv;
				else if (*config.value > config.maxv) *config.value = config.maxv;
			}
			else if (config.min_clamped)
			{
				if (*config.value < config.minv) *config.value = config.minv;
			}
			else if (config.max_clamped)
			{
				if (*config.value > config.maxv) *config.value = config.maxv;
			}

			// If the widget is edited through ctrl+click mode the active value will be entered every frame.
			// If the value is out of bounds the value will be overwritten with max or min so each frame the value will be switching between the
			// ctrl+click value and the bounds value until the widget is not in ctrl+click mode. To prevent the callback from running every 
			// frame we check if the value was already submitted.
			if (config.last_value != *config.value)
			{
				config.last_value = *config.value;
				auto value = *config.value;

				if (item.config.alias.empty())
					mvSubmitCallback([&item, value]() {
					mvAddCallback(item.getCallback(false), item.uuid, ToPyFloat(value), item.config.user_data);
						});
				else
					mvSubmitCallback([&item, value]() {
					mvAddCallback(item.getCallback(false), item.config.alias, ToPyFloat(value), item.config.user_data);
						});
			}
		}
	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_input_intx(ImDrawList* drawlist, mvAppItem& item, mvInputIntMultiConfig& config)
{
	//-----------------------------------------------------------------------------
	// pre draw
	//-----------------------------------------------------------------------------

	// show/hide
	if (!item.config.show)
		return;

	// focusing
	if (item.info.focusNextFrame)
	{
		ImGui::SetKeyboardFocusHere();
		item.info.focusNextFrame = false;
	}

	// cache old cursor position
	ImVec2 previousCursorPos = ImGui::GetCursorPos();

	// set cursor position if user set
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(item.state.pos);

	// update widget's position state
	item.state.pos = { ImGui::GetCursorPosX(), ImGui::GetCursorPosY() };

	// set item width
	if (item.config.width != 0)
		ImGui::SetNextItemWidth((float)item.config.width);

	// set indent
	if (item.config.indent > 0.0f)
		ImGui::Indent(item.config.indent);

	// push font if a font object is attached
	if (item.font)
	{
		ImFont* fontptr = static_cast<mvFont*>(item.font.get())->getFontPtr();
		ImGui::PushFont(fontptr);
	}

	// themes
	apply_local_theming(&item);

	//-----------------------------------------------------------------------------
	// draw
	//-----------------------------------------------------------------------------
	{
		ScopedID id(item.uuid);

		bool res = false;

		switch (config.size)
		{
		case 2:
			res = ImGui::InputInt2(item.info.internalLabel.c_str(), config.value->data(), config.flags);
			break;
		case 3:
			res = ImGui::InputInt3(item.info.internalLabel.c_str(), config.value->data(), config.flags);
			break;
		case 4:
			res = ImGui::InputInt4(item.info.internalLabel.c_str(), config.value->data(), config.flags);
			break;
		default:
			break;
		}

		if (res)
		{
			auto inital_value = *config.value;
			// determines clamped cases
			if (config.min_clamped && config.max_clamped)
			{
				for (int i = 0; i < 4; i++)
				{
					if (config.value->data()[i] < config.minv) config.value->data()[i] = config.minv;
					else if (config.value->data()[i] > config.maxv) config.value->data()[i] = config.maxv;
				}
			}
			else if (config.min_clamped)
			{
				for (int i = 0; i < 4; i++)
				{
					if (config.value->data()[i] < config.minv) config.value->data()[i] = config.minv;
				}
			}
			else if (config.max_clamped)
			{
				for (int i = 0; i < 4; i++)
				{
					if (config.value->data()[i] > config.maxv) config.value->data()[i] = config.maxv;
				}
			}

			// If the widget is edited through ctrl+click mode the active value will be entered every frame.
			// If the value is out of bounds the value will be overwritten with max or min so each frame the value will be switching between the
			// ctrl+click value and the bounds value until the widget is not in ctrl+click mode. To prevent the callback from running every 
			// frame we check if the value was already submitted.
			if (config.last_value != *config.value)
			{
				config.last_value = *config.value;

				auto value = *config.value;

				if (item.config.alias.empty())
					mvSubmitCallback([&item, value]() {
					mvAddCallback(item.getCallback(false), item.uuid, ToPyIntList(value.data(), (int)value.size()), item.config.user_data);
						});
				else
					mvSubmitCallback([&item, value]() {
					mvAddCallback(item.getCallback(false), item.config.alias, ToPyIntList(value.data(), (int)value.size()), item.config.user_data);
						});
			}
		}
	}

	//-----------------------------------------------------------------------------
	// update state
	//-----------------------------------------------------------------------------
	UpdateAppItemState(item.state);

	//-----------------------------------------------------------------------------
	// post draw
	//-----------------------------------------------------------------------------

	// set cursor position to cached position
	if (item.info.dirtyPos)
		ImGui::SetCursorPos(previousCursorPos);

	if (item.config.indent > 0.0f)
		ImGui::Unindent(item.config.indent);

	// pop font off stack
	if (item.font)
		ImGui::PopFont();

	// handle popping themes
	cleanup_local_theming(&item);

	if (item.handlerRegistry)
		item.handlerRegistry->checkEvents(&item.state);

	// handle drag & drop if used
	apply_drag_drop(&item);
}

void
DearPyGui::draw_separator(ImDrawList* drawlist, mvAppItem& item)
{ 
	ImGui::Separator(); 
}

void
DearPyGui::draw_spacer(ImDrawList* drawlist, mvAppItem& item)
{ 
	if (item.config.width == 0 && item.config.height == 0) 
		ImGui::Spacing(); 
	else 
		ImGui::Dummy({ (float)item.config.width, (float)item.config.height }); 
}

void
DearPyGui::draw_menubar(ImDrawList* drawlist, mvAppItem& item)
{
	if (ImGui::BeginMenuBar())
	{

		item.state.lastFrameUpdate = GContext->frame;
		item.state.visible = true;

		for (auto& item : item.childslots[1])
			item->draw(drawlist, ImGui::GetCursorPosX(), ImGui::GetCursorPosY());

		ImGui::EndMenuBar();
	}
}

void
DearPyGui::draw_clipper(ImDrawList* drawlist, mvAppItem& item)
{
	ScopedID id(item.uuid);

	if (item.config.width != 0)
		ImGui::PushItemWidth((float)item.config.width);


	ImGuiListClipper clipper;
	clipper.Begin((int)item.childslots[1].size());

	while (clipper.Step())
	{
		for (int row_n = clipper.DisplayStart; row_n < clipper.DisplayEnd; row_n++)
			item.childslots[1][row_n]->draw(drawlist, ImGui::GetCursorPosX(), ImGui::GetCursorPosY());
	}
	clipper.End();
	if (item.config.width != 0)
		ImGui::PopItemWidth();
}

void 
mvDragIntMulti::setPyValue(PyObject* value)
{
	std::vector<int> temp = ToIntVect(value);
	while (temp.size() < 4)
		temp.push_back(0);
	std::array<int, 4> temp_array;
	for (size_t i = 0; i < temp_array.size(); i++)
		temp_array[i] = temp[i];
	if (configData.value)
		*configData.value = temp_array;
	else
		configData.value = std::make_shared<std::array<int, 4>>(temp_array);
}

void 
mvDragFloatMulti::setPyValue(PyObject* value)
{
	std::vector<float> temp = ToFloatVect(value);
	while (temp.size() < 4)
		temp.push_back(0.0f);
	std::array<float, 4> temp_array;
	for (size_t i = 0; i < temp_array.size(); i++)
		temp_array[i] = temp[i];
	if (configData.value)
		*configData.value = temp_array;
	else
		configData.value = std::make_shared<std::array<float, 4>>(temp_array);
}

void
mvSliderFloatMulti::setPyValue(PyObject* value)
{
	std::vector<float> temp = ToFloatVect(value);
	while (temp.size() < 4)
		temp.push_back(0.0f);
	std::array<float, 4> temp_array;
	for (size_t i = 0; i < temp_array.size(); i++)
		temp_array[i] = temp[i];
	if (configData.value)
		*configData.value = temp_array;
	else
		configData.value = std::make_shared<std::array<float, 4>>(temp_array);
}

void 
mvSliderIntMulti::setPyValue(PyObject* value)
{
	std::vector<int> temp = ToIntVect(value);
	while (temp.size() < 4)
		temp.push_back(0);
	std::array<int, 4> temp_array;
	for (size_t i = 0; i < temp_array.size(); i++)
		temp_array[i] = temp[i];
	if (configData.value)
		*configData.value = temp_array;
	else
		configData.value = std::make_shared<std::array<int, 4>>(temp_array);
}

void
mvListbox::setPyValue(PyObject *value)
{
    *configData.value = ToString(value);

    configData.index = 0;
    configData.disabledindex = 0;

    int index = 0;
    for (const auto& name : configData.names)
    {
        if (name == *configData.value)
        {
            configData.index = index;
            configData.disabledindex = index;
            break;
        }
        index++;
    }
}

void
mvRadioButton::setPyValue(PyObject* value)
{
	*configData.value = ToString(value);

	// update index
	configData.index = 0;
	configData.disabledindex = 0;

	int index = 0;
	for (const auto& name : configData.itemnames)
	{
		if (name == *configData.value)
		{
			configData.index = index;
			configData.disabledindex = index;
			break;
		}
		index++;
	}
}

void 
mvInputIntMulti::setPyValue(PyObject* value)
{
	std::vector<int> temp = ToIntVect(value);
	while (temp.size() < 4)
		temp.push_back(0);
	std::array<int, 4> temp_array;
	for (size_t i = 0; i < temp_array.size(); i++)
		temp_array[i] = temp[i];
	if (configData.value)
		*configData.value = temp_array;
	else
		configData.value = std::make_shared<std::array<int, 4>>(temp_array);
}

void 
mvInputFloatMulti::setPyValue(PyObject* value)
{
	std::vector<float> temp = ToFloatVect(value);
	while (temp.size() < 4)
		temp.push_back(0.0f);
	std::array<float, 4> temp_array;
	for (size_t i = 0; i < temp_array.size(); i++)
		temp_array[i] = temp[i];
	if (configData.value)
		*configData.value = temp_array;
	else
		configData.value = std::make_shared<std::array<float, 4>>(temp_array);
}
