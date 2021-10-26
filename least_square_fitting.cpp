#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    system("cls");
    int size;
    cout << "Enter size of x and y arrays ---\t ";
    cin >> size;

    float arr_x[size], arr_y[size], sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0, slope = 0, intercept = 0;

    cout << "Enter the elements for X\t[with spaces]\n";
    cout << "--------------------------------------\n";

    for (int i = 0; i < size; i++)
    {
        cin >> arr_x[i];
    }
    cout << "--------------------------------------\n\n";

    cout << "Enter the elements for Y\t[with spaces]\n";
    cout << "--------------------------------------\n";
    for (int j = 0; j < size; j++)
    {
        cin >> arr_y[j];
    }
    cout << "--------------------------------------\n\n";

    for (int k = 0; k < size; k++)
    {
        sum_x += arr_x[k];
        sum_y += arr_y[k];
        sum_x2 += (pow(arr_x[k], 2));
        sum_xy += (arr_x[k] * arr_y[k]);
    }

    slope = ((size * sum_xy) - (sum_x * sum_y)) / ((size * sum_x2) - pow(sum_x, 2));

    intercept = ((sum_y / size) - (slope * (sum_x / size)));

    cout << "Slope is ---\t" << slope << endl;
    cout << "Intercept is ---\t" << intercept << endl;

    //-------------------------------------------------------------------------------
    // for cc
    float y_bar = 0, Sy = 0, S = 0, cc = 0, temp = 0;

    y_bar = sum_y / size;

    for (int m = 0; m < size; m++)
    {
        Sy += pow((arr_y[m] - y_bar), 2);
        S += pow((arr_y[m] - (intercept + (slope * arr_x[m]))), 2);
    }

    temp = (Sy - S) / Sy;
    cc = pow(temp, 0.5);

    cout << "Corelation Coefficient is ---\t" << cc << endl;
    cout << "\n-----------------------------------------------------------\n";

    cout << "X\t|\t"
         << "Y\t|\t"
         << "Y_CAL\t|\t"
         << "ERROR" << endl;
    cout << "-----------------------------------------------------------\n";
    float y_calc = 0, error = 0;
    for (int x = 0; x < size; x++)
    {
        y_calc = (intercept + (slope * arr_x[x]));
        error = arr_y[x] - y_calc;
        cout << arr_x[x] << "\t|\t" << arr_y[x] << "\t|\t" << y_calc << "\t|\t" << error << endl;
    }
    cout << "-----------------------------------------------------------\n\n";
    system("echo Thanks!!!");
}