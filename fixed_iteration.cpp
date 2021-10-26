#include <iostream>
#include <math.h>
using namespace std;

double round(double);
double func(double);
double inverse(double);

int main()
{
    system("cls");
    int i = 1;
    double x0, x = 0, epsilon;
    cout << "Enter guess root and accuracy\t[with spaces]\n";
    cout << "-------------------------------------\n";
    cin >> x0 >> epsilon;
    cout << "\n------------------------------------------------------------------\n";
    cout << "Seq\t\tx0\t\tx\t\tfx\n";
    cout << "------------------------------------------------------------------\n";
    while (true)
    {
        x = round(inverse(x0));
        cout << i << "\t\t" << x0 << "\t\t" << x << "\t\t" << round(func(x)) << endl;
        if (fabs(round(func(x))) <= epsilon)
            break;
        x0 = x;
        i++;
    }
    cout << "\nRoot is\t| " << x << "\nNumber of iterations is\t| " << i << "\n\n";
}

//my functions
double round(double var)
{
    double value = (int)(var * 1000000 + .5);
    return (double)value / 1000000;
}

double func(double x)
{
    return x * x * x + -2 * x - 5;
}

double inverse(double x)
{
    return cbrt(2 * x + 5);
}