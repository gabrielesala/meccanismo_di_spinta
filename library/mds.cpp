using namespace std;
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include "../library/mds.h"

int mds_inspect(mds* mds){  // funzione che controlla i parametri
    int ins;
    double max_pl = 1/2 * Lb;  // definisco la lunghezza massima del pistone
    if (mds -> Dm > 0 && 
        mds -> Lm > 0 &&
        mds -> Lp > 0 &&
        mds -> Lb > 0 &&
        mds -> Hp > 0 &&
        mds -> alfa > 0)
    {ins = 0;}
    if (mds -> Lm sin(alfa) > Lb){  // imposto il primo constrain
        cout << "Error 101! The baricenter's position value has to be lower than the length of the chassis, so < than " << Lb << endl;
    ins = 101;
    }

    if (mds-> Lm cos(alfa) >= 1/2 Hp){ // imposto il secondo constrain
        cout << "Error 102! The vertical length of the cranck " << endl;}
    ins = 102;

    if (mds-> Lp <= max_pl){  // imposto l'ultimo constrain
        cout << "Error 103! The length of the piston has to be lower than 1/2 of the chassis length, so < than " << max_pl << endl;}
    ins = 103;

    return ins;
}



string mds_to_svg(mds* mds){   // definizione file svg (ERROR, da sistemare)
    string defxml;
    defxml =  "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">\n\n";
    string rect1;
    rect1 = "<rect width=\""750"": // blocked values
    rect1 += "height="150"";
    rect1 += "transform="translate(50,100)"";
    rect1 += "style="fill:rgb(0,0,255);stroke-width:3;stroke:rgb(0,0,255)\"/> \n";
    
    
    string cranck;
    cranck = "<rect x="+ to_string(50 + Lm/2 cos(alfa+ 3/2 Pi))"";
    cranck += "y="+ to_string(100 + Lm/2 Sin(alfa+ 3/2 Pi))"";
    cranck += "width="+ to_string(Lm)""; 
    cranck += "height=\"+ to_string(Lp";
    cranck += "transform="rotate(alfa - 90 Pi)" /> \n";

    string piston;
    piston = "<rect x="+ to_string(50 + Lm cos(alfa+ 3/2 Pi))"";
    piston += "y="+ to_string(100 + Lm/2 sin(alfa+ 3/2 Pi))"";
    piston += "width="+ to_string(Lp)";
    piston += "height="+ to_string(Hp)/>\n";


    string circle2;
    circle1 = "<circle cx="50 + Lm cos(alfa+ 3/2 Pi)" cy="100 + Lm/2 sin(alfa+ 3/2 Pi)" r="30" stroke="black" stroke-width="3" fill="red" /> \n";

    string rect2;
    rect2 = "<rect width="750"";
    rect2 += "height="150"";
    rect2 += "transform="translate(50, + to_string =(100 + Lm sin(alfa) + 2 Hp))"";
    rect2 += "style="fill:rgb(0,0,255);stroke-width:3;stroke:rgb(0,0,255)\" /> \n";

    string circle1;
    circle1 = "<circle cx="50" cy="100" r="30" stroke="black" stroke-width="3" fill="red" /> \n";

    string mds_to_svg = rect1 + cranck + piston + circle2 + rect2 + circle1;
    return mds_to_svg;

    }


void mg_filew(string mds_to_svg){

    if(mds_to_svg == "") {
        cout << "ERROR";
    }
    if(mds_to_svg != ""){
        string name;

        cout << "You have now to choose the name for your file" << endl;
        cin >> name;

        // Create and open a text file
        ofstream MyFile(name);

        // Write to the file
        MyFile << mds_to_svg;

        // Close the file
        MyFile.close();
    }
}



void init_mds(mds* mds){
    while(true){
        cout << "Define crank width:";
        cin >> mds -> Dm;
        cout << "Define crank length";
        cin >> mds -> Lm;
        cout << "Define piston length:";
        cin >> mds -> Lp;
        cout << "Define chassis length";
        cin >> mds -> Lb;
        cout << "define piston width: ";
        cin >> mds -> Hp;
        cout << "Define crank's angle:";
        cin >> mds -> alfa;

        if ( mds_inspect(mds* mds)){

            mds_to_svg(mds* mds);
            return;
        }
    }
}