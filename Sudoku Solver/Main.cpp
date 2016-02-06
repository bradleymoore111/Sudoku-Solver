#include <iostream>
#include <string>
#include "SudokuBoard.h"

using namespace std;

int main() {
	int testArray[9][9] = {
		{ 1,2,3,	4,5,6,	7,8,9 },
		{ 8,5,6,	4,5,6,	7,8,9 },
		{ 7,0,9,	4,5,6,	7,7,9 },

		{ 1,2,3,	4,5,6,	7,8,9 },
		{ 0,1,1,	1,1,1,	1,2,1 },
		{ 1,2,3,	4,5,6,	7,8,9 },

		{ 3,2,3,	4,5,6,	7,8,9 },
		{ 2,2,3,	4,5,6,	7,8,9 },
		{ 1,2,3,	4,5,6,	7,8,9 },
	};
	SudokuBoard test(testArray);

	cout << test.toString() << endl;

	cout << ((test.isNOPV(8, 2, 1))?"true":"false") << endl;

	return 0;
}