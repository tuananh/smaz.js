#include <node.h>
#include <node_buffer.h>

#include "nan.h"

extern "C" {
#include "smaz/smaz.h"
}

NAN_METHOD(compress)
{
    Nan::HandleScope();

    const v8::Local<v8::Object> input = info[0].As<v8::Object>();
    const size_t inlen = node::Buffer::Length(input);
    const size_t maxoutlen = inlen * 1.5; // threshold

    char* output = new char[maxoutlen];
    size_t outlen = smaz_compress(node::Buffer::Data(input), inlen,
        output, maxoutlen);

    if (maxoutlen > outlen) {
        info.GetReturnValue().Set(
            Nan::CopyBuffer(output, outlen).ToLocalChecked());
        delete[] output;
    } else {
        delete[] output;
        Nan::ThrowError(
            "Memory allocated for compressed result was shorter than necessary");
    }
}

NAN_METHOD(decompress)
{
    Nan::HandleScope();

    const v8::Local<v8::Object> input = info[0].As<v8::Object>();
    const size_t inlen = node::Buffer::Length(input);
    const size_t maxoutlen = inlen * 3;

    char* output = new char[maxoutlen];
    size_t outlen = smaz_decompress(node::Buffer::Data(input), inlen,
        output, maxoutlen);

    if (maxoutlen > outlen) {
        info.GetReturnValue().Set(
            Nan::CopyBuffer(output, outlen).ToLocalChecked());
        delete[] output;
    } else {
        delete[] output;
        Nan::ThrowError(
            "Memory allocated for decompressed result was shorter than necessary");
    }
}

NAN_MODULE_INIT(init)
{
    Nan::Set(target, Nan::New("compress").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(compress))
            .ToLocalChecked());
    Nan::Set(target, Nan::New("decompress").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(decompress))
            .ToLocalChecked());
}

NODE_MODULE(node_smaz, init)
