#pragma once

#if defined(_WIN32) || defined(_WIN64)
#ifdef SCANNERLIB_EXPORTS
#define SCANNERLIB_API __declspec(dllexport)
#else
#define SCANNERLIB_API __declspec(dllimport)
#endif
#else
#define SCANNERLIB_API
#endif
