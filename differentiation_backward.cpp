#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    system("cls");
    int size;
    cout << "Enter the size of data:\t";
    cin >> size;

    double arr_back[size][size + 1], delta;

    for (int a = 0; a < size; a++)
    {
        for (int b = 0; b <= size; b++)
        {
            arr_back[a][b] = 16148;
        }
    }
    cout << "Enter x data :-\n----------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr_back[i][0];
    }

    cout << "\n\nEnter y data :-\n----------------------------------------------\n";
    for (int j = 0; j < size; j++)
    {
        cin >> arr_back[j][1];
    }
    cout << "\n\n";

    //backward difference
    for (int n = 1; n <= size; n++)
        for (int m = n - 1; m < size - 1; m++)
            arr_back[m + 1][n + 1] = arr_back[m + 1][n] - arr_back[m][n];

    //displaying backward
    cout << "Backward Difference Table" << endl;
    cout << "\n----------------------------------------------\n";

    cout << "x\ty\t";
    for (int i = 1; i < size; i++)
    {
        cout << "y" << i << "\t";
    }
    cout << "\n----------------------------------------------\n";

    for (int a = 0; a < size; a++)
    {
        for (int b = 0; b <= size; b++)
        {
            if (arr_back[a][b] == 16148)
            {
                cout << "NIL\t";
            }
            else
            {
                cout << arr_back[a][b] << "\t";
            }
        }
        cout << endl;
    }
    cout << "\n----------------------------------------------\n\n";

    //differentiating
    double x, h = arr_back[1][0] - arr_back[0][0], sum = 0;
    int index = -1;
    cout << "Enter the x datum at which derivative is to be calculated:\t";
    cin >> x;

    //finding the index of x
    for (int l = 0; l < size; l++)
    {
        if (x == arr_back[l][0])
        {
            index = l;
            break;
        }
    }
    cout << "\nIndex of " << x << " = " << index << endl;

    if (index == -1)
        return 0;

    for (int t = 2; t <= index + 1; t++)
    {
        sum += arr_back[index][t] / (t - 1);
    }

    sum /= h;

    cout << "Differentiation at " << x << " is:\t" << sum << endl
         << endl;
    cout << "~Used Backward Difference Table~" << endl;

    system("echo Thanks!!!");
}