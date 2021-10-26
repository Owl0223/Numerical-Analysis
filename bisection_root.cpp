#include <iostream>
#include <iomanip>
#include <functional>
#include <math.h>
using namespace std;

double round(double);
double func(int, double, double[]);
double interval(int, double[], function<double(int, double, double[])>, double &);

int main()
{
    system("cls");
    int degree;
    cout << "Enter degree of polynomial\t[with spaces]\n";
    cout << "-----------------------------------------------------------\n";
    cin >> degree;
    cout << "-----------------------------------------------------------\n\n";

    double a = 0, b = 0, coefs[degree + 1], xr = 0, prod = 0;

    cout << "Enter coeffecients of polynomial in increasing order <with spaces>\n";
    cout << "-----------------------------------------------------------\n";
    for (int i = 0; i <= degree; i++)
    {
        cin >> coefs[i];
    }
    cout << "\n--------------------------------------------------------------------------------\n";
    a = interval(degree, coefs, &func, b);

    double temp_b = b, temp_a = a;

    // if ((func(degree, a, coefs)) * (func(degree, b, coefs)) > 0)
    // {
    //     system("echo 'Wrong input of interval!'");
    //     return 0;
    // }

    int i = 0;
    cout << "Seq"
         << "\t|\t"
         << "a"
         << "\t|\t"
         << "b"
         << "\t|\t"
         << "Xr"
         << "\t|\t"
         << "f(a).f(Xr)\n";
    cout << "--------------------------------------------------------------------------------\n";
    while (true)
    {
        i++;
        xr = (temp_a + temp_b) / 2;
        prod = round((func(degree, temp_a, coefs)) * (func(degree, xr, coefs)));
        cout << i << "\t|\t" << temp_a << "\t|\t" << temp_b << "\t|\t" << xr << "\t|\t" << prod << endl;

        if (prod < 0)
        {
            temp_b = xr;
        }
        else if (prod > 0)
        {
            temp_a = xr;
        }
        else
        {
            break;
        }
    }
    cout << "--------------------------------------------------------------------------------\n\n";

    cout << "Root is\t"
         << round(xr)
         << "\t|\tf(root) =\t"
         << round(func(degree, round(xr), coefs))
         << endl;
    system("echo Thanks!!!");
}

//My functions
double round(double var)
{
    double value = (int)(var * 10000000 + .5);
    return (double)value / 10000000;
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

double interval(int degree, double coefs[], function<double(int, double, double[])> func, double &start)
{
    int i = 0;
    double temp = 0, tempx = start, root = 0;
    if (func(degree, start, coefs) < 0)
    {
        while (true)
        {
            if (func(degree, tempx, coefs) < 0)
            {
                tempx += 0.05;
            }
            else if (func(degree, tempx, coefs) > 0)
            {
                temp = tempx - 0.05;
                break;
            }
            else
            {
                root = tempx;
                break;
            }
        }
    }
    else if (func(degree, tempx, coefs) > 0)
    {
        while (true)
        {
            if (func(degree, tempx, coefs) > 0)
            {
                tempx -= 0.05;
            }
            else if (func(degree, tempx, coefs) < 0)
            {
                temp = tempx + 0.05;
                break;
            }
            else
            {
                root = tempx;
                break;
            }
        }
    }
    else
    {
        root = start;
    }
    start = tempx;
    return temp;
}