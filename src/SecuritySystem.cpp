/**
 * @file SecuritySystem.cpp
 * @brief Implementation of Security System
 * @version 5.0
 * @date 03/12/2025
 *
 * @authors
 * - 220201047: Security System - Chain of Responsibility Manager
 *
 * @patterns Chain of Responsibility, Facade (Subsystem)
 */

#include "SecuritySystem.h"
#include "AlarmHandler.h"
#include <iostream>

SecuritySystem::SecuritySystem(Alarm *alarm, std::vector<Light *> *lights)
    : alarm(alarm), lights(lights), isActive(false)
{

    // Build the Chain of Responsibility: Alarm Only (Reduced chain)
    alarmHandler = new AlarmHandler(alarm);

    // Chain ends here for V3.5
}

SecuritySystem::~SecuritySystem()
{
    delete alarmHandler;
}

void SecuritySystem::activate()
{
    isActive = true;
    std::cout << "[SECURITY] Security system ACTIVATED." << std::endl;
}

void SecuritySystem::deactivate()
{
    isActive = false;
    std::cout << "[SECURITY] Security system DEACTIVATED." << std::endl;
}

void SecuritySystem::handleMotionDetection()
{
    if (!isActive)
        return;

    std::cout << "[SECURITY] Motion detected! Initiating security sequence..." << std::endl;

    // Start the chain
    alarmHandler->handleRequest();
}

void SecuritySystem::displayStatus() const
{
    std::cout << "--- SECURITY SYSTEM ---" << std::endl;
    std::cout << "  Status: " << (isActive ? "ARMED" : "DISARMED") << std::endl;
    std::cout << "  Chain: Alarm Only" << std::endl;
}