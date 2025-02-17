﻿#include "Plugin.h"
#include <memory>

std::unique_ptr<Plugin> plugin;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
    if (dwReason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        plugin = std::make_unique<Plugin>(hModule);
    }
    return TRUE;
}