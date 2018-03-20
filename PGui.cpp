#include "PGui.h"

PUi::PUi() : m_device(nullptr), m_context(nullptr), m_swapChain(nullptr), m_rtv(nullptr){

}

PUi::~PUi(){
	m_rtv->Release();
	m_rtv = nullptr;

	m_swapChain->Release();
	m_swapChain = nullptr;

	m_context->Release();
	m_context = nullptr;

	m_device->Release();
	m_device = nullptr;

}

void PUi::Init(HWND hwnd){
	m_hWnd = hwnd;

	DXGI_SWAP_CHAIN_DESC scd;
	ZeroMemory(&scd, sizeof(scd));
	scd.BufferCount								= 2;
	scd.BufferDesc.Width						= 0;
	scd.BufferDesc.Height						= 0;
	scd.BufferDesc.RefreshRate.Numerator		= 60;
	scd.BufferDesc.RefreshRate.Denominator		= 1;
	scd.BufferDesc.Format						= DXGI_FORMAT_R8G8B8A8_UNORM;
	scd.BufferUsage								= DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scd.OutputWindow							= m_hWnd;
	scd.SampleDesc.Count						= 1;
	scd.SampleDesc.Quality						= 0;
	//scd.BufferDesc.Scaling					= DXGI_MODE_SCALING_CENTERED;
	scd.Windowed								= TRUE;
	scd.SwapEffect								= DXGI_SWAP_EFFECT_DISCARD;
	D3D11CreateDeviceAndSwapChain(0, D3D_DRIVER_TYPE_HARDWARE, 0, 0, 0, 0, D3D11_SDK_VERSION, &scd, &m_swapChain, &m_device, NULL, &m_context);
	
	ID3D11Texture2D* backBufferTexture;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferTexture);
	m_device->CreateRenderTargetView(backBufferTexture, NULL, &m_rtv);
	backBufferTexture->Release();

}

void PUi::Resize(int w, int h){

	m_rtv->Release();
	m_rtv = nullptr;
	m_swapChain->ResizeBuffers(0, w, h, DXGI_FORMAT_UNKNOWN, 0);
	ID3D11Texture2D* backBufferTexture;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBufferTexture);
	m_device->CreateRenderTargetView(backBufferTexture, NULL, &m_rtv);
	backBufferTexture->Release();
}

void PUi::Draw() {
	float fill[4] = { 0.0f, 0.2f, 0.25f, 1.0f };

	m_context->OMSetRenderTargets(1, &m_rtv, 0);
	m_context->ClearRenderTargetView(m_rtv, fill);
	m_swapChain->Present(1, 0);
}
