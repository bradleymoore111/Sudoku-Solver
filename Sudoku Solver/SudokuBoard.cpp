#include <iostream>
#include <string>
#include "SudokuBoard.h"

using namespace std;

SudokuBoard::SudokuBoard()
{

}

void SudokuBoard::fillBoard() {

}

bool SudokuBoard::isNonlyPossibleVal(int n,int a,int b) { // at coordinate [a][b]

	return false;
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
