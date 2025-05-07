#include <bits/stdc++.h>

struct parduotuve {
	std::string pav;
	std::vector<std::string> rusys;
	std::vector<double> kainos;
	std::vector<std::string> tinka;
};



void rasyti(double krepselis, std::vector<parduotuve> pard, int s) {
	std::ofstream fr("U1rez.txt");

	if(krepselis <= s) {
		fr << krepselis <<'\n';
		for(int i=0; i<pard.size(); i++) {
			if(pard[i].tinka.size() != 0) {
				fr << pard[i].pav <<  ' ';
				for(int j=0; j<pard[i].tinka.size(); j++) {
					fr << pard[i].tinka[j] << ' ';
				}
				fr <<'\n';

			}

		}

	}
	else fr <<"Nepavyks nusipirkti";
}

void skaiciuoti(std::vector<parduotuve> &pard, double &s) {
	double krepselis=0; //galutinei kainai paskaiciuoti
	
	
	for(int i=0; i<pard[0].rusys.size(); i++) {
		double minkaina=INT_MAX; //rasim minimialia kiekvieno produkto kaina
		for(int j=0; j<pard.size(); j++) {
			if(pard[j].kainos[i] <minkaina && pard[j].kainos[i] >0) {
				minkaina = pard[j].kainos[i];
			}

		}
		for(int j=0; j<pard.size(); j++) { //tada rasim kurios parduotuves ja siulo
			if(pard[j].kainos[i] ==minkaina) {
				pard[j].tinka.push_back({pard[0].rusys[i]});
			}

		}
		krepselis += minkaina; //didinam bendra kaina
	}

//rikiuojam pagal prekiu kieki
	for(int i=0; i<pard.size(); i++) {
		for(int j=0; j<pard.size()-1; j++) {
			if(pard[j].tinka.size() < pard[j+1].tinka.size()) {
				std::swap(pard[j], pard[j+1]);
			}


		}
	}

	rasyti(krepselis, pard, s);

}

void skaityti(int &p, double &s, std::vector<std::string> &rusys, std::vector<parduotuve> &pard) {
	std::ifstream fd("U1.txt");

	fd >> p >> s;
	fd.ignore(80, '\n');

//nuskaitom prekiu pavadinimus
	rusys.resize(p);
	for(int i=0; i<p; i++) {
		char temp[11];
		fd.get(temp, 11);
		rusys[i]=temp;
	}
	fd.ignore(80, '\n');

//nuskaitom visas parduotuves ir ju siulomas kainas
	parduotuve tempa;
	char temp[11];
	while(fd.get(temp, 11)) {
		tempa.pav = temp;
		tempa.rusys = rusys;
		tempa.kainos.resize(p);
		for(int i=0; i<tempa.kainos.size(); i++) {
			fd >> tempa.kainos[i];
		}
		fd.ignore(80, '\n');
		pard.push_back(tempa);
	}


	skaiciuoti(pard, s);
}

int main()
{



	int p;
	double s; //prekiu, suma pinigu
	std::vector<std::string> rusys;
	std::vector<parduotuve> pard;

	skaityti(p, s, rusys, pard);


	return 0;
}
