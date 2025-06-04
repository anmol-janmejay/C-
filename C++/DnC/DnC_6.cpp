#include <iostream>
using namespace std;

bool isSafe(int value, int board[9][9], int curr_row, int curr_column)
{
    // row check
    for (int col = 0; col < 9; col++)
    {
        if (board[curr_row][col] == value)
        {
            return false;
        }
    }

    // column check
    for (int row = 0; row < 9; row++)
    {
        if (board[row][curr_column] == value)
        {
            return false;
        }
    }

    // 3*3 box check
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[3 * (curr_row / 3) + i][3 * (curr_column / 3) + j] == value)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(int board[9][9], int n)
{
    // Find the Next Empty cell
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        // check for empty cell
        {
            if (board[i][j] == 0)
            {
                for (int value = 1; value <= 9; value++)
                {
                    // check for safety
                    if (isSafe(value, board, i, j))
                    {
                        // insert
                        board[i][j] = value;
                        // baaki recursion sambhal lega
                        if (solve(board, n))
                        {
                            return true;
                        }
                        // backtracking
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
}

int main()
{
    int board[9][9] = {
        {4, 5, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 7, 0, 6, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 2, 8},
        {0, 0, 0, 9, 5, 0, 0, 0, 0},
        {0, 8, 6, 0, 0, 0, 2, 0, 0},
        {0, 2, 0, 6, 0, 0, 7, 5, 0},
        {0, 0, 0, 0, 0, 0, 4, 7, 6},
        {0, 7, 0, 0, 4, 5, 0, 0, 0},
        {0, 0, 8, 0, 0, 9, 0, 0, 0}};

    int n = 9;

    if (solve(board, n))
    {
        cout << "Solved Sudoku Board:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists for the given Sudoku board." << endl;
    }
    return 0;
}

// #include <iostream>
// using namespace std;

// // Function to check if placing a value is safe
// bool isSafe(int value, int board[9][9], int curr_row, int curr_column)
// {
//     // Row check
//     for (int col = 0; col < 9; col++)
//     {
//         if (board[curr_row][col] == value)
//         {
//             return false;
//         }
//     }

//     // Column check
//     for (int row = 0; row < 9; row++)
//     {
//         if (board[row][curr_column] == value)
//         {
//             return false;
//         }
//     }

//     // 3x3 box check
//     int startRow = curr_row / 3 * 3;
//     int startCol = curr_column / 3 * 3;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             if (board[startRow + i][startCol + j] == value)
//             {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// // Function to solve the Sudoku
// bool solve(int board[9][9], int n)
// {
//     // Find the next empty cell
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (board[i][j] == 0)
//             { // Empty cell found
//                 // Try placing digits 1-9
//                 for (int value = 1; value <= 9; value++)
//                 {
//                     if (isSafe(value, board, i, j))
//                     {
//                         // Place the value
//                         board[i][j] = value;

//                         // Recursively solve the rest of the board
//                         if (solve(board, n))
//                         {
//                             return true;
//                         }

//                         // Backtrack if solution not found
//                         board[i][j] = 0;
//                     }
//                 }

//                 // If no value fits, return false
//                 return false;
//             }
//         }
//     }

//     // If no empty cells are left, the board is solved
//     return true;
// }

// int main()
// {
//     int board[9][9] = {
//         {4, 5, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 2, 0, 7, 0, 6, 3, 0},
//         {0, 0, 0, 0, 0, 0, 0, 2, 8},
//         {0, 0, 0, 9, 5, 0, 0, 0, 0},
//         {0, 8, 6, 0, 0, 0, 2, 0, 0},
//         {0, 2, 0, 6, 0, 0, 7, 5, 0},
//         {0, 0, 0, 0, 0, 0, 4, 7, 6},
//         {0, 7, 0, 0, 4, 5, 0, 0, 0},
//         {0, 0, 8, 0, 0, 9, 0, 0, 0}};

//     int n = 9;

//     if (solve(board, n))
//     {
//         cout << "Solved Sudoku Board:" << endl;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cout << board[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }
//     else
//     {
//         cout << "No solution exists for the given Sudoku board." << endl;
//     }

//     return 0;
// }
