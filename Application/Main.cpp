// Win32 API를 사용하기 위해 include.
#include <Windows.h>
#include "../Engine/Core/Window.h"

// 창에서 메시지가 발생하면 호출될 함수.
LRESULT WINAPI WindowProc(HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        // 창이 삭제되면 발생하는 메시지.
    case WM_DESTROY:
        // 프로그램 종료 메시지 발생시키기.
        PostQuitMessage(0);
        break;
    }

    // 나머지 메시지는 윈도우 기본 설정으로 처리.
    return DefWindowProc(hwnd, message, wParam, lParam);
}

// 메인 함수(Entry Point).
int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    // 창 생성.
    Window window(hInstance, 1280, 800, TEXT("Toy Render Engine"), WindowProc);

    // 메시지 루프.
    MSG msg = { 0 };
    while (msg.message != WM_QUIT)
    {
        // 창에서 메시지가 발생하는 지 확인.
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            // 메시지 변환.
            TranslateMessage(&msg);
            // 메시지 전달.
            DispatchMessage(&msg);
        }
        else
        {

        }
    }
}