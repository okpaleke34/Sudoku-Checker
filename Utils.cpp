#include "Utils.h"


struct Switches Utils::permuation(int argc, char** argv)
{
	Switches mySwitch;
	if (argc == 1)
	{
		mySwitch.help = true;
	}
	for (int i = 0; i < argc; i++)
	{

		if (i != 0)
		{
			string prevSwitch = argv[i - 1];
			string currSwitch = argv[i];
			if (currSwitch == "-h")
			{
				mySwitch.help = true;
			}
			else if (prevSwitch == "-p")
			{
				mySwitch.solution_path = argv[i];
			}
			else if (prevSwitch == "-s")
			{
				int size = atoi(argv[i]);
				if (this->hasNaturalRoot(size) && !(size == 0 || size == 1)) {
					mySwitch.solution_size = size;
				}
				else {
					throw std::invalid_argument("The puzzle size provided is either 0 or 1 or not a natural root.\n\n");
				}
			}
		}
	}
	if (mySwitch.help)
	{
		cout << "=====Welcome to Sudoku Checker program====="
			<< "\nThis program checks sudoku solution for any square size sudoku puzzle."
			<< "\nTo handle this operation you need to create a solution file and make use of the correct command line switch."
			<< "\nAnalogy of a valid solution file is that \n"
			<< "\n-The size of the solution file will be a set of square of natural numbers except 1 example 4,9,16,25,36."
			<< "\n-Each row and column will contain the same number of integers and all cells must be natural numbers less than the size provided."
			<< "\n-Each cell will be seperated by a space"
			<< "\nExample of a 4x4 solution file is a .txt file that contains this \n\n1 4 3 2\n3 2 1 4\n4 1 2 3\n2 3 4 1\n"
			<< "\nPut this in a file and save it as solution.txt then pass the path + filename as the solution path"
			<< "\nThen on the command type \n>sudoku -p ./solution.txt -s 4\n"
			<< "\nIt is important to note that if the size of the sudoku is not provided it will take it as a 9x9 sudoku.\n\n";
	}

	if (mySwitch.solution_path == "")
	{
		throw std::invalid_argument("This program requires a solution file and none was found in the command line.\n\n");
	}
	
	//make the deafult puzzle size to 9 if none inputed
	if (mySwitch.solution_size == -1) {
		mySwitch.solution_size = 9;
	}
	return mySwitch;
}

bool Utils::hasNaturalRoot(int n)
{
	int root = sqrt(n);
	return root * root == n;
}


vector<vector<int>> Utils::readFile(string file_path, int size)
{
	vector<vector<int>> content;
	vector<int> row;
	string line, word, file_text;
	int digit;
	fstream file(file_path, ios::in);
	if (file.is_open())
	{
		int r = 1;
		while (getline(file, line))
		{
			row.clear();
			stringstream str(line);
			int col = 1;
			while (getline(str, word, ' '))
			{
				stringstream ss(word);
				ss >> digit;
				//Throw an exeption if the value is not supported. Supported values are 1-size
				if (digit == 0 || digit > size) {
					throw std::invalid_argument("There is an error in row " + to_string(r) + " column " + to_string(col) + ". The value is not supported in the puzzle. Suppoted values are 1-"+to_string(size));
				}
				row.push_back(digit);
				col++;
			}
			//throw an exception if there is a row that does not have expected number of cells
			if (row.size() != size) {
				throw std::out_of_range("There is an error in the solution file("+file_path+") in row "+to_string(r)+". Total cell number of "+to_string(size)+" is expected but "+to_string(row.size()) + " was found.");
			}
			//cout << "Total i = "<< i <<" row = "<< row.size() << endl;
			content.push_back(row);
			r++;
		}
		file.close();
		//throw an exception if the total rows does not have same size as expected
		if (content.size() != size) {
			throw std::out_of_range("There is an error in the solution file(" + file_path + "). Total row number of " + to_string(size) + " is expected but " + to_string(content.size()) + " was found.");
		}
	}
	else
	{
		throw std::exception("Could not open the file\n");
	}
	return content;
}