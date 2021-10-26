#include <iostream>
#include <math.h>
using namespace std;

double round(double);
double func(int, double, double[]);

int main()
{
    system("cls");
    int i = 1, degree;
    double x0, x1, x2, numer, denom, epsilon;
    cout << "Enter degree of polynomial\t";
    cin >> degree;
    cout << "-------------------------------------------\n\n";
    double coefs[degree + 1];
    cout << "Enter coefs in increasing order\t[with spaces]\n";
    cout << "-------------------------------------------\n";

    for (int i = 0; i <= degree; i++)
    {
        cin >> coefs[i];
    }
    cout << "-------------------------------------------\n\n";

    cout << "Enter values of x0, x1 and accuracy\t[with spaces]\n";
    cout << "-------------------------------------------\n";
    cin >> x0 >> x1 >> epsilon;
    cout << "\n--------------------------------------------------------------------------------\n";

    cout << "seq\t\tx0\t\tx1\t\tx2\t\tfx2\n";
    cout << "--------------------------------------------------------------------------------\n";
    while (true)
    {

        numer = (x0 * func(degree, x1, coefs)) - (x1 * func(degree, x0, coefs));
        denom = func(degree, x1, coefs) - func(degree, x0, coefs);
        x2 = numer / denom;
        cout << i << "\t\t" << x0 << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << round(func(degree, x2, coefs)) << endl;
        x0 = x1;
        x1 = x2;
        if (fabs(round(func(degree, x2, coefs))) <= epsilon)
            break;
        i++;
    }
    cout << "\n--------------------------------------------------------------------------------\n";

    cout << "root is\t| "
         << x2
         << "\n number of iterations is\t| "
         << i
         << "\n\n";
    system("echo Thanks!!!");
}

//my functions
double round(double var)
{
    double value = (int)(var * 100000 + .5);
    return (double)value / 100000;
}

double func(int degree, double x, double coefs[])
{
    double value = 0;

    for (int i = 0; i <= degree; i++)
    {
        value += (pow(x, i) * coefs[i]);
    }
    // return x*sin(x)+cos(x);
    return value;
}
