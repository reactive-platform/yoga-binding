//
// Created by Hermanest on 13-Apr-24.
//
#pragma once

#include <yoga/Yoga.h>

#define EXPORT __attribute__((visibility("default")))

extern "C" {

typedef void (* YGBindingsLogger)(char* string, YGLogLevel level);

EXPORT void YGBindingsSetLogger(YGBindingsLogger callback);

EXPORT void YGNodeInsertChildSafe(YGNodeRef node, YGNodeRef child, int index);

EXPORT void YGNodeRemoveChildSafe(YGNodeRef node, YGNodeRef child);

EXPORT void YGNodeRemoveAllChildrenSafe(YGNodeRef node);

EXPORT void YGTest() {}

}
