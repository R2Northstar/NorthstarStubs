#pragma once

#include "dxgi_object.h"

namespace dxvk {

  class DxgiFactory : public DxgiObject<IDXGIFactory7> {

  public:

    DxgiFactory(UINT Flags);
    ~DxgiFactory();

    HRESULT STDMETHODCALLTYPE QueryInterface(
            REFIID                riid,
            void**                ppvObject) final;

    HRESULT STDMETHODCALLTYPE GetParent(
            REFIID                riid,
            void**                ppParent) final;

    BOOL STDMETHODCALLTYPE IsWindowedStereoEnabled() final;

    HRESULT STDMETHODCALLTYPE CreateSoftwareAdapter(
            HMODULE               Module,
            IDXGIAdapter**        ppAdapter) final;

    HRESULT STDMETHODCALLTYPE CreateSwapChain(
            IUnknown*             pDevice,
            DXGI_SWAP_CHAIN_DESC* pDesc,
            IDXGISwapChain**      ppSwapChain) final;

    HRESULT STDMETHODCALLTYPE CreateSwapChainForHwnd(
            IUnknown*             pDevice,
            HWND                  hWnd,
      const DXGI_SWAP_CHAIN_DESC1* pDesc,
      const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
            IDXGIOutput*          pRestrictToOutput,
            IDXGISwapChain1**     ppSwapChain) final;

    HRESULT STDMETHODCALLTYPE CreateSwapChainForCoreWindow(
            IUnknown*             pDevice,
            IUnknown*             pWindow,
      const DXGI_SWAP_CHAIN_DESC1* pDesc,
            IDXGIOutput*          pRestrictToOutput,
            IDXGISwapChain1**     ppSwapChain) final;

    HRESULT STDMETHODCALLTYPE CreateSwapChainForComposition(
            IUnknown*             pDevice,
      const DXGI_SWAP_CHAIN_DESC1* pDesc,
            IDXGIOutput*          pRestrictToOutput,
            IDXGISwapChain1**     ppSwapChain) final;

    HRESULT STDMETHODCALLTYPE EnumAdapters(
            UINT                  Adapter,
            IDXGIAdapter**        ppAdapter) final;

    HRESULT STDMETHODCALLTYPE EnumAdapters1(
            UINT                  Adapter,
            IDXGIAdapter1**       ppAdapter) final;

    HRESULT STDMETHODCALLTYPE EnumAdapterByLuid(
            LUID                  AdapterLuid,
            REFIID                riid,
            void**                ppvAdapter) final;

    HRESULT STDMETHODCALLTYPE EnumAdapterByGpuPreference(
            UINT                  Adapter,
            DXGI_GPU_PREFERENCE   GpuPreference,
            REFIID                riid,
            void**                ppvAdapter);

    HRESULT STDMETHODCALLTYPE EnumWarpAdapter(
            REFIID                riid,
            void**                ppvAdapter) final;

    HRESULT STDMETHODCALLTYPE GetWindowAssociation(
            HWND*                 pWindowHandle) final;

    HRESULT STDMETHODCALLTYPE GetSharedResourceAdapterLuid(
            HANDLE                hResource,
            LUID*                 pLuid) final;

    HRESULT STDMETHODCALLTYPE MakeWindowAssociation(
            HWND                  WindowHandle,
            UINT                  Flags) final;

    BOOL STDMETHODCALLTYPE IsCurrent() final;

    HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusWindow(
            HWND                  WindowHandle,
            UINT                  wMsg,
            DWORD*                pdwCookie) final;

    HRESULT STDMETHODCALLTYPE RegisterStereoStatusEvent(
            HANDLE                hEvent,
            DWORD*                pdwCookie) final;

    HRESULT STDMETHODCALLTYPE RegisterStereoStatusWindow(
            HWND                  WindowHandle,
            UINT                  wMsg,
            DWORD*                pdwCookie) final;

    HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusEvent(
            HANDLE                hEvent,
            DWORD*                pdwCookie) final;

    void STDMETHODCALLTYPE UnregisterStereoStatus(
            DWORD                 dwCookie) final;

    void STDMETHODCALLTYPE UnregisterOcclusionStatus(
            DWORD                 dwCookie) final;

    UINT STDMETHODCALLTYPE GetCreationFlags() final;

    HRESULT STDMETHODCALLTYPE CheckFeatureSupport(
            DXGI_FEATURE          Feature,
            void*                 pFeatureSupportData,
            UINT                  FeatureSupportDataSize) final;

    HRESULT STDMETHODCALLTYPE RegisterAdaptersChangedEvent(
            HANDLE                hEvent,
            DWORD*                pdwCookie);

    HRESULT STDMETHODCALLTYPE UnregisterAdaptersChangedEvent(
            DWORD                 Cookie);

  private:

    UINT             m_flags;

  };

}
