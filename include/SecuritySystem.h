/**
 * @file SecuritySystem.h
 * @brief Context class for Security System (Chain of Responsibility)
 * @version 5.0
 * @date 03/12/2025
 *
 * @authors
 * - 220201047: Security System - Chain of Responsibility Manager
 *
 * @patterns Chain of Responsibility, Facade (Subsystem)
 */

#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include "Alarm.h"
#include "Light.h"
#include <vector>

class SecuritySystem
{
private:
    Alarm *alarm;
    std::vector<Light *> *lights;

    bool isActive;

public:
    SecuritySystem(Alarm *alarm, std::vector<Light *> *lights);
    ~SecuritySystem();

    void activate();
    void deactivate();
    void handleMotionDetection();
    void displayStatus() const;
};

#endif // SECURITYSYSTEM_H