  
#ifndef MDS_H
#define MDS_H

#include <iostream>
#include <string>

struct mds
{
    double Dm;
    double Lm;
    double Lp;
    double Lb;
    double Hp;
	double alfa;

    mds(double _Dm, double _Lm, double _Lp, double _Lb, double _Hp, double _alfa){ // definisco i parametri variabili
        Dm = 0;
		Lm = 0;
        Lp = 0;
        Lb = 0;
        Hp = 0;
	    alfa = 0;
    }
};

void mg_filew(string cat);  
std::string mds_to_svg(mds* mds);  // crea la stringa
int mds_inspect(mds* mds);    //controlla i vincoli
void init_mds(mds* mds);    //crea un nuovo meccanismo di spinta inizializzando nuove variabili


#endif