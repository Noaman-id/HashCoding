#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>

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
	Pliste* Lien; 
};
struct TTHash
{
	Eliste Tableau[m];
};

int longfc(string Cle) {
    int count = 0;
	while (Cle[count] != '\0' ) {
		count++;
    }
    return count;
}

int Fonc_Hashcode(string Cle, int nb_function){
	int L=longfc(Cle);
	int cp=0;
	switch (nb_function)
	{
	case 1:
		for(int i=0 ; i<L ;i++){
			if(Cle[i]>='0' && Cle[i]<='9'){
				cp += (Cle[i] - '0') * 19;
			}
			else
			{
				cp += (Cle[i] - 'A') * 19;
			}
		}
		return cp % m;
		break;
	case 2:
		for(int i=0 ; i<L ;i++){
			cp += (Cle[i] >= '0' && Cle[i] <= '9') ? pow((Cle[i] - '0'), 2) * 19 : pow((Cle[i] - 'A') * 19, 2);
		}
		return cp % m;
		break;
	case 3:
		for(int i=0 ; i<L ;i++){
			cp += (Cle[i] >= '0' && Cle[i] <= '9') ? pow((Cle[i] - '0'), 3) * 19 : pow((Cle[i] - 'A') * 19, 3);
		}
		return cp % m;	
		break;
	}
	return cp % m;
}

void Ajouter_liste(Pliste*& Ptr,string Cle){
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
			while ( P != NULL && Cle > P->info )
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
	for(int i=0;i<=a;i++){
		fichier<<CreeCle(3,30)<<endl;
	}
	return 1;
}	

void Ajouter_Thash(TTHash& THash, string Cle, int NoFonction) {

    int Indice = Fonc_Hashcode(Cle, NoFonction);

	Ajouter_liste(THash.Tableau[Indice].Lien, Cle);

	THash.Tableau[Indice].NbElem++;
	
}

void Liberer(TTHash Thash) {
	Pliste* P;
	Pliste* Q;
	for (int i = 0; i < m; i++) {
		P = Thash.Tableau[i].Lien;
		while (P != NULL) {
			Q = P->Suiv;
			delete P;
			P = Q;
		}
	}
}

void Init_TabHashCode(TTHash& Thash) {
	for (int i = 0; i < m; i++) {
		Thash.Tableau[i].NbElem = 0;
		Thash.Tableau[i].Lien = NULL;
	}
}

void Afficher_NbElem(TTHash Thash){
	for(int i = 1 ; i < 5 ; i++){
		for( int j = (i - 1) * 20; j < (i*20)-1; j++){
			cout<<Thash.Tableau[j].NbElem <<" ";
		}
		cout<<endl;
	}
	cout<< endl;
}

void Creer_Thash(TTHash &Thash, string Name, int NoFonction) 
{
    ifstream File(Name);  
    if (!File) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << Name << std::endl;
        return;
    }

    string Cle;
    while (File >> Cle) 
	{  
        Ajouter_Thash(Thash, Cle, NoFonction);
    }

    File.close();  
}

int main() {
	TTHash Thash;
	string Name = "Bib.bin";
	CreeFichier(10000);
	for(int i = 1 ; i < 4 ; i++){
		Init_TabHashCode(Thash);
		Creer_Thash(Thash,Name,i);
		Afficher_NbElem(Thash);
		Liberer(Thash);
	}
	return 0;
}