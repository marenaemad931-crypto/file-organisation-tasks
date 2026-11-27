#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

int main()
{
    char name[20];
    int id;
    float grade;
    char choice;
    char delim = '$';


    ofstream file("students.txt", ios::app);

    if (!file)
    {
        cout << "Error opening file!";
        return 1;
    }

    do
    {
        cout << "Enter student name: ";
        cin >> ws;
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;


        file << name << ", " << id << ", "
             << grade << " " << delim << endl;

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    file.close();

    cout << "Student records saved successfully!";

    return 0;
}

