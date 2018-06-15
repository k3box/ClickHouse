#pragma once
#include "../Common/ConcurrentBoundedQueue.h"
#include "../Core/Block.h"


namespace DB
{

class InternalTextLogsQueue : public ConcurrentBoundedQueue<MutableColumns>
{
public:
    /// You should not push logs in the queue if their priority greater max_priority
    int max_priority;

    InternalTextLogsQueue();

    static Block getSampleBlock();
    static MutableColumns getSampleColumns();

    /// Converts priority from Poco::Message::Priority to a string
    static const char * getPriorityName(int priority);
};

using InternalTextLogsQueuePtr = std::shared_ptr<InternalTextLogsQueue>;

}


