#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

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
	ofstream fichier("Cle.txt", ios::out | ios::trunc);
	for(int i=0;i<a;i++){
		fichier<<CreeCle(3,30)<<endl;
	}
	return 1;
}	

int main() {
	CreeFichier(10000);
	return 0;
}