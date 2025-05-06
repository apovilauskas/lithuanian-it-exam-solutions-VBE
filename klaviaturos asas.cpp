#include <bits/stdc++.h>

struct mokinys {
	std::string vardas;
	int zodziu;
	int klaidu;
	std::string miestas;
};

struct miestas {
	std::string pav;
	std::vector<mokinys> mok;
};

void skaityti(int &m, std::vector<miestas> &miest) {
	std::ifstream fd("U2.txt");

	fd >> m;
	fd.ignore(80, '\n');
	miest.resize(m);

	for(int i=0; i<m; i++) {

		char miestas[16];
		fd.get(miestas, 16);
		miest[i].pav = miestas;
		int dalyviu;
		fd >> dalyviu;
		miest[i].mok.resize(dalyviu);
		fd.ignore(80,'\n');
		for(int j=0; j<miest[i].mok.size(); j++) {
			char temp[11];
			fd.get(temp, 11);
			miest[i].mok[j].vardas = temp;
			fd >> miest[i].mok[j].zodziu >> miest[i].mok[j].klaidu;
			fd.ignore(80, '\n');

		}

	}


}

void sarasai(std::vector<miestas> &miest, std::vector<mokinys> &tinka, std::vector<mokinys> &disk, int &maxpts){
    
    //max tasku
    for(int i=0; i<miest.size(); i++) {
		for(int j=0; j<miest[i].mok.size(); j++) {
			miest[i].mok[j].zodziu -= 10* miest[i].mok[j].klaidu;
			if(miest[i].mok[j].zodziu > maxpts && miest[i].mok[j].klaidu <5 )maxpts = miest[i].mok[j].zodziu;
		}
	}
	
	
	//skirstymas
	for(int i=0; i<miest.size(); i++) {
		for(int j=0; j<miest[i].mok.size(); j++) {
			if(miest[i].mok[j].zodziu == maxpts) {
				tinka.push_back(miest[i].mok[j]);
				tinka.back().miestas = miest[i].pav;
			}
			if(miest[i].mok[j].klaidu >=5) {
				disk.push_back(miest[i].mok[j]);
			}
		}
	}

    //rikiavimas
	for(int i=0; i<tinka.size(); i++) {
		for(int j=0; j<tinka.size()-1; j++) {
			if(tinka[j].klaidu > tinka[j+1].klaidu) {
				std::swap(tinka[j], tinka[j+1]);
			}
		}
	}
}

void rasyti(int maxpts, std::vector<mokinys> tinka, std::vector<mokinys> disk){
    std::ofstream fr("U2rez.txt");
    
    	fr << maxpts <<'\n';


	

	for(int i=0; i<tinka.size(); i++) {
		fr << tinka[i].vardas  << ' '<< tinka[i].miestas <<'\n';
	}

	fr << "Diskvalifikuoti:\n";

	for(int i=0; i<disk.size(); i++) {
		fr << disk[i].vardas  <<'\n';
	}

}


int main()
{


	std::vector<miestas> miest;
	int m;
    int maxpts =INT_MIN;
    
    //du vektoriai sarasams
    std::vector<mokinys> tinka;
	std::vector<mokinys> disk;
	
	skaityti(m, miest);
    sarasai(miest, tinka, disk, maxpts);
	rasyti(maxpts, tinka, disk);
	

	return 0;
}
