// This is file with all the code of 1st task.

#include "first-task.h"

namespace First {

	// Prints max and min numbers of same ones amount in bit representation of given number.
	void min_max(uint32_t number) {
		number = number - ((number >> 1) & 0x55555555);
		number = (number & 0x33333333) + ((number >> 2) & 0x33333333);
		// ones count in number
		int count = ((number + (number >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;

		uint32_t all_ones = 4294967295;
		std::cout << "Maximum size number of 32 bits with " << count << " ones: " << (all_ones << 32 - count) << std::endl;
		std::cout << "Minimum size number of 32 bits with " << count << " ones: " << (all_ones >> 32 - count) << std::endl;
	}
}