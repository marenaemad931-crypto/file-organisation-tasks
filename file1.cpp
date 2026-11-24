#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string fullname;
    int ID;
    double grade;

    cout<< "enter full name: ";
    getline(cin, fullname);

    cout<< "enter ID: ";
    cin>>ID;

    cout<< " enter grade: ";
    cin>>grade;

    ofstream file("student.txt");

    file<< "full name: " << fullname <<endl;
    file<< "ID: " << ID << endl;
    file<< "Grade: "<< grade<<endl;

    file.close();

    cout<< "Student data saved successfully!"<< endl;

    return 0;
}
