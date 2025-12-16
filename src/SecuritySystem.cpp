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
#include <iostream>

SecuritySystem::SecuritySystem(Alarm *alarm, std::vector<Light *> *lights)
    : alarm(alarm), lights(lights), isActive(false)
{
    // Chain of Responsibility removed in V3.2
    // Direct association used instead
}

SecuritySystem::~SecuritySystem()
{
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

    // Direct action
    if (alarm)
    {
        std::cout << "[SECURITY] Triggering Alarm directly..." << std::endl;
        alarm->ring();
    }
}

void SecuritySystem::displayStatus() const
{
    std::cout << "--- SECURITY SYSTEM ---" << std::endl;
    std::cout << "  Status: " << (isActive ? "ARMED" : "DISARMED") << std::endl;
    std::cout << "  Architecture: Direct Call (No Chain)" << std::endl;
}