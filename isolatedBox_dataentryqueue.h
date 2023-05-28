#ifndef ISO_DATAENTRYQUEUE_H
#define ISO_DATAENTRYQUEUE_H

#include <list>
#include <map>
#include <mutex>
#include <string>
#include <iostream>
#include <thread>
#include <iostream>

#include "MonitoringTemp.h"

extern bool m_stopProducer;
extern bool m_stopConsumer;

class ISO_DataEntryQueue
{
public:

    ISO_DataEntryQueue(MonitoringDataQueue * _queue);

    void thread_producer();
    void thread_consumer();
    

    static bool getStopProducerFlag();
    static bool getStopConsumerFlag(); 
    static void setStopProducerFlag(bool _flag); 
    static void setStopConsumerFlag(bool _flag); 

private:
    std::mutex m_map_mutex;
    MonitoringDataQueue *m_DataQueue = nullptr;
    uint32_t m_counter = 0;


};


#endif // ISO_DATAENTRYQUEUE_H
