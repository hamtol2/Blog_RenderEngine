#include "Window.h"

Window::Window(
	HINSTANCE instance, 
	uint32 width, 
	uint32 height, 
	const std::wstring& title, 
	WNDPROC messageProcedure)
	: instance(instance),
	width(width),
	height(height),
	title(title)
{
    // 윈도우 클래스 구조체 설정.
    WNDCLASS wc = { };
    wc.lpfnWndProc = messageProcedure;      // 창에서 발생한 메시지를 처리할 때 호출될 함수.
    wc.hInstance = instance;                // 프로그램 핸들 값 전달.
    wc.lpszClassName = className.c_str();   // 클래스 이름 설정.

    // 클래스 등록.
    if (RegisterClass(&wc) == false)
    {
        // 클래스 등록에 실패하면 이 코드에서 중단점이 실행되도록 중지 처리.
        __debugbreak();
    }

    // 창 크기 조정.
    // 창을 생성할 때 타이틀 바 등이 차지하는 영역을 제외한 
    // 실제 그려지는 영역의 크기를 제대로 구하기 위한 코드.
    RECT rect = { 0, 0, static_cast<long>(width), static_cast<long>(height) };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

    // 실제 Direct3D를 활용해 그리는 공간을 1280/800으로 확보한 실제 창 크기 다시 구하기.
    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;

    // 창 위치 구하기.
    // 모니터의 가운데 위치 구하기.
    int xPosition = (GetSystemMetrics(SM_CXSCREEN) - windowWidth) / 2;
    int yPosition = (GetSystemMetrics(SM_CYSCREEN) - windowHeight) / 2;

    // 창 생성.
    handle = CreateWindowEx(
        0,           // 윈도우 스타일(옵션).
        className.c_str(),   // 윈도우 클래스 이름.
        title.c_str(), // 제목에 보여줄 타이틀.
        WS_OVERLAPPEDWINDOW, // 창에 적용할 스타일.

        // 위치.
        xPosition, yPosition,
        // 크기.
        windowWidth, windowHeight,

        nullptr,    // 부모 창.
        nullptr,    // 메뉴.
        instance,  // 프로그램 핸들 값.
        nullptr     // 추가로 전달할 어플리케이션 데이터.
    );

    // 창 생성에 실패한 경우, 프로그램 종료. (오류 코드 -1).
    if (handle == nullptr)
    {
        // 창 생성에 실패하면 이 코드에서 중단점이 실행되도록 중지 처리.
        __debugbreak();
    }
    
    // 창 보여주기.
    ShowWindow(handle, SW_SHOW);

    // 업데이트 반영.
    UpdateWindow(handle);
}

Window::~Window()
{
    // 클래스 등록 해제.
    UnregisterClass(className.c_str(), instance);
}