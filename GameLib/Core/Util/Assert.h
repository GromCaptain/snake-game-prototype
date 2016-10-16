#ifndef ASSERT_H
#define ASSERT_H

#ifndef NDEBUG
#include <iostream>
#   define ASSERT(condition, message) \
	do { \
		if (! (condition)) { \
			std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
					  << " line " << __LINE__ << ": " << message << std::endl; \
			std::exit(EXIT_FAILURE); \
		} \
	} while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

#endif // ASSERT_H
