#include <iostream>
#include <string>
#include <vector>

// Include all component headers
#include "../include/Light.h"
#include "../include/Camera.h"
#include "../include/Television.h"
#include "../include/SmokeDetector.h"
#include "../include/GasDetector.h"
#include "../include/SoundSystem.h"
#include "../include/Alarm.h"
#include "../include/SecuritySystem.h"
#include "../include/ModeManager.h"
#include "../include/DeviceFactory.h"

// Simple Test Framework
int totalTests = 0;
int passedTests = 0;

typedef bool (*TestFunction)();

void runTest(const std::string& testName, TestFunction testFunc) {
    totalTests++;
    std::cout << "Running " << testName << "... ";
    try {
        if (testFunc()) {
            std::cout << "PASSED" << std::endl;
            passedTests++;
        } else {
            std::cout << "FAILED" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "FAILED (Exception: " << e.what() << ")" << std::endl;
    } catch (...) {
        std::cout << "FAILED (Unknown Exception)" << std::endl;
    }
}

// --- Component Tests ---

// 1. Light Tests
bool testLightInit() {
    PhilipsHueLight light;
    if (light.getBrand() != "Philips") return false;
    if (light.getDeviceType() != "Light") return false;
    return true;
}

// 2. Camera Tests
bool testCameraInit() {
    SamsungCamera cam;
    if (cam.getBrand() != "Samsung") return false;
    if (cam.getDeviceType() != "Camera") return false;
    // Assuming default state is not recording (implementation dependent, but standard is safe)
    // Based on header: bool isRecording;
    // We can't access protected members directly unless there is a getter.
    // There is no explicit isRecording() getter in base, but let's check basic properties.
    return true;
}

// 3. Television Tests
bool testTVInit() {
    SamsungTV tv;
    if (tv.getBrand() != "Samsung") return false;
    // Default volume/channel check if accessible
    if (tv.getVolume() < 0 || tv.getVolume() > 100) return false; 
    return true;
}

// 4. Smoke Detector Tests
bool testSmokeDetectorInit() {
    NestSmokeDetector detector;
    if (detector.getBrand() != "Nest") return false;
    if (detector.getSmokeLevel() != 0) return false; // Should start clean
    return true;
}

// 5. Sound System Tests
bool testSoundSystemInit() {
    SonosSoundSystem sound;
    if (sound.getBrand() != "Sonos") return false;
    if (sound.getVolume() < 0) return false;
    return true;
}

// 6. Alarm Tests
bool testAlarmInit() {
    Alarm* alarm = Alarm::getInstance();
    if (alarm->getDeviceType() != "Alarm (Singleton)") return false;
    // Note: isActive comes from Device base class, assuming it defaults properly or we check ringing
    if (alarm->isAlarmRinging()) return false; // Should be silent by default
    return true;
}

// 7. Security System Tests
bool testSecuritySystemInit() {
    // Needs Alarm and Light Vector
    Alarm* alarm = Alarm::getInstance();
    std::vector<Light*>* lights = new std::vector<Light*>();
    
    SecuritySystem ss(alarm, lights);
    
    bool result = true;
    if (ss.isActivated()) result = false; // Should be disarmed by default
    
    // Cleanup lights only, Alarm is singleton managed
    delete lights;
    
    return result;
}

// 8. Mode Manager Tests
bool testModeManagerInit() {
    ModeManager mm;
    // Check if it has a valid current mode name
    std::string modeName = mm.getCurrentModeName();
    if (modeName.empty()) return false;
    if (modeName != "Normal") return false; // Assuming Normal is default
    return true;
}

// 9. Factory Tests
bool testDeviceFactory() {
    SamsungFactory factory;
    Device* tv = factory.createTV();
    
    bool result = true;
    if (tv->getBrand() != "Samsung") result = false;
    
    delete tv;
    return result;
}

int main() {
    std::cout << "Starting Comprehensive Component Tests..." << std::endl;
    std::cout << "=======================================" << std::endl;
    
    runTest("Light Initialization", testLightInit);
    runTest("Camera Initialization", testCameraInit);
    runTest("TV Initialization", testTVInit);
    runTest("Smoke Detector Initialization", testSmokeDetectorInit);
    runTest("Sound System Initialization", testSoundSystemInit);
    runTest("Alarm Initialization", testAlarmInit);
    runTest("Security System Initialization", testSecuritySystemInit);
    runTest("Mode Manager Initialization", testModeManagerInit);
    runTest("Device Factory Creation", testDeviceFactory);
    
    std::cout << "\nTest Summary: " << passedTests << "/" << totalTests << " passed." << std::endl;
    
    return (totalTests == passedTests) ? 0 : 1;
}