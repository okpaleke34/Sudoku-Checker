#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Utils.h"
#include "Sudoku.h"



int main(int argc, char** argv)
{
    Utils* utils = new Utils();
    Sudoku* sudoku = new Sudoku();
    struct Switches mySwitch;
    try {
        mySwitch = utils->permuation(argc, argv);
        vector<vector<int>> puzzle = utils->readFile(mySwitch.solution_path, mySwitch.solution_size);
        if (sudoku->checkSudoku(puzzle, mySwitch.solution_size))
            cout << "\n\nCongratulations! You successfully solved the Sudoku puzzle.\n\n" << endl;
        else
            cout << "\n\nThe sudoku puzzle was not arranged properly. Rearrange and check again.\n\n" << endl;
    }
    catch (std::out_of_range& e) {
        cout << "Out of range exception: " << e.what() << endl;
    }
    catch (std::invalid_argument& e) {
        cout << "Invalid argument: " << e.what() << endl;
    }
    catch (std::exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}


