#pragma once
#include <cstdint>

extern "C"
{
#include <linux/netfilter.h>
#include <libnetfilter_queue/libnetfilter_queue.h>
}

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
        NetfilterQueue();
        ~NetfilterQueue();

        template <typename Callback>
        void bind(unsigned int queueNum, Callback &&callback)
        {
        }

        void setMode(QueueCopyMode mode);
        void setQueueMaxLen(uint32_t queuelen);
    protected:
        nfq_handle *m_handle;
        nfq_q_handle *m_queue;

        void setMode(QueueCopyMode mode, unsigned int packetLen);
        void setQueueFlags(uint32_t mask, uint32_t flags);
    };
}
