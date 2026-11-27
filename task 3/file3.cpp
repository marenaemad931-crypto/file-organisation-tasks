#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream file("welcome.txt");
    file<< "Hello Everybody";
    file.close();

    fstream infile("Welcome.txt",ios::in | ios::out);
    string text;

    infile.seekg(0,ios::end);
    int size= infile.tellg();

    infile.seekg(0,ios::beg);
    getline(infile,text);
    infile.close();

    cout<<"Hello Everybody";
    return 0;
}
