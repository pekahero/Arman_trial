//This file has all code for task 3.
#include "third-task.h"

namespace Third {
	bool check_solution(short(& solution)[9][9]) {
		int row_sum = 0;
		int column_sum[9] = { 0,0,0,0,0,0,0,0,0 };
		int sqrt_sum[3][3] = { { 0,0,0 }, { 0, 0, 0 }, { 0, 0, 0 } };

		for (auto i = 0; i < 9; i++) {
			for (auto j = 0; j < 9; j++) {
				row_sum ^= 1 << (solution[i][j] - 1);
				column_sum[i] ^= 1 << (solution[i][j] - 1);
				sqrt_sum[i / 3][j / 3] ^= 1 << (solution[i][j] - 1);
			}
			if (row_sum != 511)
				return false;
			row_sum = 0;
		}

		for (auto i = 0; i < 9; i++) 
			if (column_sum[i] != 511)
				return false;

		for (auto i = 0; i < 3; i++) 
			for (auto j = 0; j < 3; j++) 
				if (sqrt_sum[i][j] != 511)
					return false;
			
		return true;
	}
}