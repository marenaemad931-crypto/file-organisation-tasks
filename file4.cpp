#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct person {
string name;
int age;
};

int main()
{
   int n;
   cout<< "Enter How many person you want to add: ";
   cin>>n;

   ofstream outfile("perspn.txt");
   if(!outfile){
   cout<<"Error openning file for waiting!"<<endl;
   return 1;
   }

for(int i=0; i<n; i++){
    string name;
    int age;
    cout<<"Enter name for person "<<i+1<<": ";
    cin>>name;
    cout<<"Enter age for person"<<i+1<<": ";
    cin>>age;

    outfile << name << " " << age << endl;

}
outfile.close();
cout<< "\nData saved successfully to 'person.txt'.\n"<<endl;

ifstream infile("person.txt");
if(!infile){
    cout<<"Error openning file for reading!"<<endl;
    return 1;
}

vector<person> persons;
person p;

while (infile>> p.name >> p.age){
    persons.push_back(p);
}
infile.close();

if (persons.empty()){
    cout<<"No data found in the file. " << endl;
    return 0;
}

person youngest= persons[0];
person oldest = persons[0];

for(size_t i=1; i<persons.size(); i++){
    if(persons[i].age < youngest.age){
        youngest=persons[i];
    }
    if(persons[i].age > oldest.age){
        oldest= persons[i];
    }
}

ofstream resultsfile("results.txt");
if(!resultsfile){
    cout<< "Error openning results file for writing!"<<endl;
    return 1;
}

resultsfile << "youngest person: "<<youngest.name<<" (" << youngest.age<<" years old)\n";
resultsfile <<"Oldest person: " <<oldest.name<<" (" << oldest.age<<" years old)\n";
resultsfile.close();

cout<<"Results (youngest and oldest persons) saved to 'result.txt'." <<endl;

   return 0;
}





