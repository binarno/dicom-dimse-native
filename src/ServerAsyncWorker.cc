#include "ServerAsyncWorker.h"

#include <chrono>
#include <thread>

ServerAsyncWorker::ServerAsyncWorker(const Function &callback) : AsyncProgressWorker(callback)
{
        echo = "this is it";
}

void ServerAsyncWorker::Execute(const ExecutionProgress& progress)
{
        // Need to simulate cpu heavy task
        for (uint32_t i = 0; i < 100; ++i) {
          progress.Send(&i, 1);
          // std::this_thread::sleep_for(std::chrono::seconds(1));
        }
}

void ServerAsyncWorker::OnOK()
{
        // HandleScope scope(Env());
        // Callback().Call({Env().Null(), String::New(Env(), echo)});
        String output = String::New(Env(), echo);
        Callback().Call({output});
}

void ServerAsyncWorker::OnProgress(const uint32_t* data, size_t count)
{
    // HandleScope scope(Env());
    // Callback().Call({Env().Null(), Env().Null(), Number::New(Env(), *data)});

     Number output = Number::New(Env(), *data);
     Callback().Call({output});

}
