using namespace std;

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <streambuf>
#include <sstream>
#include "../meccanismo_di_spinta/include/mds.h"


int main(){
    // Define the possible options available to the user
    cout << "Choose an option:" << endl;
    cout << "Define and create a new crankshaft {1}" << endl;
    cout << "Save the created crankshaft as a svg type file {2}" << endl;
    cout << "Shutdown the current task {3}" << endl; 
    int opt;
    cin >> opt;
    choose_option(opt);
return 0;
}
