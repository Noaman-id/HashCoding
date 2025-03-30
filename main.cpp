#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;

#define m 100

struct Pliste
{
	string info;
	Pliste* Suiv;
};
struct Eliste
{
	int NbElem;
	Pliste* Suiv; 
};
struct TTHash
{
	Eliste Tableau[m];
};

int longfc(string Cle) {
    int count = 0;
    while (Cle[count] != NULL) {  
        count++;
    }
    return count;
}

<<<<<<< HEAD
int Fonc_Hshcode(string Cle, int nb_function){

=======
int Fonc_Hashcode(string Cle, int nb_function){
>>>>>>> c04093c13fa9954866e1b784ddda23a23d7b413f
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
			cp += (Cle[i] >= '0' && Cle[i] <= '9') ? pow((Cle[i] - '0'), 2) * 19 : pow((Cle[i] - '0') * 19, 2);
		}
		return cp % m;
		break;
	case 3:

		break;
	}
}

void Ajouter_liste(Pliste* Ptr,string Cle){
	Pliste* P;
	Pliste* Q;
	Pliste* R;
	P = Ptr;
	Q = new Pliste;
	Q->info=Cle;
	Q->Suiv=NULL;
	if(P == NULL) Ptr=Q;
	else{
		if(Cle < P->info){
			Q->Suiv=Ptr;
			Ptr=Q;
		}
		else{
			while (Cle > P->info && P != NULL)
			{
				R=P;
				P=P->Suiv;
			}
			R->Suiv=Q;
			Q->Suiv=P;
		}
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