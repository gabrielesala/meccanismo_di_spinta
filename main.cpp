using namespace std;


#include <iostream>
#include <string>
#include "../meccanismo_di_spinta/library/mds.h"


int main(){
    
    int risp;
    mgCatapult* catapulta;
    string cat;

    cout << "Choose an option:" << endl;
    cout << "[1] Create a new catapult" << endl;
    cout << "[2] Save catapult as a svg file" << endl;
    cout << "[3] Delete a previously created catapult" << endl;
    cout << "[4] Load a catapult" << endl;
    cout << "[5] Exit the program" << endl;  

    cin >> risp;

    while(risp!=5){
        switch (risp)
        {
        case 1:
            mg_init_mds(mds);
            cat = mg_catSVG(catapulta);
            break;
        case 2:
            mg_filew(cat);
            break;
        case 3:
            //lancia fun per eliminare un file svg
            break;
        case 4:
            //lancia fun per caricare un file svg
            break;
        case 5:
            cout << "Program ended" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
return 0;
}