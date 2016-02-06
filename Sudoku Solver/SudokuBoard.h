#pragma once
#ifndef SUDOKUBOARD_H_
#define SUDOKUBOARD_H_
#include <string>

using namespace std;

class SudokuBoard
{
public:
	int board[9][9];

	// Basically, solve it.
	void fillBoard();

	// Tests whether a number N is the only possible value at a specific position
	bool isNOPV(int n, int a, int b);
	bool isNOPVLine(int n, int a, int b);// Is N only possible val in lines (scan horizontally and vertically, to count
	bool isNOPVSmallGrid(int n, int a, int b);

	// Returns an ascii representation of the board
	string toString();
	SudokuBoard();
	SudokuBoard(int [9][9]);
	~SudokuBoard();
};

#endif