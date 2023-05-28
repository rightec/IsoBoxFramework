#include "isolatedBox_PID.h"
#include "isolatedBox_printdebug.h"

PidController::PidController()
    : m_parameterLimits(ISO_TEMP_MAX_SP, ISO_TEMP_MIN_SP, ISO_TEMP_SP_DEFAULT)
{
    ISO_printDebug::printDebug("InitializingP ID Controller");
}

bool PidController::init()
{
    bool l_retVal = false;

    l_retVal = m_pwmActuator.init();
    /// <other_init>
    /// if needed we can set
    /// m_pwmActuator.setDutyCycle(...);
    /// m_pwmActuator.setFrequency(...);
    /// m_pwmActuator.setIntensity(...);
    /// </other_init>
    return l_retVal;
}

timeProcess_t PidController::Process(const temp_t _current) {
    // TO DO

    timeProcess_t lret;
    
    // TO IMPLEMENT

    return lret;
}

void PidController::setSetPoint(const temp_t _input)
{
    m_setPoint = m_parameterLimits.validate(_input);
}

temp_t PidController::getSetPoint() const 
{ 
    return m_setPoint; 
}

void PidController::setKp(const temp_t _input)
{
    m_kp = m_parameterLimits.validate(_input);
}

temp_t PidController::getKp() const 
{ 
    return m_kp; 
}

void PidController::setKi(const temp_t _input)
{
    m_ki = m_parameterLimits.validate(_input);
}

temp_t PidController::getKi() const { return m_ki; }

void PidController::setKd(const temp_t _input)
{
    m_kd = m_parameterLimits.validate(_input);
}

temp_t PidController::getKd() const { return m_kd; }

temp_t PidController::getError(const temp_t _current)
{
    return m_currentError;
}

temp_t PidController::getProportional(const temp_t error)
{
    temp_t lret = m_kp;

    return lret;
}

temp_t PidController::getIntegral(const temp_t _error) {
    temp_t lret;

    // TO IMPLEMENT

    return lret;
}

temp_t PidController::getDerivative(const temp_t error) {
    temp_t lret;

    // TO IMPLEMENT

    return lret;
}

timeProcess_t PidController::getTransferFnctn(const temp_t pTemp, const temp_t iTemp,
    const temp_t dTemp)
{
    timeProcess_t lret;

    // TO IMPLEMENT

    return lret;

}