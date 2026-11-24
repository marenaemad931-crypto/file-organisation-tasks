#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string names[4] = {
        "Hadeer Mahmoud",
        "Youssef Ali",
        "Ahmed Mostafa",
        "Esraa Ebrahim"
    };

    string temp;

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (names[i] > names[j])
            {
                temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }

    cout << "Names in ascending order:" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << names[i] << endl;
    }

    return 0;
}
