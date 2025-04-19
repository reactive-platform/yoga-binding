//
// Created by Hermanest on 13-Apr-24.
//
#pragma once

#include <yoga/Yoga.h>

#define EXPORT __attribute__((visibility("default")))

extern "C" {
typedef void (* YGBindingsLogger)(char* string, YGLogLevel level);

EXPORT void YGBindingsConfigSetLogger(YGBindingsLogger logger);
}
