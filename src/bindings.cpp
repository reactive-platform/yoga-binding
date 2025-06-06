//
// Created by Hermanest on 13-Apr-24.
//
#include <cstdio>
#include "bindings.h"

static YGBindingsLogger logger = nullptr;

extern "C" {
int YGLoggerWrapper(
    YGConfigConstRef config,
    YGNodeConstRef node,
    YGLogLevel level,
    const char* format,
    va_list args
) {
    if (logger == nullptr) {
        return 0;
    }

    // Format the log string
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), format, args);

    // Call the bindings logger
    logger(level, buffer);

    return 0;
}

void YGBindingsConfigSetLogger(YGConfigRef config, YGBindingsLogger logger) {
    ::logger = logger;

    if (logger != nullptr) {
        YGConfigSetLogger(config, YGLoggerWrapper);
    } else {
        YGConfigSetLogger(config, nullptr);
    }
}
}
