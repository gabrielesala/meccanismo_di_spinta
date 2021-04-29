  
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

void mg_filew(string cat);  //scrive su file il file la stringa che costituisce l'svg
std::string mg_catSVG(mds* meccanismo_di_spinta);    //costruisce la stringa
int mg_check(mds* meccanismo_di_spinta);    //controlla i vincoli
void mg_init_cat(mds* meccanismo_di_spinta);    //crea un nuovo meccanismo di spinta inizializzando nuove variabili


#endif