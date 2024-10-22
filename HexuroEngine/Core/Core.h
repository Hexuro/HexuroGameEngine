#ifndef _HEXURO_CORE_
#define _HEXURO_CORE_

#define BIT(x) (1 << x)

#ifdef _DEBUG
    #define HX_GAME_ASSERT(x, ...) { if(!(x)) { HX_GAME_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define HX_ENGINE_ASSERT(x, ...) { if(!(x)) { HX_ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define HX_GAME_ASSERT(x, ...)
    #define HX_ENGINE_ASSERT(x, ...)
#endif

#endif