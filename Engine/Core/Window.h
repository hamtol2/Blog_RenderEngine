#pragma once

#include "Types.h"
#include <Windows.h>
#include <string>

class Window
{
public:
	Window(
		HINSTANCE instance, 
		uint32 width, 
		uint32 height, 
		const std::wstring& title,
		WNDPROC messageProcedure
	);
	~Window();

	// Getter.
	inline const uint32 Width() const { return width; }
	inline const uint32 Height() const { return height; }
	const std::wstring& Title() const { return title; }
	inline const HWND Handle() const { return handle; }

private:
	// 창 가로 크기.
	uint32 width = 0;
	// 창 세로 크기.
	uint32 height = 0;
	// 창 제목.
	std::wstring title;
	// 창 클래스 생성시 사용할 클래스 이름.
	std::wstring className = TEXT("EngineClass");
	// 창 핸들.
	HWND handle = nullptr;
	// 프로그램 인스턴스.
	HINSTANCE instance = nullptr;
};