/*****************************************************************//**
 * \file   isolatedBox_dataentryqueue.h
 * \brief: Class that simulates a serialization
 * of value coming from a temperature sensor
 * The thread producer simulates the reading from a 
 * sensor and put them in a queue.
 * The thread consumer takes the value from the queue and 
 * it keeps the compensation process going
 *
 * \author F.Morani
 * \date   May 2023
***********************************************************************/

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
#include "isolatedBoxCmake.h"

extern bool m_stopProducer;
extern bool m_stopConsumer;

using namespace isoBoxApi;

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
    isoBox l_IsoBox;


};


#endif // ISO_DATAENTRYQUEUE_H
