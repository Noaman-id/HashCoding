#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;

#define m 100

int Fonc_Hashcode(string Cle, int nb_function){
	int L=longfc(Cle);
	int cp=0;
	switch (nb_function)
	{
	case 1:
		for(int i=0 ; i<L ;i++){
			cp += (Cle[i] - '0') * 19 ? (Cle[i]>='0' && Cle[i]<='9') : (Cle[i] - '0') * 19;
		}
		return cp % m;
		break;
	case 2:
		for(int i=0 ; i<L ;i++){
			cp += (Cle[i] - '0') * 19 ? (Cle[i]>='0' && Cle[i]<='9') : (Cle[i] - '0') * 19;
		}
		return cp % m;
		break;
		break;
	case 3:
	// a trouver  //
		break;
	}
}

string CreeCle(int a,int b){
	int NbrCh;
	NbrCh=a+(rand() % (b));
	int Ch_ou_nbr;
	string Cle;
	char CH,Nbr;
	for(int i=0;i<NbrCh;i++){
		Ch_ou_nbr=(rand() % 3);
		if(Ch_ou_nbr==0){
			Nbr=48+(rand() % 10);
			Cle=Cle+Nbr;
		}
		else{
			CH=65 +(rand() % 26);
			Cle=Cle+CH;
		}
	}
	return Cle;
}


int longfc(string Cle) {
    int count = 0;
    while (Cle[count] != NULL) {  
        count++;
    }
    return count;
}

int CreeFichier(int a){
	ofstream fichier("Bib.bin", ios::out | ios::trunc);
	for(int i=0;i<a;i++){
		fichier<<CreeCle(3,30)<<endl;
	}
	return 1;
}	
void Ajouter_Thash(string Cle, int NoFonction) {
    int Indice = Fonc_Hashcode(Cle, NoFonction);
    Ajouter_liste(THash[Indice].Lien, Cle);
    THash[Indice].NbElem++;
}



void Creer_Thash(TThash& Thash, const std::string& Name, int NoFonction) {
    std::ifstream F(Name);  
    if (!F) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << Name << std::endl;
        return;
    }

    std::string Cle;
    while (F >> Cle) 
	{  
        Ajouter_Thash(Thash, Cle, NoFonction);
    }

    F.close();  
}
int main() {
	CreeFichier(10000);
	return 0;
}