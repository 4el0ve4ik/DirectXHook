#pragma once
#include <d3d10_1.h>
#include <d3d10.h>
#include <dxgi.h>
#pragma comment(lib, "dxgi.lib")
#ifndef _M_X64
#pragma comment(lib, "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86/d3d10.lib")
#pragma comment(lib, "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86/d3dx10.lib")
#else
#pragma comment(lib, "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3d10.lib")
#pragma comment(lib, "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3dx10.lib")
#endif // !_M_X64


enum SwapChainIndex
{
	iQueryInterface = 0,
	iAddRef,
	iRelease,
	iSetPrivateData,
	iSetPrivateDataInterface,
	iGetPrivateData,
	iGetParent,
	iGetDevice,
	iPresent,
	iGetBuffer,
	iSetFullscreenState,
	iGetFullscreenState,
	iGetDesc,
	iResizeBuffers,
	iResizeTarget,
	iGetContainingOutput,
	iGetFrameStatistics,
	iGetLastPresentCount
};

enum DeviceIndex {
	iiQueryInterface = 0,
	iiAddRef,
	iiRelease,
	iVSSetConstantBuffers,
	iPSSetShaderResources,
	iPSSetShader,
	iPSSetSamplers,
	iVSSetShader,
	iDrawIndexed,
	iDraw,
	iPSSetConstantBuffers,
	iIASetInputLayout,
	iIASetVertexBuffers,
	iIASetIndexBuffer,
	iDrawIndexedInstanced,
	iDrawInstanced,
	iGSSetConstantBuffers,
	iGSSetShader,
	iIASetPrimitiveTopology,
	iVSSetShaderResources,
	iVSSetSamplers,
	iSetPredication,
	iGSSetShaderResources,
	iGSSetSamplers,
	iOMSetRenderTargets,
	iOMSetBlendState,
	iOMSetDepthStencilState,
	iSOSetTargets,
	iDrawAuto,
	iRSSetState,
	iRSSetViewports,
	iRSSetScissorRects,
	iCopySubresourceRegion,
	iCopyResource,
	iUpdateSubresource,
	iClearRenderTargetView,
	iClearDepthStencilView,
	iGenerateMips,
	iResolveSubresource,
	iVSGetConstantBuffers,
	iPSGetShaderResources,
	iPSGetShader,
	iPSGetSamplers,
	iVSGetShader,
	iPSGetConstantBuffers,
	iIAGetInputLayout,
	iIAGetVertexBuffers,
	iIAGetIndexBuffer,
	iGSGetConstantBuffers,
	iGSGetShader,
	iIAGetPrimitiveTopology,
	iVSGetShaderResources,
	iVSGetSamplers,
	iGetPredication,
	iGSGetShaderResources,
	iGSGetSamplers,
	iOMGetRenderTargets,
	iOMGetBlendState,
	iOMGetDepthStencilState,
	iSOGetTargets,
	iRSGetState,
	iRSGetViewports,
	iRSGetScissorRects,
	iGetDeviceRemovedReason,
	iSetExceptionMode,
	iGetExceptionMode,
	iiGetPrivateData,
	iiSetPrivateData,
	iiSetPrivateDataInterface,
	iClearState,
	iFlush,
	iCreateBuffer,
	iCreateTexture1D,
	iCreateTexture2D,
	iCreateTexture3D,
	iCreateShaderResourceView,
	iCreateRenderTargetView,
	iCreateDepthStencilView,
	iCreateInputLayout,
	iCreateVertexShader,
	iCreateGeometryShader,
	iCreateGeometryShaderWithStreamOutput,
	iCreatePixelShader,
	iCreateBlendState,
	iCreateDepthStencilState,
	iCreateRasterizerState,
	iCreateSamplerState,
	iCreateQuery,
	iCreatePredicate,
	iCreateCounter,
	iCheckFormatSupport,
	iCheckMultisampleQualityLevels,
	iCheckCounterInfo,
	iCheckCounter,
	iGetCreationFlags,
	iOpenSharedResource,
	iSetTextFilterSize,
	iGetTextFilterSize
};

class D3D10HOOK {
public:
	D3D10HOOK(HWND hWnd);
	~D3D10HOOK();
	void SetSwapChainHook(void* Func, SwapChainIndex index);
	void SetDeviceHook(void* Func, DeviceIndex index);
	void* GetOriginDeviceFunc(DeviceIndex index);
	void* GetOriginSwapChainFunc(SwapChainIndex index);
	bool GetHookStatus();

private:
	ID3D10Device * pDevice = NULL;
	IDXGISwapChain * pSwapChain = NULL;
	void** SwapChainVtable;
	void** DeviceVtable;
	bool initializedHook = false;
	void* oSwapChainFunc[17];
	void* oDeviceFunc[97];
};
