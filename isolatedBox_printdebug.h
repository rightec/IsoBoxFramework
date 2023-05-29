/*****************************************************************//**
 * \file   isolatedBox_printdebug.h
 * \brief: Class to manahge standard output message
 * \author F.Morani
 * \date   May 2023
***********************************************************************/
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
