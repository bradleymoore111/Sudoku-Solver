#include <iostream>
#include <string>
#include "SudokuBoard.h"

using namespace std;

int main() {
	int testArray[9][9] = {
		{ 1,2,3,4,5,6,7,8,9 },
		{ 1,2,3,4,5,6,7,8,9 },
		{ 1,2,3,4,5,6,7,8,9 },
		{ 1,2,3,4,5,6,7,8,9 },
		{ 1,2,3,4,5,6,7,8,9 },
		{ 1,2,3,4,5,6,7,8,9 },
		{ 1,2,3,4,5,6,7,8,9 },
		{ 1,2,3,4,5,6,7,8,9 },
		{ 1,2,3,4,5,6,7,8,9 },
	};
	SudokuBoard test(testArray);

	cout << test.toString() << endl;

	return 0;
}