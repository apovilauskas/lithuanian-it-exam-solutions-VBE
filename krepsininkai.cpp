#include <bits/stdc++.h>

struct krep {
	int k; //numeris
	int t; //laiku
	bool start=0;
	int z=0;
	int ne=0; //zaide ir sedejo
};

void startas(std::vector<krep> &a) {
	for(int i=0; i<a.size(); i++) {
		for(int j=i+1; j<a.size(); j++) {
			if(a[i].start == a[j].start) {
				if(a[i].k > a[j].k) {
					std::swap(a[i], a[j]);
				}
			}
			else if(a[i].start < a[j].start) std::swap(a[i], a[j]);
		}
	}

}

void skaityti(int &n,  std::vector<krep> &a) {
	int maxi=0, mini=0;
	int maxii, minii;
	std::ifstream fd("U1.txt");
	std::ofstream fr("U1rez.txt");
	fd >> n;
	a.resize(n);
	for(int i=0; i<n; i++) {
		fd >> a[i].k >> a[i].t;
		for(int j=0; j<a[i].t; j++) {
			int temp;
			fd >> temp;
			if(temp > 0) {
				if(j == 0) a[i].start = 1;
				a[i].z+= temp;
			}
			else a[i].ne-= temp;
		}
	}
	startas(a);
	for(int i=0; i<5; i++) {
		fr << a[i].k << ' ';
	}
	fr << '\n';

	for(int i=0; i<a.size(); i++) {
		if(a[i].z > maxi) {
			maxi = a[i].z;
			maxii = i;
		}
		if(a[i].ne > mini) {
			mini = a[i].ne;
			minii = i;
		}
	}

	fr << a[maxii].k << ' ' <<maxi << '\n';
	fr << a[minii].k << ' ' <<mini << '\n';
}



int main() {


	int n; //krepsininku
	std::vector<krep> a;
	skaityti(n, a);

	return 0;
}
