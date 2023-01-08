#ifndef SUDOKU_H
#define SUDOKU_H
#pragma once
#include <algorithm>

class Sudoku {
private:
public:
	/*
	* This function checks if vector of sukudo solution passed as a parameter is valid
	* @param puzzle a vector of vector int conataing the sudoku puzzle
	* @param size and integer, that is size of the puzzle
	* @return it returns a bool true if the puzzle was arranged successfully
	*/
	bool checkSudoku(const std::vector<std::vector<int>>, int);
};

#endif