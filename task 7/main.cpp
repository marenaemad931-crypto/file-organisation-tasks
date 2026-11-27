#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ofstream outFile("names.txt");
    outFile << "Hadeer Mahmoud" << endl;
    outFile << "Youssef Ali" << endl;
    outFile << "Ahmed Mostafa" << endl;
    outFile << "Esraa Ebrahim" << endl;
    outFile.close();

    ifstream inFile("names.txt");
    if(!inFile){
        cout << "Error opening file!" << endl;
        return 1;
    }

    vector<string> names;
    string line;
    while(getline(inFile,line)){
        names.push_back(line);
    }

    sort(names.begin(),names.end());

    cout << "Names sorted in ascending order:" << endl;
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }
    return 0;
}

