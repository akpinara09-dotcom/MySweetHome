#ifndef DEVICEFACTORY_H
#define DEVICEFACTORY_H

#include "Device.h"
#include "Light.h"
#include "Camera.h"
#include "Television.h"
#include "SmokeDetector.h"
#include "GasDetector.h"
#include "SoundSystem.h"
#include <string>

// Abstract Factory Pattern for creating device families
class DeviceFactory {
public:
    virtual ~DeviceFactory() {}
    virtual Light* createLight() = 0;
    virtual Camera* createCamera() = 0;
    virtual Television* createTV() = 0;
    virtual SoundSystem* createSoundSystem() = 0;
};

// Concrete Factory - Samsung Family
class SamsungFactory : public DeviceFactory {
public:
    virtual Light* createLight();
    virtual Camera* createCamera();
    virtual Television* createTV();
    virtual SoundSystem* createSoundSystem();
};

// Concrete Factory - Premium Brand Mix (Philips, Xiaomi, LG, Sonos)
class PremiumFactory : public DeviceFactory {
public:
    virtual Light* createLight();
    virtual Camera* createCamera();
    virtual Television* createTV();
    virtual SoundSystem* createSoundSystem();
};

// Abstract Factory for Detector System (Smoke + Gas sold together)
class DetectorFactory {
public:
    virtual ~DetectorFactory() {}
    virtual SmokeDetector* createSmokeDetector() = 0;
    virtual GasDetector* createGasDetector() = 0;
};

// Concrete Detector Factory - Nest Family
class NestDetectorFactory : public DetectorFactory {
public:
    virtual SmokeDetector* createSmokeDetector();
    virtual GasDetector* createGasDetector();
};

// Concrete Detector Factory - Budget Family
class BudgetDetectorFactory : public DetectorFactory {
public:
    virtual SmokeDetector* createSmokeDetector();
    virtual GasDetector* createGasDetector();
};

// Factory Method Pattern - Simple device creation
class SimpleDeviceFactory {
public:
    enum DeviceType {
        LIGHT_PHILIPS,
        LIGHT_IKEA,
        CAMERA_SAMSUNG,
        CAMERA_XIAOMI,
        TV_SAMSUNG,
        TV_LG,
        SOUND_SONOS,
        SOUND_BOSE,
        SMOKE_NEST,
        SMOKE_FIRSTALERT,
        GAS_NEST,
        GAS_KIDDE
    };
    
    static Device* createDevice(DeviceType type);
    static Device* createDeviceByInput(char deviceChar, int brandChoice);
};

#endif // DEVICEFACTORY_H
