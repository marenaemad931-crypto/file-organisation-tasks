
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    int grade;
    int deleteGrade;
    bool found = false;

    ofstream outFile("grades.txt");

    if (!outFile)
    {
        cout << "Error creating file!";
        return 1;
    }

    cout << "Enter 5 grades:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> grade;
        outFile << grade << endl;
    }

    outFile.close();

    ifstream inFile("grades.txt");

    if (!inFile)
    {
        cout << "Error opening file!";
        return 1;
    }

    cout << "\nGrades before deletion:" << endl;

    while (inFile >> grade)
    {
        cout << grade << endl;
    }

    inFile.close();

    cout << "\nEnter the grade you want to delete: ";
    cin >> deleteGrade;

    ifstream originalFile("grades.txt");
    ofstream tempFile("temp.txt");

    if (!originalFile || !tempFile)
    {
        cout << "Error opening files!";
        return 1;
    }

    while (originalFile >> grade)
    {
        if (grade != deleteGrade)
        {
            tempFile << grade << endl;
        }
        else
        {
            found = true;
        }
    }

    originalFile.close();
    tempFile.close();

    if (found)
    {
        if (remove("grades.txt") == 0 &&
            rename("temp.txt", "grades.txt") == 0)
        {
            cout << "\nGrade deleted successfully!" << endl;
        }
        else
        {
            cout << "\nError replacing file!" << endl;
        }
    }
    else
    {
        remove("temp.txt");
        cout << "\nGrade not found!" << endl;
    }

    ifstream finalFile("grades.txt");

    if (finalFile)
    {
        cout << "\nGrades after deletion:" << endl;

        while (finalFile >> grade)
        {
            cout << grade << endl;
        }

        finalFile.close();
    }

    return 0;
}

