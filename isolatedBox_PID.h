/*****************************************************************//**
 * \file   isolatedBox_PID.h
 * \brief: Class to manage a generic PID using 
 *  PWM modulation as actuation
 *
 * \author F.Morani
 * \date   May 2023
***********************************************************************/
#ifndef _ISOLATED_PID_H
#define _ISOLATED_PID_H

#include "isolatedBox_common.h"
#include "isolatedBox_actuator.h"

/**
 * @brief Pid Processor 
 */
class PidController
{

public:
    /**
     * @brief Construct a new Pid Processor object
     */
    PidController();

    /**
     * @brief Destroy the Pid Processor object
     */
     ~PidController();

    /**
     * @brief Initilize PID loop
     *
     * @return true success
     * @return false fail
     */
     bool init();


     bool setPoints(temp_t _min, temp_t _max);

    /**
     * @brief
     *
     * @param current
     * @return timeProcess_t
     */
     timeProcess_t Process(const temp_t current);


    /**
     * @brief Set the process temperature set point in degrees ºC
     * Min/Max:
     */
     temp_t setSetPoint(const temp_t _setpoint);

    /**
     * @brief Get the process temperature set point
     *
     * @return temp_t
     */
     temp_t getSetPoint() const;

    /**
     * @brief Set the proportional gain
     * Min/Max:
     *
     */
     void setKp(const temp_t _k);

    /**
     * @brief Get the proportional gain
     *
     * @return temp_t
     */
     temp_t getKp() const;

    /**
     * @brief Set the integral gain
     * Min/Max:
     *
     */
     void setKi(const temp_t);

    /**
     * @brief Get the integral gain
     *
     * @return temp_t
     */
     temp_t getKi() const;

    /**
     * @brief Set the derivative gain
     * Min/Max:
     *
     */
     void setKd(const temp_t);

    /**
     * @brief Get the derivative gain
     *
     * @return temp_t
     */
     temp_t getKd() const;

private:
    /**
    * @brief The PWM class that manages actuation
    */
    IsoActuator m_pwmActuator;

    /**
     * @brief The set point is the desired process value.     *
     */
    temp_t m_setPoint;

    /**
     * @brief Proportional gain
     * Min / Max: 20ºC / 100ºC
     */
    temp_t m_kp;

    /**
     * @brief Integral gain
     * Min / Max: 20ºC / 100ºC
     */
    temp_t m_ki;

    /**
     * @brief Derivative gain
     * Min / Max: 20ºC / 100ºC
     */
    temp_t m_kd;

    /**
     * @brief Current temperature deviation from the set point
     */
    temp_t m_currentError;

    /**
     * @brief Setpoint limits
     *
     */
    ParameterLimits m_parameterLimits;

    /**
     * @brief Get temperature error
     *
     * @param current - current temperature T2
     * @return temp_t - temperature error e(t)
     */
    temp_t getError(const temp_t _current);

    /**
     * @brief Get the proportional adjustment
     *
     * @param error - temperature error e(t)
     * @return temp_t - Proportional temperature adjustment
     */
    temp_t getProportional(const temp_t _error);

    /**
     * @brief Get the integral adjustment
     *
     * @param error - temperature error e(t)
     * @return temp_t - Integral temperature adjustment
     */
    temp_t getIntegral(const temp_t _error);

    /**
     * @brief Get the Derivative object
     *
     * @param error - temperature error e(t)
     * @return temp_t - Derivative temperature adjustment
     */
    temp_t getDerivative(const temp_t _error);

    /**
     * @brief Get the transfer function result
     *
     * @param pTemp - Proportional adjustment
     * @param iTemp - Integral adjustment
     * @param dTemp - Derivative adjustment
     * @return timeProcess_t
     */
    timeProcess_t getTransferFnctn(const temp_t _pTemp, const temp_t _iTemp,
       const temp_t _dTemp);
};


#endif // _ISOLATED_PID_H