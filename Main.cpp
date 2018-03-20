#include "PGui.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	char className [] = "MainWindowClass";
	int width = 800;
	int height = 600;

	WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, NULL, NULL, hInstance, NULL, NULL, NULL, NULL, className, NULL };
	RegisterClassEx(&wcex);

	HWND hWnd = CreateWindowEx(0, className, "Game", WS_OVERLAPPEDWINDOW, 150, 150, width, height, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	PUi pui;
	pui.Init(hWnd);
	

	MSG msg = { 0 };
	while (WM_QUIT != msg.message) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			pui.Draw();
		}
	}

	return (int)msg.wParam;


}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {
	case WM_SIZE:

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}