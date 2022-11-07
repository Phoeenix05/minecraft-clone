#ifndef __LOG_HPP__
#define __LOG_HPP__

#ifndef RELEASE

#include <iostream>

#define LOG_INFO(msg) std::printf("\033[1;92m[INFO]\033[0m %s", msg);
#define LOG_ERROR(msg) std::printf("\033[1;91m[ERROR]\033[0m %s", msg);
#define LOG_WARNING(msg) std::printf("\033[1;95m[ERROR]\033[0m %s", msg);

#else

#define LOG_INFO(msg)
#define LOG_ERROR(msg)
#define LOG_WARNING(msg)

#endif

#endif