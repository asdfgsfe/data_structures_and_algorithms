#include <iostream>
#include <vector>

using namespace std;

void PrintLevel(const vector<vector<int> >& matrix, int tR, int tC, int dR, int dC, bool fromUp)
{
    if (fromUp)
    {
        while (tR != dR + 1)
        {
            //cout << "t: [" << dR << " " << dC << "]";
            cout << matrix[tR++][tC--] << " ";
        }
        cout << endl;
    }
    else
    {
        while (dR != tR - 1)
        {
            //cout << "f: [" << tR << " " << tC << "]";
            cout << matrix[dR--][dC++] << " ";
        }
        cout << endl;
    }
}

void ZigZagPrintMatrix(const vector<vector<int> >& matrix)
{
    int rows = matrix.size() - 1;
    int cols = matrix[0].size() - 1;
    int tR = 0;
    int tC = 0;
    int dR = 0;
    int dC = 0;
    bool fromUp = false;

    while (tR <= rows)
    {
        //cout << "[" << tR << "," << tC << "]" << "[" << dR << ", " << dC << "]" << endl; 

        PrintLevel(matrix, tR, tC, dR, dC, fromUp);
        
        //NOTE: Order tR, tC, dC, dR
        tR = tC == cols ? tR + 1 : tR;
        tC = tC == cols ? tC : tC + 1;
        dC = dR == rows ? dC + 1 : dC;
        dR = dR == rows ? dR : dR + 1;
        fromUp = !fromUp;
    }
    cout << endl;
}

int main(void)
{
    vector<vector<int> >matrix;
    int k = 1;
    for (int i = 0; i < 3; i++)
    {
        vector<int> v;
        for (int j = 0; j < 3; ++j)
        {
            v.push_back(k);
            k++;
        }
        matrix.push_back(v);
        v.clear();
    }
    ZigZagPrintMatrix(matrix);
        
    return 0;
}
