#include "isolatedBox_printdebug.h"


std::mutex g_printMutex;

ISO_printDebug::ISO_printDebug()
{


}


void ISO_printDebug::printDebug(std::string _debugLine)
{
    std::lock_guard<std::mutex> guard(g_printMutex);
    std::cout << _debugLine << std::endl;
}
