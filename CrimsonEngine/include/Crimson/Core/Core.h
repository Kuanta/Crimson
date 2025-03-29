#pragma once

#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <memory>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <filesystem>
#include <unordered_map>


// CRIMSON_API tanımı: Export/Import ayarları
#ifdef CRIMSON_EXPORT
    #ifdef _MSC_VER
        #define CRIMSON_API __declspec(dllexport)
    #else
        #define CRIMSON_API __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define CRIMSON_API __declspec(dllimport)
    #else
        #define CRIMSON_API
    #endif
#endif