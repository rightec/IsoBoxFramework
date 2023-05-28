#ifndef ISO_PRINTDEBUG_H
#define ISO_PRINTDEBUG_H

#include <iostream>
#include <mutex>


extern std::mutex g_printMutex;

class ISO_printDebug
{
public:
    ISO_printDebug();

    static void printDebug(std::string _debugLine);

private:

};



#endif // ISO_PRINTDEBUG_H
