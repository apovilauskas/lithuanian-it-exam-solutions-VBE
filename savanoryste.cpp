#include <bits/stdc++.h>

struct diena {
	int kelinta;
	int val, min;
	int qval, qmin;
	int r1,r2,r3,r4,r5;
	int rusiu=0;
	int kiekis=0;


};

void skaityti(std::vector<diena> &dien, int &d) { //funkcija skaitymui
	std::ifstream fd("U1.txt");
	fd >> d;
	dien.resize(d);

	for(int i=0; i<dien.size(); i++) {
		fd>> dien[i].kelinta >> dien[i].val >> dien[i].min >> dien[i].qval >> dien[i].qmin >>
		  dien[i].r1 >> dien[i].r2 >> dien[i].r3 >> dien[i].r4 >>dien[i].r5;

	}
}

int laikas(diena a) { //funkcija laikui skaiciuoti
	return (a.qval*60+a.qmin)-(a.val*60+a.min);
}

void skaiciuoti(std::vector<diena> &dien, int &d, std::vector<diena> &atrinkti) {

	for(int i=0; i<dien.size(); i++) {
		dien[i].kiekis += (dien[i].r1 + dien[i].r2+dien[i].r3+dien[i].r4+dien[i].r5);
		if(dien[i].r1 >0)dien[i].rusiu++;
		if(dien[i].r3 >0)dien[i].rusiu++;
		if(dien[i].r2 >0)dien[i].rusiu++;
		if(dien[i].r4 >0)dien[i].rusiu++;
		if(dien[i].r5 >0)dien[i].rusiu++;
	}



	int maxkiekis=INT_MIN;
	int maxrusiu = INT_MIN;
	std::vector<diena> maxk;
	for(int i=0; i<dien.size(); i++) {
		if(dien[i].rusiu > maxrusiu)maxrusiu = dien[i].rusiu;
	}

	for(int i=0; i<dien.size(); i++) {
		if(dien[i].rusiu == maxrusiu)maxk.push_back(dien[i]);
	}

	for(int i=0; i<maxk.size(); i++) {
		if(maxk[i].kiekis > maxkiekis)maxkiekis = dien[i].kiekis;
	}


	for(int i=0; i<maxk.size(); i++) {
		if(maxk[i].kiekis == maxkiekis)atrinkti.push_back(maxk[i]);
	}
}

void rasyti(std::vector<diena> &atrinkti) {
	std::ofstream fr("U1rez.txt");

	for(int i=0; i<atrinkti.size(); i++) {
		fr << atrinkti[i].kelinta << ' ' <<laikas(atrinkti[i]) <<'\n';
	}

}

int main()
{
	int d;
	std::vector<diena> dien;
	std::vector<diena> atrinkti;

	skaityti(dien, d);
	skaiciuoti(dien, d, atrinkti);
	rasyti(atrinkti);


	return 0;
}
