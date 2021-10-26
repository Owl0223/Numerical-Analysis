#include <iostream>
#include <math.h>
using namespace std;

double round(double);
double func(int, double, double[]);
double derivative(int, double, double[]);

int main()
{
    system("cls");
    int i = 1, j = 1, degree;
    cout << "----------------------------------------------\n";
    cout << "Enter degree of polynomial\t";
    cin >> degree;

    double x0, h, h2, acc, temp_x0, coefs[degree + 1];
    cout << "----------------------------------------------\n";
    cout << "Enter guess root(for double root),guess root(for single root)  and epsilon\n";
    cin >> x0 >> temp_x0 >> acc;
    cout << "----------------------------------------------\n";

    cout << "Enter coefs in increasing order\t[with spaces]\n";
    cout << "----------------------------------------------\n";

    for (int k = 0; k <= degree; k++)
    {
        cin >> coefs[k];
    }
    cout << "\n----------------------------------------------\n";
    cout << "\nFor double root :-\n\n";

    cout << "Seq"
         << "\t|\t"
         << "x"
         << "\t|\t"
         << "h" << endl;
    cout << "----------------------------------------------\n";

    while (true)
    {
        h = x0 - 2 * (func(degree, x0, coefs) / derivative(degree, x0, coefs));
        cout << i << "\t|\t" << round(x0) << "\t|\t" << h << endl;
        if (fabs(round(h - x0)) <= acc)
            break;
        x0 = h;
        i++;
    }
    cout << "----------------------------------------------\n\n";

    cout << "\nFor single root :-\n\n";

    cout << "Seq"
         << "\t|\t"
         << "x"
         << "\t|\t"
         << "h" << endl;
    cout << "----------------------------------------------\n";

    while (true)
    {
        h2 = temp_x0 - (func(degree, temp_x0, coefs) / derivative(degree, temp_x0, coefs));
        cout << j << "\t|\t" << round(temp_x0) << "\t|\t" << h2 << endl;
        if (fabs(round(h2 - temp_x0)) <= acc)
            break;
        temp_x0 = h2;
        j++;
    }
    cout << "----------------------------------------------\n\n";

    cout << "Single Root is\t" << temp_x0 << "\nDouble root is" << x0 << "\nNumber of iteations for single root is\t" << j << "\nNumber of iteations for double root is\t" << i << "\n\n";
    system("echo Thanks!!!");
}

double round(double var)
{
    double value = (int)(var * 1000000 + .5);
    return (double)value / 1000000;
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
double derivative(int degree, double x, double coefs[])
{
    double value = 0;
    for (int i = 1; i <= degree; i++)
    {
        value += (pow(x, i - 1) * coefs[i]) * i;
    }
    return value;
}
