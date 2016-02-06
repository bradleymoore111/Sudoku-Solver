#include <iostream>
#include <string>
#include "SudokuBoard.h"

using namespace std;

SudokuBoard::SudokuBoard()
{

}

void SudokuBoard::fillBoard() {
	// Using a backtracking method
	// Basically, is this gonna be a giant recursion thing?
	// Where like, at each empty cell, we test it with a value. Then we call the recursive function for the next cell with 9 different values. If they get to a point where all subtrees return false, then that would itself return false. If there's a single true though, then return true, and set the cell to the val you were testing yourself that the higher level called. If last cell, test and look for true. It shouldn't have been able to get to you if you can get true, 
	// Pseudo code!
	/*
	
	bool testCell(int board[][], int x, int y){
		// if last cell, test each. return false if none work, return true if works. 
		// otherwise
		// create new clone of board for each possible number that the next cell can be
		// call this function for the next blank cell for each number, storing all the true/falses they return. 
		//		if all responses are false, return false
		//		if there is a single (or more) true response, return true
		
	 */
	
	// Actual implementation time
	int x = 0, y = 0;
	while (board[x][y] != 0 || y <= 8) {
		x++;
		if (x == 9) {
			x = 0;
			y++;
		}
	}

	bool nums[9];
	for (int i = 0; i < 9; i++) {
		int tempBoard[9][9];
		for (int j = 0; j < 9; j++) for (int k = 0; k < 9; k++) tempBoard[j][k] = SudokuBoard::board[j][k]; // Copying array data over

		int a = x + 1;
		int b = y;
		if (a == 9) {
			a = 0;
			b++;
		}

		while (tempBoard[a][b] != 0 || b <= 8) {
			a++;
			if (a == 9) {
				a = 0;
				b++;
			}
		}


		if (a == 8 && b == 8 && tempBoard[a][b] != 0) {
			nums[i] = true;
		}

		else {
			if (SudokuBoard::isNOPV(tempBoard, i + 1, a, b)) { // Testing if this number can exist
				nums[i] = testCell(tempBoard, a, b);
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (nums[i]) {
			SudokuBoard::board[x][y] = i + 1;
		}
	}
}

bool SudokuBoard::testCell(int aboard[9][9], int x, int y) { // [x][y] is current location
	if (x == 8 && y == 8) { // last cell, got here successfully
		return true;
	}
	
	bool nums[9];
	for (int i = 0; i < 9; i++) {
		int tempBoard[9][9];
		for (int j = 0; j < 9; j++) for (int k = 0; k < 9; k++) tempBoard[j][k] = aboard[j][k]; // Copying array data over
		
		int a = x + 1;
		int b = y;
		if (a == 9) {
			a = 0;
			b++;
		}

		while (tempBoard[a][b] != 0 || b <= 8) {
			a++;
			if (a == 9) {
				a = 0;
				b++;
			}
		}


		if (a == 8 && b == 8 && tempBoard[a][b] != 0) {
			nums[i] = true;
		}

		else {
			if (SudokuBoard::isNOPV(tempBoard, i + 1, a, b)) { // Testing if this number can exist
				nums[i] = testCell(tempBoard, a, b);
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (nums[i]) {
			return true;
		}
	}

	return false;
}

// Does basic checking to see if a cell can contain a number. Is N On Possible Vals I think it stands for, not sure
bool SudokuBoard::isNOPV(int n,int a,int b) { // at coordinate [a][b]
	return isNOPVLine(n, a, b) && isNOPVSmallGrid(n, a, b);
}

bool SudokuBoard::isNOPV(int tempBoard[9][9], int n, int a, int b) {
	return isNOPVLine(tempBoard, n, a, b) && isNOPVSmallGrid(tempBoard, n, a, b);
}

// Appears to work
bool SudokuBoard::isNOPVLine(int n, int a, int b) {
	for (int i = 0; i < 9; i++) {
		// Checking vertical
		if (SudokuBoard::board[i][b] == n && i != a) {
			return false;
		}
		// Checking horizontal
		if (SudokuBoard::board[a][i] == n && i != b) {
			return false;
		}
	}

	return true;
}

bool SudokuBoard::isNOPVLine(int tempBoard[9][9], int n, int a, int b) {
	for (int i = 0; i < 9; i++) {
		// Checking vertical
		if (tempBoard[i][b] == n && i != a) {
			return false;
		}
		// Checking horizontal
		if (tempBoard[a][i] == n && i != b) {
			return false;
		}
	}

	return true;
}

// Appears to work
bool SudokuBoard::isNOPVSmallGrid(int n, int a, int b) {
	int c = a - a%3, d = b - b%3; // temp vars, to keep original coordinate while also having coordinates to play with
	for (int i = c; i < c + 3; i++) {
		for (int j = d; j < d + 3; j++) {
			if(SudokuBoard::board[i][j] == n && a!=i && j != b){
				return false;
			}
		}
	}
	return true;
}

bool SudokuBoard::isNOPVSmallGrid(int tempBoard[9][9], int n, int a, int b) {
	int c = a - a % 3, d = b - b % 3; // temp vars, to keep original coordinate while also having coordinates to play with
	for (int i = c; i < c + 3; i++) {
		for (int j = d; j < d + 3; j++) {
			if (tempBoard[i][j] == n && a != i && j != b) {
				return false;
			}
		}
	}
	return true;
}

string SudokuBoard::toString() {
	string s = "=============================\n|| ";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			s = s + to_string((SudokuBoard::board)[i][j]) + " ";
			if (j % 3 == 2) {
				s = s + "|| ";
			}
		}
		s = s + "\n";
		if (i % 3 == 2) {
			if (i != 8) {
				s = s + "=============================\n|| "; // etc.
			}
			else {
				s += "=============================\n";
			}
		}
		else {
			s = s + "|| ";
		}
	}
	return s;
}

SudokuBoard::SudokuBoard(int a[9][9])
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = a[i][j];
		}
	}
}

SudokuBoard::~SudokuBoard()
{
}
