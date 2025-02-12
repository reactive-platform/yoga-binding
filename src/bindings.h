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

extern "C"
{

    typedef void (*YGBindingsLogger)(char *string, YGLogLevel level);

    YOGA_API void YGBindingsSetLogger(YGBindingsLogger callback);

    YOGA_API void YGNodeInsertChildSafe(YGNodeRef node, YGNodeRef child, int index);

    YOGA_API void YGNodeRemoveChildSafe(YGNodeRef node, YGNodeRef child);

    YOGA_API void YGNodeRemoveAllChildrenSafe(YGNodeRef node);

    YOGA_API void YGTest();
}
