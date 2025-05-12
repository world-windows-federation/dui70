#pragma once

#include <Windows.h>

#include <ShellScalingApi.h>
#include <Vsstyle.h>
#include <vssym32.h>

#include <wil/common.h>
#include <wil/result.h>

#include <fstream>
#include <sstream>
#include <format>
#include <functional>
#include <filesystem>

#include "../DirectUI/DirectUI.h"

#pragma comment(lib, "dui70.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "Shcore.lib")
#include "resource.h"

#define RECTWIDTH(rc)   ((rc).right-(rc).left)
#define RECTHEIGHT(rc)  ((rc).bottom-(rc).top)