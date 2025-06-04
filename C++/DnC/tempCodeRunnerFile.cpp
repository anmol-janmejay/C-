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