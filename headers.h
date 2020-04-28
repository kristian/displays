#ifndef DISPLAYS
#define DISPLAYS

#include <nan.h>

class Display : public Nan::ObjectWrap {
public:
    int top, left, width, height;
};

NAN_METHOD(GetDisplays);

class DisplayImpl : public Display {
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Value> NewInstance(int, int, int, int);
  static NAN_METHOD(New);

  DisplayImpl(int, int, int, int);

  static NAN_GETTER(GetTop);
  static NAN_GETTER(GetLeft);
  static NAN_GETTER(GetWidth);
  static NAN_GETTER(GetHeight);
};

#endif
