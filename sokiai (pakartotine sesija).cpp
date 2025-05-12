#include <bits/stdc++.h>

struct pora {

	std::string vard;
	std::vector<int> pirmas;
	std::vector<int> antras;
	int suma=0;
};

void skaityti(int n, int k, int m, std::vector<pora> &p) {
	std::ifstream fd("U2.txt");

	fd >> n >> k >>m;
	fd.ignore(80,'\n');

	p.resize(n);
	for(int i=0; i<n; i++) {
		char pav[21];
		fd.get(pav, 21);
		p[i].vard = pav;
		fd.ignore(80,'\n');
		for(int j=0; j<k; j++) {
			int temp;
			fd >> temp;
			p[i].pirmas.push_back(temp);
		}
		fd.ignore(80,'\n');
		for(int j=0; j<m; j++) {
			int temp;
			fd >> temp;
			p[i].antras.push_back(temp);
		}
		fd.ignore(80,'\n');
	}

}

void skaiciuoti(std::vector<pora> &p) {

	for(int i=0; i<p.size(); i++) {
		int min1=INT_MAX,min2=INT_MAX,max1=INT_MIN,max2=INT_MIN;
		for(int j=0; j<p[i].pirmas.size(); j++) {
			if(p[i].pirmas[j]>max1)max1=p[i].pirmas[j];
			if(p[i].pirmas[j]<min1)min1=p[i].pirmas[j];
			p[i].suma+= p[i].pirmas[j];
		}
		for(int j=0; j<p[i].antras.size(); j++) {
			if(p[i].antras[j]>max2)max2=p[i].antras[j];
			if(p[i].antras[j]<min2)min2=p[i].antras[j];
			p[i].suma+= p[i].antras[j];
		}
		p[i].suma = p[i].suma - min1 - min2 - max1 - max2;
	}

}

void rikiuoti(std::vector<pora> &p) {

	for(int i=0; i<p.size(); i++) {
		for(int j=0; j<p.size()-1; j++) {
			if(p[j].suma <p[j+1].suma)std::swap(p[j], p[j+1]);
		}
	}

}


int main()
{

	std::ofstream fr("U2rez.txt");

	int n, k, m;
	std::vector<pora> p;

	skaityti(n,k,m,p);
	skaiciuoti(p);
	rikiuoti(p);


	for(int i=0; i<p.size(); i++) {
		fr << p[i].vard << ' '<< p[i].suma <<'\n';
	}


	return 0;
}
