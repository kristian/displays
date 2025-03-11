#ifdef __linux__

#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARSE_NUMBER(str, var) var = strtol(strtok(str, delimiter), NULL, 10);

NAN_METHOD(GetDisplays) {
    v8::Local<v8::Array> displays = Nan::New<v8::Array>();

    FILE *fp;
    fp = popen("/usr/bin/env xrandr 2> /dev/null | grep -oE \"[0-9]+x[0-9]+\\+[0-9]+\\+[0-9]+\"", "r");
    if (!fp) {
        return Nan::ThrowError(Nan::New("Unable to get xrandr information, is X11 installed?").ToLocalChecked());
    }

    char rect[30]; // supports maximum resolutions of 99k+ x 99k+
    char delimiter[] = "x+";
    int width, height, left, top;
    while(fgets(rect, sizeof(rect) - 1, fp) != NULL) {
        PARSE_NUMBER(rect, width)
        PARSE_NUMBER(NULL, height)
        PARSE_NUMBER(NULL, left)
        PARSE_NUMBER(NULL, top)

        v8::Local<v8::Value> display = DisplayImpl::NewInstance(top, left, width, height);
        Nan::Set(displays, displays->Length(), display);
    }

    pclose(fp);

    info.GetReturnValue().Set(displays);
}

#endif