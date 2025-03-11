
#ifdef WIN32

#include "headers.h"
#include <windows.h>

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
  v8::Local<v8::Value> display = DisplayImpl::NewInstance(
    lprcMonitor->top, lprcMonitor->left, 
    lprcMonitor->right - lprcMonitor->left, 
    lprcMonitor->bottom - lprcMonitor->top
  );
  
  v8::Local<v8::Array> displays =  *((v8::Local<v8::Array> *)dwData);
  Nan::Set(displays, displays->Length(), display);
  
  return TRUE;
}

NAN_METHOD(GetDisplays) {
    v8::Local<v8::Array> displays = Nan::New<v8::Array>();

    EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, (LPARAM)&displays);

    info.GetReturnValue().Set(displays);
}

#endif