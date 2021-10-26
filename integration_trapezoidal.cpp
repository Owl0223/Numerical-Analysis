#include <iostream>

using namespace std;

int main()
{
    system("cls");
    int size;
    cout << "Enter the size of data:\t";
    cin >> size;

    double arr[size][2];

    cout << "Enter x data :-\n----------------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i][0];
    }

    cout << "\n\nEnter y data :-\n----------------------------------------------\n";
    for (int j = 0; j < size; j++)
    {
        cin >> arr[j][1];
    }
    cout << "\n\n";

    //displaying values
    cout << "Seq\tx\ty" << endl;
    cout << "-------------------------------\n";
    for (int a = 0; a < size; a++)
    {
        cout << a << "\t";
        for (int b = 0; b < 2; b++)
        {
            cout << arr[a][b] << "\t";
        }
        cout << endl;
    }

    //if user wants integration over a particular region
    bool choice;
    int start = 0, end = size - 1;
    cout << "Do you want to integrate over a specific region? If yes then enter 0 else 1:\t";
    cin >> choice;
    if (!choice)
    {
        cout << "Enter the index of start and end value with space:\t";
        cin >> start >> end;
    }

    //integration
    double temp, h, delta;

    h = arr[1][0] - arr[0][0];
    delta = arr[start][1] + arr[end][1];

    for (int k = start + 1; k < end; k++)
    {
        delta += 2 * arr[k][1];
    }

    temp = (h / 2) * delta;
    cout << "The value of integration is:\t" << temp << endl;

    system("echo Thanks!!!");
}