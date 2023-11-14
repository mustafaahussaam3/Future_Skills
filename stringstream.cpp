#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std ; 

void printFrequency(string st){

    map<string,int>m;

    stringstream ss(st);
    string word ; 

    while (ss >> word){
        cout << word << endl ;
        m[word]++ ; 
    }

    map<string,int>::iterator it;
    for (it = m.begin() ; it != m.end(); ++it){
        cout << it->first << " " << it->second<<endl;
    }
}





int main (){

    string s = "Hello Mustafa Hussam Mustafa Hussam " ;
    printFrequency(s);
    return 0;

}
