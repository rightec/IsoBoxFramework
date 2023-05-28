#include "isolatedBox_PID.h"

#ifdef ISO_PRINT_DEBUG
#include "isolatedBox_printdebug.h"
#endif // ISO_PRINT_DEBUG


 PidController::PidController()
     : m_parameterLimits(ISO_TEMP_MIN_SP, ISO_TEMP_MAX_SP, ISO_TEMP_SP_DEFAULT)
{
#ifdef ISO_PRINT_DEBUG
    ISO_printDebug::printDebug("InitializingP ID Controller");
#endif
    m_setPoint = 0.0;
    m_kp = 0.0;
    m_ki = 0.0;
    m_kd = 0.0;
    m_currentError = 0.0;

    init();
}


PidController::~PidController()
{
}

bool PidController::setPoints(temp_t _min, temp_t _max)
{
    bool lRetVal = false;
    if (setSetPoint(_min) == _min)
        if (setSetPoint(_max) == _max)
            lRetVal = true;
        else lRetVal = false;
    return lRetVal;
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

    timeProcess_t lret{};
    
    // TO IMPLEMENT

    return lret;
}

temp_t PidController::setSetPoint(const temp_t _input)
{
    m_setPoint = m_parameterLimits.validate(_input);
    return m_setPoint;
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
    temp_t lret{};

    // TO IMPLEMENT

    return lret;
}

temp_t PidController::getDerivative(const temp_t error) {
    temp_t lret{};

    // TO IMPLEMENT

    return lret;
}

timeProcess_t PidController::getTransferFnctn(const temp_t pTemp, const temp_t iTemp,
    const temp_t dTemp)
{
    timeProcess_t lret{};

    // TO IMPLEMENT

    return lret;

}
