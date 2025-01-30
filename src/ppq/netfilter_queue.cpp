#include "ppq/netfilter_queue.hpp"

#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <linux/netfilter.h>

#include <libnetfilter_queue/pktbuff.h>
#include <libnetfilter_queue/libnetfilter_queue_ipv4.h>
#include <libnetfilter_queue/libnetfilter_queue_ipv6.h>
#include <libnetfilter_queue/libnetfilter_queue_tcp.h>
#include <libnetfilter_queue/libnetfilter_queue_udp.h>
#include <libnetfilter_queue/linux_nfnetlink_queue.h>

using namespace kit::ppq;
kit::ppq::NetfilterQueue::~NetfilterQueue()
{

}

void NetfilterQueue::setMode(QueueCopyMode mode)
{
    setMode(mode, 0xffff);
}

void NetfilterQueue::setQueueMaxLen(uint32_t queuelen)
{
    if(m_queue)
    {
        nfq_set_queue_maxlen(m_queue, queuelen);
    }
}

void NetfilterQueue::setMode(QueueCopyMode mode, unsigned int packetLen)
{
    if(m_queue)
    {
        nfq_set_mode(m_queue, static_cast<uint8_t>(mode), packetLen);
    }
}

void NetfilterQueue::setQueueFlags(uint32_t mask, uint32_t flags)
{
    if(handler && handler->m_queue)
    {
        nfq_set_queue_flags(handler->m_queue, mask, flags);
    }
}

int NetfilterQueue::netfilterCallback(nfq_q_handle *queue, nfgenmsg *nfmsg, nfq_data *nfqd, void *data)
{
    nfqnl_msg_packet_hdr *ph = nfq_get_msg_packet_hdr(nfqd);
    if (ph == nullptr)
    {
        //Issue while packet header
        return 0;
    }



    return nfq_set_verdict(queue, ntohl(ph->packet_id), NF_ACCEPT, pktb_len(pkBuff), pktb_data(pkBuff));;
}
