#ifdef __APPLE__

#include "headers.h"
#include <ApplicationServices/ApplicationServices.h>

NAN_METHOD(GetDisplays) {
    v8::Local<v8::Array> displays = Nan::New<v8::Array>();

    uint32_t dspyCnt;
    CGError cgret = CGGetActiveDisplayList(0, NULL, &dspyCnt);
    if (kCGErrorSuccess != cgret) {
        return Nan::ThrowError(Nan::New("Failed to determine active display count").ToLocalChecked());
    }

    std::vector<CGDirectDisplayID> dspys(dspyCnt);
    cgret = CGGetActiveDisplayList(dspyCnt, dspys.begin().base(), &dspyCnt);
    if (kCGErrorSuccess != cgret) {
        return Nan::ThrowError(Nan::New("Failed to list active displays").ToLocalChecked());
    }

    for(uint32_t dspyIdx=0; dspyIdx < dspyCnt; dspyIdx++) {
        CGRect dspyRect = CGDisplayBounds(dspys[dspyIdx]);

        v8::Local<v8::Value> display = DisplayImpl::NewInstance(
            dspyRect.origin.y, dspyRect.origin.x,
            dspyRect.size.width, dspyRect.size.height
        );
        Nan::Set(displays, displays->Length(), display);
    }

    info.GetReturnValue().Set(displays);
}

#endif