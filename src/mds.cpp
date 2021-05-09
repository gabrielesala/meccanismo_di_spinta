#include <iostream>
#include <string.h>
#include <cmath>
#include <fstream>
#include <string>
#include "../include/mds.h"

using namespace std;

int mds_inspect(mds* mds){  // funzione che controlla i parametri
    int ins;
    double max_pl = 1/2 * (mds->Lb);  // define max piston length
    if (mds -> Dm > 0 && 
        mds -> Lm > 0 &&
        mds -> Lp > 0 &&
        mds -> Lb > 0 &&
        mds -> Hp > 0 &&
        mds -> alfa > 0)
    {ins = 0;}

    // first constrain set
    if ((mds -> Lm) * sin((mds->alfa)) > (mds->Lb))
    {  
        cout << "Error 101! The baricenter's position value has to be lower than the length of the chassis, so < than " << (mds->Lb) << endl;
    ins = 101;
    }

    // second constrain set
    if ((mds-> Lm) * cos((mds->alfa)) >= 1/2 * (mds->Hp))
    { 
        cout << "Error 102! The vertical length of the cranck " << endl;}
    ins = 102;

    // last constrain set
    if ((mds-> Lp) <= max_pl){  
        cout << "Error 103! The length of the piston has to be lower than 1/2 of the chassis length, so < than " << max_pl << endl;}
    ins = 103;

    return ins;
}



string mds_to_svg(mds* mds){   //define svg file code, crankshaft chosen properties are added to the svg file 
    string defxml;
    defxml =  "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"600\">\n\n";

    string rect1; //defining the higher part of the static chassis
    rect1 = "<rect width=\"750\"";
    rect1 += " height=\" 150";
    rect1 += " transform=\"translate(50,100)";
    rect1 += " style=\"fill:rgb(0,0,255)stroke-width:3 stroke:rgb(0,0,255)\"/> \n";
    
    
    string cranck;  //defining cranck svg code
    cranck = "<rect x=\""+ to_string(50 + (mds->Lm)/2 * cos((mds->alfa)+ 3/2 * 3.14))+"\"";
    cranck += "y=\""+ to_string(100 + (mds->Lm)/2 * sin((mds->alfa)+ 3/2 * 3.14))+"\"";
    cranck += "width=\""+ to_string((mds->Lm)); 
    cranck += "height=\""+ to_string((mds->Lp));
    cranck += "transform=\"rotate("+ to_string((mds->alfa) - 90 * 3.14)+ "/> \n";

    string piston;  //defining piston svg code
    piston = "<rect x=\""+ to_string(50 + (mds->Lm) * cos((mds->alfa)+ 3/2 * 3.14))+"\"";
    piston += "y=\""+ to_string(100 + (mds->Lm)/2 * sin((mds->alfa)+ 3/2 * 3.14))+"\"";
    piston += "width=\""+ to_string((mds->Lp))+"\"";
    piston += "height=\""+ to_string((mds->Hp)) + "/> \n";


    string circle2;  //defining second rotational couple svg code
    circle2 = "<circle cx=\"" + to_string(50 + (mds->Lm) * cos((mds->alfa) + 3/2 * 3.14)) + "\"+ cy=\""+to_string(100 + (mds->Lm)/2 * sin((mds->alfa)+ 3/2 * 3.14)) + "r=\"30\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" /> \n";

    string rect2; //defining the lower part of the static chassis
    rect2 = "<rect width=\"750\"";
    rect2 += "height=\"150\"";
    rect2 += "transform=\"translate(\"50," + to_string(100 + (mds->Lm) * sin((mds->alfa)) + 2 * (mds->Hp)) + "\"";
    rect2 += "style=\"fill:rgb(0,0,255);stroke-width:3;stroke:rgb(0,0,255)\" /> \n";

    string circle1; //defining first rotational couple svg code
    circle1 = "<circle cx=\"50\" cy=\"100\" r=\"30\" stroke=\"black\" stroke-width=\"3\" fill=\"red\" /> \n";

    string mds_svg = rect1 + cranck + piston + circle2 + rect2 + circle1; //creating the modified crankshaft svg
    return mds_svg;

    }


void mg_filew(string mds_to_svg){  //writetothefile functio, used to add previous svg code to a chosen file

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



void init_mds(mds* mds){  //function which let the user initialize the crankshaft properties
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

        if ( mds_inspect(mds)){

            mds_to_svg(mds);
            return;
        }
    }
}

void choose_option(int opt){ //choose_option function, which let the user choose the needed functionality
    mds* mds;
    string mds_svg;
    while(opt!=3){
        switch (opt)
        {
        case 1:
            init_mds(mds);
            mds_svg = mds_to_svg(mds);
            break;
        case 2:
            mg_filew(mds_svg);
            break;
        case 3:
            cout << "Program ended" << endl;
            break;
        }
    }
    if(opt < 1 && opt > 3){
        cout << opt << " is not an acceptable option. Please, choose an available option" << endl;
    }
}