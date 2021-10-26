#include <iostream>

using namespace std;

int factorial(int);
double p_func(double, int);

int main()
{
    system("cls");
    int size;
    cout << "Enter the size of data:\t";
    cin >> size;

    double arr[size][size + 1], delta;

    for (int a = 0; a < size; a++)
    {
        for (int b = 0; b <= size; b++)
        {
            arr[a][b] = 16148168401;
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

    //creating table
    for (int n = 1; n <= size; n++)
        for (int m = n - 1; m < size - 1; m++)
            arr[m + 1][n + 1] = arr[m + 1][n] - arr[m][n];

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
            if (arr[a][b] == 16148168401)
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

    //calculating the interpolated term
    double x, p, h, y, temp;
    cout << "Enter the interpolation value for x:\t";
    cin >> x;

    h = arr[1][0] - arr[0][0];
    p = (x - arr[size - 1][0]) / h;

    y = arr[size - 1][1];
    for (int t = 2; t <= size; t++)
    {
        temp = (arr[size - 1][t] * p_func(p, t - 1)) / factorial(t - 1);
        y += temp;
    }

    cout << "y(" << x << ") is:\t" << y << endl;

    system("echo Thanks!!!");
}

//my functions

int factorial(int x)
{
    if (x == 0 || x == 1)
    {
        return 1;
    }
    else
    {
        return x * factorial(x - 1);
    }
}

double p_func(double p, int i)
{
    double result = 1;
    for (int j = 0; j < i; j++)
    {
        result *= p + j;
    }
    return result;
}