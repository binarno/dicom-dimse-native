#pragma once
#include <napi.h>

using namespace Napi;

template<class T>
class ServerAsyncWorker : public AsyncProgressWorker<T>
{
    public:
        ServerAsyncWorker(const Function &callback);

        void Execute(const ExecutionProgress& progress);

        void OnOK();

        void OnProgress(const T* data, size_t count);

    private:
    std::string _input;
    std::string _output;
};
#include "ServerAsyncWorker.cpp"