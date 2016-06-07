/**
 * Esri CityEngine SDK Unity Plugin Example
 *
 * This example demonstrates the main functionality of the Procedural Runtime API.
 * Esri R&D Center Zurich, Switzerland
 *
 * See http://github.com/ArcGIS/esri-cityengine-sdk for instructions.
 */

#include <iostream>

#include "prtx/ExtensionManager.h"

#include "UnityEncoder.h"


#ifdef _WIN32
#	define CODECS_UNITY_EXPORTS_API __declspec(dllexport)
#else
#	define CODECS_UNITY_EXPORTS_API __attribute__ ((visibility ("default")))
#endif


/*
 * an extension library is only loaded if the major and minor version numbers match.
 * this ensures compatibility.
 */
static const int VERSION_MAJOR = 1;
static const int VERSION_MINOR = 3;


extern "C" {

CODECS_UNITY_EXPORTS_API void registerExtensionFactories(prtx::ExtensionManager* manager) {
	try {
		manager->addFactory(UnityEncoderFactory::instance());
	} catch (std::exception& e) {
		std::cerr << __FUNCTION__ << " caught exception: " <<  e.what() << std::endl;
	} catch (...) {
		std::cerr << __FUNCTION__ << " caught unknown exception: " << std::endl;
	}
}

CODECS_UNITY_EXPORTS_API void unregisterExtensionFactories(prtx::ExtensionManager* /*manager*/) {
}


CODECS_UNITY_EXPORTS_API int getVersionMajor() {
	return VERSION_MAJOR;
}

CODECS_UNITY_EXPORTS_API int getMinimalVersionMinor() {
	return VERSION_MINOR;
}

}
