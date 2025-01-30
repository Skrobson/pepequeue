#include "ppq/netfilter_queue_handle.hpp"

NetfilterQueueHandler::NetfilterQueueHandler(PrivateTag)
{

}

NetfilterQueueHandler::~NetfilterQueueHandler()
{
    if(m_queue)
    {
        nfq_destroy_queue(m_queue);
    }
    if(m_handle)
    {
        nfq_close(m_handle);
    }
}
