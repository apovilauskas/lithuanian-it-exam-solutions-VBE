#include <bits/stdc++.h>

struct pirstine {
	int lyt; //3 vyr 4 mot
	int ranka; //1 kaire 2 desine
	int dydis;
};

void skaityti(int &n, std::vector<pirstine> &mot, std::vector<pirstine> &vyr) {
	std::ifstream fd("U1.txt");

	fd >> n;
	pirstine temp;
	for(int i=0; i<n; i++) {
		fd >> temp.lyt >> temp.ranka >> temp.dydis;
		if(temp.lyt == 3)vyr.push_back(temp);
		else mot.push_back(temp);
	}
}

int poros(std::vector<pirstine> zm) {
	for(int i=0; i<zm.size(); i++) {
		for(int j=0; j<zm.size()-1; j++) {
			if(zm[j].dydis > zm[j+1].dydis)std::swap(zm[j], zm[j+1]);
		}
	}

	int poru=0;

	for(int i=0; i<zm.size()-1; i++) {
		if(zm[i].dydis == zm[i+1].dydis && zm[i+1].ranka != zm[i].ranka) {
			poru ++;
			i++;
		}
	}

	return poru;

}

int liko(int &poru, std::vector<pirstine> &viso) {

	return viso.size()-(poru*2);
}

void rasyti(std::vector<pirstine> &mot, std::vector<pirstine> &vyr) {
	std::ofstream fr("U1rez.txt");

	int pmot=poros(mot), pvyr=poros(vyr);
	
	fr << pmot <<'\n';
	fr << pvyr <<'\n';
	fr << liko(pmot, mot)<<'\n';
	fr << liko(pvyr,vyr);
}




int main()
{
	int n;
	std::vector<pirstine> mot;
	std::vector<pirstine> vyr;

	skaityti(n, mot, vyr);
	rasyti(mot, vyr);



	return 0;
}
