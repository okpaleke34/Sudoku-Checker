#ifndef UTILS_H
#define UTILS_H
#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


using std::string; using std::vector; using std::to_string;
using std::cout; using std::cin; using std::endl;
using std::fstream;using std::ios;using std::stringstream;

struct Switches
{
	string solution_path;
	int solution_size = -1;
	bool help = false;
};

class Utils {
private:
public:
	/*
	* This function loop through all the switch and assign it to the Switch struct according to the previous value.
	* This helps in permutation of the switch which means any switch can be added any place without following strict position.
	*@param argv is the array of all the switches
	*@param argc is the total number of the switch seperated by space entered
	*@return It returns a struct that contains all the switches
	*/
	struct Switches permuation(int, char**);
	/*
	* This reads a solution file and turn the file content to a vector. It checks for errors in the size and content of the file and throws an exception
	* @param path the link/path to the solution file
	* @param size the size of the puzzle eg 4 means it is a 4x4 sudoku
	* @return It retuns a vector of vector int  conataining the puzzle
	*/
	vector<vector<int>> readFile(string,int);
	/*
	* This function checks if a number passed through it has a natural root
	* @param number
	* @return a boolen of true or false
	*/
	bool hasNaturalRoot(int);
};

#endif