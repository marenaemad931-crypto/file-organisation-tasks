#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main()
{
    int x;
    cout << "Enter number of persons: ";
    cin >> x;

    ofstream out("persons.txt");
    if (!out.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    for (int i = 0; i < x; i++) {
        Person A;
        cout << "Enter name of person: " << i + 1 << ": ";
        cin.ignore();
        getline(cin, A.name);

        cout << "Enter age of person: " << i + 1 << ": ";
        cin >> A.age;

        out << A.name << endl;
        out << A.age << endl;
    }
    out.close();

    ifstream in("persons.txt");
    if (!in.is_open()) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    vector<Person> pep;
    Person tem;

    while (getline(inF, tem.name)) {
        in >> tem.age;
        in.ignore();
        people.push_back(tem);
    }
    in.close();

    if (!pep.empty()) {
        Person youngest = pep[0];
        Person oldest = pep[0];

        for (int i = 1; i < pep.size(); i++) {
            if (pep[i].age < youngest.age) {
                youngest = pep[i];
            }
            if (pep[i].age > oldest.age) {
                oldest = pep[i];
            }
        }

        ofstream res("results.txt");
        if (res.is_open()) {
            res << "Youngest Person: " << youngest.name << " (" << youngest.age << " years old)" << endl;
            res << "Oldest Person: " << oldest.name << " (" << oldest.age << " years old)" << endl;
            res.close();
            cout << "Results saved successfully to results.txt!" << endl;
        }
    }

    return 0;
}





