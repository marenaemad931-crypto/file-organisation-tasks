#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
   string fruit;

   ifstream infile("fruit.txt");

   if(infile.is_open()){

    while(getline(infile,fruit)){

        cout<< fruit << endl;
    }

    infile.close();

   }

   ofstream outfile("fruit.txt", ios::app);

   if(outfile.is_open()){

    outfile << "fresh fruits" << endl;
    outfile.close();

   }

    return 0;
}
