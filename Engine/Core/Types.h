#pragma once

// dll���� ���ø��� ������ �� �߻��ϴ� ��� ���� �ɼ�.
// dll ������ Ŭ�������� std::vector ���� ����ϸ� �߻��ϱ� ������ �����ϴ� ��쿡�� �� �� ����.
#pragma warning(disable: 4251)

// __declspec(dllexport) / __declspec(dllimport)�� �ڿ������� ������ �� �ֵ��� ��ũ�� ����.
#ifdef BUILD_DLL
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

// ���� ����ϴ� Ÿ�Կ� ���� Ÿ�� ������.
using uint8 = unsigned __int8;
using int8 = __int8;
using uint32 = unsigned __int32;
using int32 = __int32;
using uint64 = unsigned __int64;
using int64 = __int64;