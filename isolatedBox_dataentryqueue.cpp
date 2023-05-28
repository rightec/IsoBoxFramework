#include "isolatedBox_dataentryqueue.h"
#include "isolatedBox_printdebug.h"

static bool m_stopProducer;
static bool m_stopConsumer;

ISO_DataEntryQueue::ISO_DataEntryQueue(MonitoringDataQueue * _queue)
{
    m_DataQueue = _queue;

    if (m_DataQueue != nullptr)
        m_DataQueue->clear(); // Clear the list
}


void ISO_DataEntryQueue::thread_producer()
{

     ISO_printDebug::printDebug("ISO_DataEntryQueue::thread_producer");

    /// The thread keeps working if the flag is true

    while (m_stopProducer == true){
        

        /// Getting timestamp
        const auto p1 = std::chrono::system_clock::now();
        auto l_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
                               p1.time_since_epoch()).count();
        std::string l_timestamp = std::to_string(l_milliseconds);

        std::string l_output = "ISO_DataEntryQueue::thread_producer: TimeStamp - seconds since epoch: "
                  + l_timestamp;

        ISO_printDebug::printDebug(l_output);

        
        for (int i = 0; i < 100; i++) {
            // Insert record in the list

            /// Preparing data Monitor
            MonitoringTemp l_msgData;
            int l_val = i; //  rand();

            std::string l_valueStn = std::to_string(l_val);
            std::string l_type = "Celsius";

            insert(l_msgData, l_valueStn, l_type);

            std::string l_output;
            l_output = "ISO_DataEntryQueue::thread_producer: Add pair: Temp is: " + l_valueStn +
                " " + l_type;
            ISO_printDebug::printDebug(l_output);

            if (m_DataQueue != nullptr)
                m_DataQueue->push(l_msgData);
            m_counter++;

            std::this_thread::sleep_for(std::chrono::seconds(1));
        } // end for

    } // end while
}


void ISO_DataEntryQueue::thread_consumer()
{
    if (m_DataQueue != nullptr){

        ISO_printDebug::printDebug("ISO_DataEntryQueue::thread_consumer");
        /// The thread keeps working if the flag is true
    
        while (m_stopConsumer == true){
                if (m_DataQueue->size() > 0) {
                    /// Checking the list - Remove and process the first element

                    MonitoringTemp l_monData = m_DataQueue->pop();

                    std::string l_output = "ISO_DataEntryQueue::thread_consumer Element retrieved "
                        + l_monData.first + " " + l_monData.second;
                    ISO_printDebug::printDebug(l_output);


                    const auto p1 = std::chrono::system_clock::now();
                    l_output =  "ISO_DataEntryQueue::thread_consumer: TimeStamp - seconds since epoch: "
                            + std::to_string(std::chrono::duration_cast<std::chrono::seconds>(
                                                 p1.time_since_epoch()).count());
                    ISO_printDebug::printDebug(l_output);

                    std::this_thread::sleep_for(std::chrono::seconds(1));
                } // else
            
        } // while
    } else {
        ISO_printDebug::printDebug("ISO_DataEntryQueue::thread_consumer: could not start ");
    }

}

bool ISO_DataEntryQueue::getStopProducerFlag()
{
    return m_stopProducer;
}

bool ISO_DataEntryQueue::getStopConsumerFlag()
{
    return m_stopConsumer;
}

void ISO_DataEntryQueue::setStopProducerFlag(bool _flag)
{
    m_stopProducer = _flag;
}

void ISO_DataEntryQueue::setStopConsumerFlag(bool _flag)
{
    m_stopConsumer = _flag;
}

