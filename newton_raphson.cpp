#include <iostream>
#include <math.h>
using namespace std;

enum choice
{
    yes,
    no
};
double round(double);
double func(int, double, double[]);
double derivative(int, double, double[]);

int main()
{
    system("cls");
    int degree, i = 1, xc;
    enum choice xchoice;
    cout << "Enter degree of polynomial\t";
    cin >> degree;
    cout << "----------------------------------------------\n";

    double x, coefs[degree + 1], h, acc;
    cout << "You wanna enter value of x?\t[0 for yes | 1 for no]\t";
    cin >> xc;
    cout << "----------------------------------------------\n";

    xchoice = (choice)xc;

    if (xchoice == yes)
    {
        cout << "Enter x\t";
        cin >> x;
        cout << "----------------------------------------------\n";
    }
    else if (xchoice == no)
    {
        x = 0;
    }

    cout << "Enter epsilon\t";
    cin >> acc;
    cout << "----------------------------------------------\n";

    cout << "Enter coefs in increasing order\t[with spaces]\n";
    cout << "----------------------------------------------\n";

    for (int j = 0; j <= degree; j++)
    {
        cin >> coefs[j];
    }
    cout << "\n----------------------------------------------\n";

    h = func(degree, x, coefs) / derivative(degree, x, coefs);

    cout << "Seq"
         << "\t|\t"
         << "x"
         << "\t|\t"
         << "h" << endl;
    cout << "----------------------------------------------\n";

    while (true)
    {
        h = func(degree, x, coefs) / derivative(degree, x, coefs);
        cout << i << "\t|\t" << x << "\t|\t" << h << endl;
        if (fabs(round(h)) <= acc)
            break;
        x -= h;
        i++;
    }
    cout << "----------------------------------------------\n\n";

    cout << "Root is\t" << x << "\nNumber of iteations is\t" << i << endl;
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