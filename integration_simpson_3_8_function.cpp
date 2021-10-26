#include <iostream>
#include <math.h>

using namespace std;

double round(double, int);
double func(int, double, double[]);

int main()
{
    system("cls");
    cout<<"###########~~~~~Simpson 3/8 Integration~~~~~###########\n";
    int degree, n;
    cout << "Enter degree of polynomial:\t";
    cin >> degree;
    cout << "-----------------------------------------------------------\n";

    double start = 0, end = 0, coefs[degree + 1], h;

    cout << "Enter coeffecients of polynomial in increasing order <with spaces>\n";
    cout << "-----------------------------------------------------------\n";
    for (int i = 0; i <= degree; i++)
    {
        cin >> coefs[i];
    }

    cout << "Enter lower limit, upper limit, and number of intervals <with spaces>\n";
    cout << "-----------------------------------------------------------\n";
    cin >> start >> end >> n;

    h = (end - start) / n;

    double x[n + 1], y[n + 1];

    for (int j = 0; j <= n; j++)
    {
        x[j] = round(start + j * h, 3);
        y[j] = round(func(degree, x[j], coefs), 5);
    }

    cout << "\nSeq\tx\t\ty\n";
    cout << "----------------------------------------\n";
    for (int k = 0; k <= n; k++)
        cout << k << "\t" << x[k] << "\t\t" << y[k] << endl;

    cout << "----------------------------------------\n";

    double temp, delta;

    delta = y[0] + y[n];

    for (int k = 1; k < n; k ++)
    {
        if (k % 3 == 0)
        {
            delta += 2 * y[k];
        }
        else
        {
            delta += 3 * y[k];
        }
    }

    temp = ((3 * h) / 8) * delta;

    cout << "\nThe value of integration is:\t" << temp << endl;
    system("echo Thanks!!!");
}

//My functions
double round(double var, int points)
{
    double value = (int)(var * pow(10, points) + .5);
    return (double)value / pow(10, points);
}

double func(int degree, double x, double coefs[])
{
    double value = 0;

    for (int i = 0; i <= degree; i++)
    {
        value += (pow(x, i) * coefs[i]);
    }
    return value;
}