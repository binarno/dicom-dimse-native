#include <napi.h>

using namespace Napi;

template<class T>
class ServerAsyncWorker : public AsyncProgressWorker
{
    public:
        ServerAsyncWorker(std::string data, Function &callback);

        void Execute(const ExecutionProgress& progress);

        void OnOK();

    private:
    std::string _input;
    std::string _output;
};
