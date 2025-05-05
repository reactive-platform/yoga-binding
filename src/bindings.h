//
// Created by Hermanest on 13-Apr-24.
//
#pragma once

#include <yoga/Yoga.h>

#define EXPORT __attribute__((visibility("default")))

extern "C" {
typedef void (* YGBindingsLogger)(YGLogLevel level, char* string);

EXPORT void YGBindingsConfigSetLogger(YGConfigRef config, YGBindingsLogger logger);
}
