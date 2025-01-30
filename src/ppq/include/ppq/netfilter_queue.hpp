#pragma once
#include "ppq/netfilter_queue_handle.hpp"

#include <cstdint>
#include <memory>


enum QueueCopyMode : uint8_t {
	COPY_NONE = NFQNL_COPY_NONE,
	COPY_META = NFQNL_COPY_META,
	COPY_PACKET = NFQNL_COPY_PACKET
};

namespace kit::ppq
{
    class NetfilterQueue
    {
    public:
        NetfilterQueue() = default;
        ~NetfilterQueue();

        template <typename Callback>
        void bind(unsigned int queueNum, Callback &&callback)
        {
        }

        bool binded() const
        {

        }

        void setMode(QueueCopyMode mode);
        void setQueueMaxLen(uint32_t queuelen);

    protected:
        std::shared_ptr<NetfilterQueueHandler> handler;

        void setMode(QueueCopyMode mode, unsigned int packetLen);
        void setQueueFlags(uint32_t mask, uint32_t flags);

        virtual int netfilterCallback(struct nfq_q_handle *queue, struct nfgenmsg *nfmsg, struct nfq_data *nfad, void *data);
    };
}
