#pragma once

#include <cstdint>
#include <memory>

extern "C"
{
#include <libnetfilter_queue/libnetfilter_queue.h>
}

namespace kit::ppq
{
    class NetfilterQueueHandler
    {
        struct PrivateTag{} ;

    public:
        NetfilterQueueHandler(PrivateTag);
        ~NetfilterQueueHandler();

        //todo: pass callback, number, etc
        static std::unique_ptr<NetfilterQueueHandler> create():

    private:
        nfq_handle *m_handle;
        nfq_q_handle *m_queue;
    };
}
