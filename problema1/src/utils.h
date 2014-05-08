#ifndef UTILS_H
#define UTILS_H

#define __debug__
#ifdef __debug__
#include <cstdlib>
#define debug() do {std::cout << "debug línea "  << __LINE__ << std::endl;} while(0)
#define die() do {std::cout << "die línea "  << __LINE__ << std::endl; exit(0);} while(0)
#else
#define debug() do {} while(0)
#define die() do {} while(0)
#endif

#define print(...) do {cout __print_select(__VA_ARGS__, __print16, __print15, __print14, __print13, __print12, __print11, __print10, __print07, __print09, __print08, __print06, __print05, __print04, __print03, __print02, __print01)(__VA_ARGS__);} while(0)
#define __print_select(__01, __02, __03, __04, __05, __06, __07, __08, __09, __10, __11, __12, __13, __14, __15, __16, macro, ...) macro
#define __print01(a) << (a)
#define __print02(a,...) __print01(a) __print01(__VA_ARGS__)
#define __print03(a,...) __print01(a) __print02(__VA_ARGS__)
#define __print04(a,...) __print01(a) __print03(__VA_ARGS__)
#define __print05(a,...) __print01(a) __print04(__VA_ARGS__)
#define __print06(a,...) __print01(a) __print05(__VA_ARGS__)
#define __print07(a,...) __print01(a) __print06(__VA_ARGS__)
#define __print08(a,...) __print01(a) __print07(__VA_ARGS__)
#define __print09(a,...) __print01(a) __print08(__VA_ARGS__)
#define __print10(a,...) __print01(a) __print09(__VA_ARGS__)
#define __print11(a,...) __print01(a) __print10(__VA_ARGS__)
#define __print12(a,...) __print01(a) __print11(__VA_ARGS__)
#define __print13(a,...) __print01(a) __print12(__VA_ARGS__)
#define __print14(a,...) __print01(a) __print13(__VA_ARGS__)
#define __print15(a,...) __print01(a) __print14(__VA_ARGS__)
#define __print16(a,...) __print01(a) __print15(__VA_ARGS__)

#define if_(cond) ((cond) ?
#define then_(expr) (expr) :
#define else_(expr) (expr))

#define if_then_else(c,t,f) ((c) ? (t) : (f))

#endif /* UTILS_H */