#ifndef ServerAsyncWorker_h
#define ServerAsyncWorker_h

#include "ServerAsyncWorker.h"


template<class T>
ServerAsyncWorker<T>::ServerAsyncWorker(const Function &callback) : AsyncProgressWorker<T>(callback)
{
}

template<class T>
void ServerAsyncWorker<T>::Execute(const ExecutionProgress& progress)
{
        progress.Send(reinterpret_cast<const T*>(5), 1);
}

template<class T>
void ServerAsyncWorker<T>::OnOK()
{
        String output = String::New(Env(), _output);
        Callback().Call({output});
}

template<class T>
void ServerAsyncWorker<T>::OnProgress(const T* data, size_t count)
{

}

#endif