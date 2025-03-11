#include "headers.h"

static Nan::Persistent<v8::FunctionTemplate> display_constructor;

DisplayImpl::DisplayImpl(int top, int left, int width, int height) {
  this->top = top;
  this->left = left;
  this->width = width;
  this->height = height;
}

NAN_MODULE_INIT(DisplayImpl::Init) {
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(DisplayImpl::New);
  display_constructor.Reset(tpl);
  tpl->SetClassName(Nan::New("Display").ToLocalChecked());

  v8::Local<v8::ObjectTemplate> itpl = tpl->InstanceTemplate();
  itpl->SetInternalFieldCount(1);

  Nan::SetAccessor(itpl, Nan::New("height").ToLocalChecked(), DisplayImpl::GetHeight);
  Nan::SetAccessor(itpl, Nan::New("width").ToLocalChecked(), DisplayImpl::GetWidth);
  Nan::SetAccessor(itpl, Nan::New("left").ToLocalChecked(), DisplayImpl::GetLeft);
  Nan::SetAccessor(itpl, Nan::New("top").ToLocalChecked(), DisplayImpl::GetTop);  

  Nan::Set(target, Nan::New("get").ToLocalChecked(), Nan::GetFunction(
    Nan::New<v8::FunctionTemplate>(GetDisplays)).ToLocalChecked());
}

v8::Local<v8::Value> DisplayImpl::NewInstance(int top, int left, int width, int height) {
  const int argc = 4;
  v8::Local<v8::Value> argv[argc] = {
    Nan::New(top), Nan::New(left),
    Nan::New(width), Nan::New(height)
  };

  Nan::EscapableHandleScope scope;
  v8::Local<v8::Object> instance = Nan::NewInstance(Nan::GetFunction(
    Nan::New(display_constructor)).ToLocalChecked(), argc, argv).ToLocalChecked();
  return scope.Escape(instance);
}

NAN_METHOD(DisplayImpl::New) {
  DisplayImpl* display = new DisplayImpl(
    Nan::To<int>(info[0]).FromJust(), Nan::To<int>(info[1]).FromJust(),
    Nan::To<int>(info[2]).FromJust(), Nan::To<int>(info[3]).FromJust()
  );
  display->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

#define PROPERTY_GETTER(name, property)                                        \
    NAN_GETTER(DisplayImpl::name) {                                            \
      Display* self = Nan::ObjectWrap::Unwrap<Display>(info.This())  ;         \
      info.GetReturnValue().Set(Nan::New(self->property));                     \
    }

PROPERTY_GETTER(GetTop, top)
PROPERTY_GETTER(GetLeft, left)
PROPERTY_GETTER(GetWidth, width)
PROPERTY_GETTER(GetHeight, height)

NODE_MODULE(displays, DisplayImpl::Init)