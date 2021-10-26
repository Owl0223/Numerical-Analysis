#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    system("cls");
    int size;
    cout << "Enter the size of data:\t";
    cin >> size;

    bool choice = true;
    double arr[size][size + 1], arr_back[size][size + 1], delta;

    for (int a = 0; a < size; a++)
    {
        for (int b = 0; b <= size; b++)
        {
            arr[a][b] = 16148;
            arr_back[a][b] = 16148;
        }
    }
    cout << "Enter x data :-\n----------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i][0];
    }

    cout << "\n\nEnter y data :-\n----------------------------------------------\n";
    for (int j = 0; j < size; j++)
    {
        cin >> arr[j][1];
    }
    cout << "\n\n";

    // duplicating array

    for (int i = 0; i < size; i++)
        for (int j = 0; j <= size; j++)
            arr_back[i][j] = arr[i][j];

    //creating tables

    //forward difference
    for (int n = 1; n <= size; n++)
        for (int m = 0; m < size - n; m++)
            arr[m][n + 1] = arr[m + 1][n] - arr[m][n];

    //backward difference
    for (int n = 1; n <= size; n++)
        for (int m = n - 1; m < size - 1; m++)
            arr_back[m + 1][n + 1] = arr_back[m + 1][n] - arr_back[m][n];

    //displaying forward
    cout << "Forward Difference Table" << endl;
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
            if (arr[a][b] == 16148)
            {
                cout << "NIL\t";
            }
            else
            {
                cout << arr[a][b] << "\t";
            }
        }
        cout << endl;
    }
    cout << "\n----------------------------------------------\n\n";

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
    double x, h = arr[1][0] - arr[0][0], sum = 0;
    int index = -1;
    cout << "Enter the x datum at which derivative is to be calculated:\t";
    cin >> x;

    //finding the index of x
    for (int l = 0; l < size; l++)
    {
        if (x == arr[l][0])
        {
            index = l;
            break;
        }
    }
    cout << "\nIndex of " << x << " = " << index << endl;

    if (index == -1)
        return 0;

    if (index > size / 2)
        choice = false;

    if (choice)
    {
        for (int t = 2; t <= size - index; t++)
        {
            sum += (arr[index][t] / (t - 1)) * pow(-1, t);
        }
    }
    else
    {
        for (int t = 2; t <= index + 1; t++)
        {
            sum += arr_back[index][t] / (t - 1);
        }
    }
    sum /= h;

    cout << "Differentiation at " << x << " is:\t" << sum << endl
         << endl;
    if (choice)
    {
        cout << "~Used Forward Difference Table~" << endl;
    }
    else
    {
        cout << "~Used Backward Difference Table~" << endl;
    }

    system("echo Thanks!!!");
}