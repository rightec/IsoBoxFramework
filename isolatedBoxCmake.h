/*****************************************************************//**
 * \file   isolatedBoxCmake.h
 * \brief: Main API class to manage a temperature controller
 * on a target device called "Box"
 *
 * \author F.Morani
 * \date   May 2023
***********************************************************************/
#ifndef  _ISO_BOX_CMAKE_H
#define  _ISO_BOX_CMAKE_H

#include <iostream>
#include "isolatedBox_PID.h"  // include class to manage actuation

constexpr auto ISO_DEF_UNDEF_TEMP = 65535;
constexpr auto ISO_DEF_TRSH__CMP_TEMP = 0.1;

using namespace std;

namespace isoBoxApi {

class isoBox {
public:
    isoBox() {
        // Performing all initialization
        m_max_interval_temp = ISO_DEF_UNDEF_TEMP;
        m_min_interval_temp = ISO_DEF_UNDEF_TEMP;
        m_treshold_cmp_temp = ISO_DEF_TRSH__CMP_TEMP;
        m_Box_temp = ISO_DEF_UNDEF_TEMP;
        m_initDone = false;
    }

    bool init(temp_t _min, temp_t _max) {
        bool l_retVal = false;
        if (_max > _min) {
            l_retVal = m_pidActuator.init();
            m_initDone = l_retVal;
            return l_retVal;
        }
        else
            return l_retVal;
    }

    bool getInitDone() { return m_initDone; };

    /**
    * Set the sample class name.
    *
    * \param float _temp The current value of 
    * \return a sample return value
    */
    float applyCompensation(float _temp)
    {
        /// Here cames the measured temperature
        /// If it is out of range we should apply compensentaion
        /// 
    }
private:
    temp_t m_max_interval_temp;
    temp_t m_min_interval_temp;
    temp_t m_treshold_cmp_temp;
    temp_t m_Box_temp;
    bool  m_initDone;
    PidController m_pidActuator;
};

};
#endif // !_ISO_BOX_CMAKE_H