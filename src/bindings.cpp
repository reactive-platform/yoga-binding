//
// Created by Hermanest on 13-Apr-24.
//
#include <exception>
#include "bindings.h"

static YGBindingsLogger logger = nullptr;

static void Log(const std::exception &err)
{
    if (logger == nullptr)
        return;
    logger(const_cast<char *>(err.what()), YGLogLevelFatal);
}

void YGBindingsSetLogger(YGBindingsLogger callback)
{
    logger = callback;
}

void YGNodeInsertChildSafe(YGNodeRef node, YGNodeRef child, int index)
{
    try
    {
        YGNodeInsertChild(node, child, static_cast<uint32_t>(index));
    }
    catch (const std::exception &err)
    {
        Log(err);
    }
}

void YGNodeRemoveChildSafe(YGNodeRef node, YGNodeRef child)
{
    try
    {
        YGNodeRemoveChild(node, child);
    }
    catch (const std::exception &err)
    {
        Log(err);
    }
}

void YGNodeRemoveAllChildrenSafe(YGNodeRef node)
{
    try
    {
        YGNodeRemoveAllChildren(node);
    }
    catch (const std::exception &err)
    {
        Log(err);
    }
}

void YGTest()
{
    // Test function implementation
}