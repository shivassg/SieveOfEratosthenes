
/* 
 * File:   Main.cpp
 * Author: Shiva Shankar Ganesan
 * Created on October 5, 2018
 * Compiler Used: g++
 * Description of the file: Driver file which reads the input file and sets the number and mode 
 */

#include <cstdlib>
#include <iostream>
#include<fstream>
#include<map>
#include"sieveOfEratosthenes.h"

using namespace std;

int main() {
 
    
 sieveOfEratosthenes object;
 ifstream in("test10.txt");
 if(in.fail()){
     cout<<"Your file didn't work"<< std::strerror(errno);
 }
 else{
     string s;
     int n;
     string mode;
     
     while (!in.eof()){
        getline(in,s);
        size_t pos=s.find(" ");
        n = atoi(s.substr(0, pos).c_str());
        mode = s.substr(pos + 1);
        object.setInput(n,mode);
        cout<< "N value=" << n<<endl;
        object.compute();
        object.freeSteps();
        cout<<endl;
     }
 }
 
in.close();

    return 0;
}
