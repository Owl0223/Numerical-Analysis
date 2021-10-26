#include <iostream>
#include <math.h>

using namespace std;
double round(double);

int main()
{
    system("cls");
    //input size of array
    int size;
    cout << "Enter size of arrays---\t";
    cin >> size;

    double arr_x[size], arr_y[size], arr_x_init[size], arr_y_init[size], sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0, slope = 0, intercept = 0, sum_init_y = 0;

    //input elements of x and y
    cout << "Enter the elements for X\t[With a space in between]\t---\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr_x[i];
    }
    cout << "----------------------------------------------\n";

    cout << "Enter the elements for Y\t[With a space in between]\t---\n";
    for (int j = 0; j < size; j++)
    {
        cin >> arr_y[j];
    }
    cout << "----------------------------------------------\n";

    //duplicating initial arrays
    for (int k = 0; k < size; k++)
    {
        arr_x_init[k] = arr_x[k];
        arr_y_init[k] = arr_y[k];
    }

    //taking log of Y array
    for (int m = 0; m < size; m++)
    {
        arr_y[m] = log(arr_y[m]);
    }

    //calculating sums
    for (int n = 0; n < size; n++)
    {
        sum_x += arr_x[n];
        sum_y += arr_y[n];
        sum_x2 += (pow(arr_x[n], 2));
        sum_xy += (arr_x[n] * arr_y[n]);
        sum_init_y += arr_y_init[n];
    }

    //calculating slope and intercept
    slope = ((size * sum_xy) - (sum_x * sum_y)) / ((size * sum_x2) - pow(sum_x, 2));

    intercept = exp(((sum_y / size) - (slope * (sum_x / size))));

    //displaying tabular data with error calculated
    cout << "Slope is---\t" << slope << endl;
    cout << "Intercept is---\t" << intercept << endl;

    // for cc
    float y_bar = 0, Sy = 0, S = 0, cc = 0, temp = 0, temp2 = 0;

    y_bar = sum_init_y / size;

    for (int m = 0; m < size; m++)
    {
        Sy += pow((arr_y_init[m] - y_bar), 2);
        temp2 = intercept * (exp(slope * arr_x_init[m]));
        S += pow((arr_y_init[m] - temp2), 2);
    }

    temp = (Sy - S) / Sy;
    cc = pow(temp, 0.5);

    cout << "Corelation Coefficient is ---\t" << cc << endl;
    cout << "\n----------------------------------------------\n";

    cout << "\n---------------------------------------------------------------\n";

    cout << "X"
         << "\t|\t"
         << "Y"
         << "\t|\t"
         << "Y_CAL"
         << "\t|\t"
         << "ERROR" << endl;
    cout << "---------------------------------------------------------------\n";

    double y_calc = 0, error = 0;

    for (int w = 0; w < size; w++)
    {
        y_calc = (intercept * (exp(arr_x_init[w] * slope)));
        error = round((arr_y_init[w]) - y_calc);
        cout << arr_x_init[w] << "\t|\t" << arr_y_init[w] << "\t|\t" << y_calc << "\t|\t" << error << endl;
    }
    cout << "---------------------------------------------------------------\n\n";
    system("echo Thanks!!!");
}

double round(double var)
{
    double value = (int)(var * 100000 + .5);
    return (double)value / 100000;
}