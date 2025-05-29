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
    // ������ Ŭ���� ����ü ����.
    WNDCLASS wc = { };
    wc.lpfnWndProc = messageProcedure;      // â���� �߻��� �޽����� ó���� �� ȣ��� �Լ�.
    wc.hInstance = instance;                // ���α׷� �ڵ� �� ����.
    wc.lpszClassName = className.c_str();   // Ŭ���� �̸� ����.

    // Ŭ���� ���.
    if (RegisterClass(&wc) == false)
    {
        // Ŭ���� ��Ͽ� �����ϸ� �� �ڵ忡�� �ߴ����� ����ǵ��� ���� ó��.
        __debugbreak();
    }

    // â ũ�� ����.
    // â�� ������ �� Ÿ��Ʋ �� ���� �����ϴ� ������ ������ 
    // ���� �׷����� ������ ũ�⸦ ����� ���ϱ� ���� �ڵ�.
    RECT rect = { 0, 0, static_cast<long>(width), static_cast<long>(height) };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

    // ���� Direct3D�� Ȱ���� �׸��� ������ 1280/800���� Ȯ���� ���� â ũ�� �ٽ� ���ϱ�.
    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;

    // â ��ġ ���ϱ�.
    // ������� ��� ��ġ ���ϱ�.
    int xPosition = (GetSystemMetrics(SM_CXSCREEN) - windowWidth) / 2;
    int yPosition = (GetSystemMetrics(SM_CYSCREEN) - windowHeight) / 2;

    // â ����.
    handle = CreateWindowEx(
        0,           // ������ ��Ÿ��(�ɼ�).
        className.c_str(),   // ������ Ŭ���� �̸�.
        title.c_str(), // ���� ������ Ÿ��Ʋ.
        WS_OVERLAPPEDWINDOW, // â�� ������ ��Ÿ��.

        // ��ġ.
        xPosition, yPosition,
        // ũ��.
        windowWidth, windowHeight,

        nullptr,    // �θ� â.
        nullptr,    // �޴�.
        instance,  // ���α׷� �ڵ� ��.
        nullptr     // �߰��� ������ ���ø����̼� ������.
    );

    // â ������ ������ ���, ���α׷� ����. (���� �ڵ� -1).
    if (handle == nullptr)
    {
        // â ������ �����ϸ� �� �ڵ忡�� �ߴ����� ����ǵ��� ���� ó��.
        __debugbreak();
    }
    
    // â �����ֱ�.
    ShowWindow(handle, SW_SHOW);

    // ������Ʈ �ݿ�.
    UpdateWindow(handle);
}

Window::~Window()
{
    // Ŭ���� ��� ����.
    UnregisterClass(className.c_str(), instance);
}