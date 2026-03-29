//
// Created by Hermanest on 13-Apr-24.
//
#pragma once

#include <yoga/Yoga.h>

#ifdef _MSC_VER
#ifdef YOGA_BINDING_EXPORTS
#define YOGA_API __declspec(dllexport)
#else
#define YOGA_API __declspec(dllimport)
#endif
#else
#define YOGA_API __attribute__((visibility("default")))
#endif

extern "C" {
typedef void (* YGBindingsLogger)(YGLogLevel level, char* string);

YOGA_API void YGBindingsConfigSetLogger(YGConfigRef config, YGBindingsLogger logger);
}
