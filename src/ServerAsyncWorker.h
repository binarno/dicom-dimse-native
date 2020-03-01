#pragma once
#include <napi.h>

using namespace Napi;

class ServerAsyncWorker : public AsyncProgressWorker<uint32_t>
{
    public:
        ServerAsyncWorker(const Function &callback);

        void Execute(const ExecutionProgress& progress);

        void OnOK();

        void OnProgress(const uint32_t* data, size_t /* count */);

    private:
    std::string echo;
};
