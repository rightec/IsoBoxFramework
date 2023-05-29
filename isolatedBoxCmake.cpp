/*****************************************************************//**
 * \file   isolatedBoxCmake.cpp
 * \brief: Main API class to manage a temperature controller
 * on a target device called "Box"
 *
 * \author F.Morani
 * \date   May 2023
***********************************************************************/

#include "isolatedBoxCmake.h"

using namespace isoBoxApi;


isoBox::isoBox()
{
    m_max_interval_temp = ISO_DEF_UNDEF_TEMP;
    m_min_interval_temp = ISO_DEF_UNDEF_TEMP;
    m_treshold_cmp_temp = ISO_DEF_TRSH__CMP_TEMP;
    m_Box_temp = ISO_DEF_UNDEF_TEMP;
    m_initDone = false;
}


bool isoBox::init(temp_t _min, temp_t _max)
{
    bool l_retVal = false;
    if (_max > _min) {
        /// <summary>
        /// PID has 2 set points. One for max and on for min
        /// </summary>
        /// <param name="_min"></param>
        /// <param name="_max"></param>
        /// <returns></returns>
        l_retVal = m_pidActuator.setPoints(_min, _max);   // init();
        m_initDone = l_retVal;
        return l_retVal;
    }
    else
        return l_retVal;
}
float isoBoxApi::isoBox::applyCompensation(float _temp)
{   
    /// If it is out of range we should apply compensentaion
    
    /// <summary>
    /// Here cames the measured temperature
    /// First we set the m_Box_temp to store the measured value
    /// </summary>
    /// <param name="_temp"></param>
    /// <returns></returns>
    m_Box_temp = _temp;

    
    return _temp;  
}


