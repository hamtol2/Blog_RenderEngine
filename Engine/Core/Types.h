#pragma once

#pragma warning(disable: 4251)

#ifdef BUILD_DLL
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

using uint8 = unsigned __int8;
using int8 = __int8;
using uint32 = unsigned __int32;
using int32 = __int32;
using uint64 = unsigned __int64;
using int64 = __int64;