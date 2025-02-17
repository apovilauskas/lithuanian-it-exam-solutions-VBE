#include <bits/stdc++.h>

struct avis {
	std::string vardas;
	std::vector<char> dnr;
	int kof=0;
};

void rasyti(std::string &vd, std::vector<avis> &a);
void skaito(int &n, int &k, int &m, std::vector<avis> &a, std::string &vd);
void rik(std::vector<avis> &a);
void kof(std::vector<avis> &a, int &k, int &m);


int main()
{


	int n; //aviu
	int m; //fragmento ilgis;
	int k; //kelinta
	std::string vd;
	std::vector<avis> a;
	skaito(n,k,m,a, vd);
	kof(a,k,m);
	rik(a);
	rasyti(vd, a);


	return 0;
}

void skaito(int &n, int &k, int &m, std::vector<avis> &a, std::string &vd) {
	std::ifstream fd("U2.txt");
	fd >> n >> m >> k;
	a.resize(n);
	fd.ignore(80, '\n');
	for(int i=0; i<n; i++) {
		char temp[11];
		fd.get(temp, 11);
		a[i].vardas = temp;
		for(int j=0; j<m; j++) {
			a[i].dnr.resize(m);
			fd.get(a[i].dnr[j]);
		}
		fd.ignore(80, '\n');
	}
	vd = a[k-1].vardas;
}

void kof(std::vector<avis> &a, int &k, int &m) {
	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<m; j++) {
			if(i==k-1) continue;
			if(a[i].dnr[j] == a[k-1].dnr[j]) a[i].kof++;
		}
	}
}

void rik(std::vector<avis> &a) {
	for(int i=0; i<a.size(); i++) {
		for(int j=i+1; j<a.size(); j++) {
			if(a[i].kof == a[j].kof) {
				if(a[i].vardas > a[j].vardas) {
					std::swap(a[i], a[j]);
				}
			}
			if(a[i].kof < a[j].kof) std::swap(a[i], a[j]);
		}
	}

}

void rasyti(std::string &vd, std::vector<avis> &a) {
	std::ofstream fr("U2rez.txt");
	fr << vd << '\n';
	for(int i=0; i<a.size()-1; i++) {
		fr << a[i].vardas << ' ' <<a[i].kof << '\n';
	}
}
