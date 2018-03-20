#pragma once
#include <windows.h>
#include <d3d11_1.h>
#pragma comment(lib, "d3d11.lib")

struct PText {
	int id;
};


struct PButton {
	int id;
};

struct PSlider {
	int id;
};

struct PPanel {
	int id;
};

class PUi {
public:
	PUi();
	~PUi();

	void Init(HWND hwnd);

	void Resize(int w, int h);

	void Draw();


private:

	ID3D11Device* m_device;
	ID3D11DeviceContext* m_context;
	IDXGISwapChain* m_swapChain;
	ID3D11RenderTargetView* m_rtv;

	HWND m_hWnd;
};