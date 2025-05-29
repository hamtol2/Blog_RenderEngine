// Win32 API�� ����ϱ� ���� include.
#include <Windows.h>
#include "../Engine/Core/Window.h"

// â���� �޽����� �߻��ϸ� ȣ��� �Լ�.
LRESULT WINAPI WindowProc(HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        // â�� �����Ǹ� �߻��ϴ� �޽���.
    case WM_DESTROY:
        // ���α׷� ���� �޽��� �߻���Ű��.
        PostQuitMessage(0);
        break;
    }

    // ������ �޽����� ������ �⺻ �������� ó��.
    return DefWindowProc(hwnd, message, wParam, lParam);
}

// ���� �Լ�(Entry Point).
int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    // â ����.
    Window window(hInstance, 1280, 800, TEXT("Toy Render Engine"), WindowProc);

    // �޽��� ����.
    MSG msg = { 0 };
    while (msg.message != WM_QUIT)
    {
        // â���� �޽����� �߻��ϴ� �� Ȯ��.
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            // �޽��� ��ȯ.
            TranslateMessage(&msg);
            // �޽��� ����.
            DispatchMessage(&msg);
        }
        else
        {

        }
    }
}