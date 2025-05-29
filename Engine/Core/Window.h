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
	// â ���� ũ��.
	uint32 width = 0;
	// â ���� ũ��.
	uint32 height = 0;
	// â ����.
	std::wstring title;
	// â Ŭ���� ������ ����� Ŭ���� �̸�.
	std::wstring className = TEXT("EngineClass");
	// â �ڵ�.
	HWND handle = nullptr;
	// ���α׷� �ν��Ͻ�.
	HINSTANCE instance = nullptr;
};