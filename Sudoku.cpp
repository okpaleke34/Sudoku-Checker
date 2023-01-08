#include "Utils.h"
#include "Sudoku.h"

bool Sudoku::checkSudoku(const std::vector<std::vector<int>>puzzle, int size)
{
    // Check rows
    for (int row = 0; row < size; row++)
    {
        /*std::vector<int> puzzle_ = puzzle[i];
        sort(puzzle_.begin(), puzzle_.end());
        vector<int>::iterator it = std::unique(puzzle_.begin(), puzzle_.end());
        bool wasUnique = (it == puzzle_.end());
        if (!wasUnique) {
            return false;
        }*/

        std::vector<bool> used(size + 1);
        for (int col = 0; col < size; col++)
        {
            if (puzzle[row][col] != 0 && used[puzzle[row][col]]) {
                return false;
            }
            used[puzzle[row][col]] = true;
        }
    }

    // Check columns
    for (int col = 0; col < size; col++)
    {
        std::vector<bool> used(size + 1);
        for (int row = 0; row < size; row++)
        {
            if (puzzle[row][col] != 0 && used[puzzle[row][col]]) {
                return false;
            }
            used[puzzle[row][col]] = true;
        }
    }

    // Check the mini box(square root)
    int _sqrt = sqrt(size);
    for (int row = 0; row < size; row += _sqrt)
    {
        for (int col = 0; col < size; col += _sqrt)
        {
            std::vector<bool> used(size + 1);
            for (int k = 0; k < size; k++)
            {
                int x = row + k / _sqrt;
                int y = col + k % _sqrt;
                if (puzzle[x][y] != 0 && used[puzzle[x][y]]) {
                    return false;
                }
                used[puzzle[x][y]] = true;
            }
        }
    }
    return true;
}