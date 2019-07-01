#include <iostream>
#include <vector>

using namespace std;

bool IsContains(const vector<vector<int> >& matrix, int k)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row = 0;
    int col = cols - 1;

    while (row < rows && col > -1)
    {
        if (matrix[row][col] == k)
        {
            return true;
        }
        else if (matrix[row][col] > k)
        {
            --col;
        }
        else
        {
            ++row;
        }
    }
    
    return false;
}

int main(void)
{
    vector<vector<int> >matrix;
    int k = 233;
    int a[8][7] = { { 0, 1, 2, 3, 4, 5, 6  },// 0
                    { 10, 12, 13, 15, 16, 17, 18  },// 1
                    { 23, 24, 25, 26, 27, 28, 29  },// 2
                    { 44, 45, 46, 47, 48, 49, 50  },// 3
                    { 65, 66, 67, 68, 69, 70, 71  },// 4
                    { 96, 97, 98, 99, 100, 111, 122  },// 5
                    { 166, 176, 186, 187, 190, 195, 200  },// 6
                    { 233, 243, 321, 341, 356, 370, 380  } // 7
                        };

    for (int i = 0; i < 8; ++i)
    {
        vector<int> v;
        for (int j = 0; j < 7; ++j)
        {
            v.push_back(a[i][j]);
        }
        matrix.push_back(v);
        v.clear();
    }

    if (IsContains(matrix, k))
        cout << "true" <<endl;

    return 0;
}
