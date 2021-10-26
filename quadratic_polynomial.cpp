#include <iostream>
#include <math.h>

using namespace std;

double det(double[3][3]);
double round(double);

int main()
{
    system("cls");
    int size;
    cout << "Enter size of arrays:    ";
    cin >> size;

    //arrays
    double arr_x[size], arr_y[size], sum_x = 0, sum_y = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, sum_xy = 0, sum_x2y = 0, arr_x_init[size], arr_y_init[size];

    cout << "Enter the elements for X\t[With a space in between]\n----------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr_x[i];
        arr_x_init[i] = arr_x[i];
    }
    cout << "----------------------------------------------\n\n";

    cout << "Enter the elements for Y\t[With a space in between]\n----------------------------------------------\n";
    for (int j = 0; j < size; j++)
    {
        cin >> arr_y[j];
        arr_y_init[j] = arr_y[j];
    }
    cout << "----------------------------------------------\n\n";

    for (int k = 0; k < size; k++)
    {
        sum_x += arr_x[k];
        sum_y += arr_y[k];
        sum_x2 += (pow(arr_x[k], 2));
        sum_x3 += (pow(arr_x[k], 3));
        sum_x4 += (pow(arr_x[k], 4));
        sum_xy += (arr_x[k] * arr_y[k]);
        sum_x2y += (pow(arr_x[k], 2) * arr_y[k]);
    }

    //solving the varuables

    double mat[3][3];

    //entering data to matrix
    mat[0][0] = size;
    mat[0][1] = sum_x;
    mat[0][2] = sum_x2;
    mat[1][0] = sum_x;
    mat[1][1] = sum_x2;
    mat[1][2] = sum_x3;
    mat[2][0] = sum_x2;
    mat[2][1] = sum_x3;
    mat[2][2] = sum_x4;

    // Solving variables
    double det_mat = 0, D = 0, temp = 0, var[3], mat_temp[3][3];
    det_mat = det(mat);

    for (int m = 0; m < 3; m++)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                mat_temp[x][y] = mat[x][y];
            }
        }

        mat_temp[0][m] = sum_y;
        mat_temp[1][m] = sum_xy;
        mat_temp[2][m] = sum_x2y;

        temp = det(mat_temp);
        D = temp / det_mat;
        var[m] = D;
    }
    cout << "a0 is ---\t" << var[0]
         << "\na1 is ---\t" << var[1]
         << "\na2 is ---\t" << var[2]
         << endl;
    // for cc
    double y_bar = 0, Sy = 0, S = 0, cc = 0, temp1 = 0, temp2 = 0;

    y_bar = sum_y / size;

    for (int m = 0; m < size; m++)
    {
        Sy += pow((arr_y_init[m] - y_bar), 2);
        temp2 = var[0] + var[1] * arr_x_init[m] + var[2] * arr_x_init[m] * arr_x_init[m];
        S += pow((arr_y_init[m] - temp2), 2);
    }

    temp1 = (Sy - S) / Sy;
    cc = pow(temp1, 0.5);

    cout << "Corelation Coefficient is ---\t" << cc << endl;
    cout << "\n----------------------------------------------\n";

    cout << "\n------------------------------------------------------------\n";

    cout << "X"
         << "\t|\t"
         << "Y"
         << "\t|\t"
         << "Y_CAL"
         << "\t|\t"
         << "ERROR" << endl;
    double y_calc = 0, error = 0;

    cout << "------------------------------------------------------------\n";

    for (int q = 0; q < size; q++)
    {
        y_calc = (double)(var[0]) + (var[1] * arr_x_init[q]) + (var[2] * pow(arr_x_init[q], 2));
        error = (arr_y_init[q] - y_calc);
        cout << arr_x_init[q] << "\t|\t" << arr_y_init[q] << "\t|\t" << y_calc << "\t|\t" << round(error) << endl;
    }
    cout << "------------------------------------------------------------\n\n\n";
    system("echo Thanks!!!");
}

double det(double mat[3][3])
{
    double cf1, cf2, cf3, D;

    cf1 = (mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1]);
    cf2 = (mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0]);
    cf3 = (mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0]);

    D = mat[0][0] * cf1 - mat[0][1] * cf2 + mat[0][2] * cf3;

    return D;
}

double round(double var)
{
    double value = (int)(var * 100000 + .5);
    return (double)value / 100000;
}