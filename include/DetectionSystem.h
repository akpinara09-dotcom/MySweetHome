/**
 * @file DetectionSystem.h
 * @brief Detection System handling smoke and gas detectors
 * @version 5.0
 * @date 03/12/2025
 * 
 * @authors
 * - 210201856: Detection System - Chain of Responsibility, Observer (Smoke/Gas)
 * 
 * @patterns Chain of Responsibility, Observer
 */

#ifndef DETECTIONSYSTEM_H
#define DETECTIONSYSTEM_H

#include <vector>
#include "Alarm.h"
#include "Light.h"

class DetectionSystem {
private:
    Alarm* alarm;
    std::vector<Light*>* lights;
    
public:
    DetectionSystem(Alarm* alarm, std::vector<Light*>* lights);
    ~DetectionSystem();
    
    void activate();
    void deactivate();
    
    void handleSmokeDetection();
    void handleGasDetection();
    void displayStatus() const;
};

#endif // DETECTIONSYSTEM_H
