#include <iostream>
#include <string>
#include "SudokuBoard.h"

using namespace std;

int main() {
	int testArray[9][9] = {
		{ 0,5,1,	0,0,0,	0,0,0 },
		{ 3,6,8,	2,4,9,	1,5,7 },
		{ 0,9,4,	0,6,0,	0,0,0 },

		{ 0,2,7,	0,0,6,	0,0,1 },
		{ 0,3,9,	0,1,2,	7,6,0 },
		{ 1,0,6,	4,0,0,	2,0,0 },

		{ 0,0,2,	0,5,0,	3,1,0 },
		{ 9,1,5,	6,8,3,	4,7,2 },
		{ 0,0,3,	0,2,0,	0,8,0 },
	};
	SudokuBoard test(testArray);

	cout << test.toString() << endl;

	cout << "This is the before of the puzzle. Lets see how it looks after calling solve!" << endl;

	test.fillBoard();

	cout << test.toString() << endl;

	return 0;
}