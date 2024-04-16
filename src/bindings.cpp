//
// Created by Hermanest on 13-Apr-24.
//
#include <exception>
#include "bindings.h"

static YGBindingsLogger logger;

static void Log(std::exception &err) {
    if (logger == nullptr) return;
    logger((char*)err.what(), YGLogLevelFatal);
}

extern "C" {

void YGBindingsSetLogger(YGBindingsLogger callback) {
    logger = callback;
}

void YGNodeInsertChildSafe(YGNodeRef node, YGNodeRef child, int index) {
    try {
        YGNodeInsertChild(node, child, index);
    } catch (std::exception &err) {
        Log(err);
    }
}

void YGNodeRemoveChildSafe(YGNodeRef node, YGNodeRef child) {
    try {
        YGNodeRemoveChild(node, child);
    } catch (std::exception &err) {
        Log(err);
    }
}

void YGNodeRemoveAllChildrenSafe(YGNodeRef node) {
    try {
        YGNodeRemoveAllChildren(node);
    } catch (std::exception &err) {
        Log(err);
    }
}

}