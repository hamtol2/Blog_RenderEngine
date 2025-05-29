#pragma once

// dll에서 템플릿을 내보낼 때 발생하는 경고를 끄는 옵션.
// dll 내부의 클래스에서 std::vector 등을 사용하면 발생하기 때문에 인지하는 경우에는 끌 수 있음.
#pragma warning(disable: 4251)

// __declspec(dllexport) / __declspec(dllimport)를 자연스럽게 변경할 수 있도록 매크로 선언.
#ifdef BUILD_DLL
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

// 자주 사용하는 타입에 대한 타입 재정의.
using uint8 = unsigned __int8;
using int8 = __int8;
using uint32 = unsigned __int32;
using int32 = __int32;
using uint64 = unsigned __int64;
using int64 = __int64;