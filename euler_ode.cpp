#include <iostream>

using namespace std;

double f(double, double);
double round(double);

int main()
{
    system("cls");
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;
    double x[n + 1], y[n + 1], h, del, temp = 0;

    cout << "\nEnter x0, y0, x(n): ";
    cin >> x[0] >> y[0] >> x[n];

    h = round((x[n] - x[0]) / n);

    for (int a = 1; a < n; a++)
        x[a] = x[0] + a * h;

    for (int i = 0; i < n; i++)
        y[i + 1] = y[i] + round(h * f(x[i], y[i]));

    cout << "\n\nSeq\tx\ty\n-------------------------------------\n";
    for (int j = 0; j <= n; j++)
        cout << j << "\t" << x[j] << "\t" << y[j] << "\t" << endl;
}

double f(double x, double y)
{
    return x*x + y;
}

double round(double var)
{
    double value = (int)(var * 100000 + .5);
    return (double)value / 100000;
}