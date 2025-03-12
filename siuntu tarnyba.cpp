//kode klaidu nematau bet atsakymas nuo pavyzdinio truputi skiriasi. gal nebent uzduotis neaiskiai suformuluota
#include <bits/stdc++.h>

struct taskas {
	int x,y;
	std::string pav;
};

void skaityti(int &n, int &m, std::vector<taskas> &t) {
	std::ifstream fd("U1.txt");
	fd >> n >> m;
	t.resize(n);
	fd.ignore(80, '\n');

	for(int i=0; i<n; i++) {
		char temp[11];
		fd.get(temp, 11);
		t[i].pav = temp;
		fd >> t[i].x >> t[i].y;
		fd.ignore(80, '\n');
	}
}

int atstumas(std::vector<taskas> &t,const int &i) {
	return (abs(t[i].x)+abs(t[i].y))*2;
}

void rasyti(int aplankyta, int km, std::string paskutinis) {
	std::ofstream fr("U1rez.txt");
	fr << aplankyta << ' ' <<km << ' ' <<paskutinis;

}

int main()
{


	std::vector<taskas> t;
	int n, m;

	skaityti(n, m, t);

	//rikiuoti pagal atstumus
	for(int i=0; i<t.size(); i++) {
		for(int j=0; j<t.size()-1; j++) {
			if(atstumas(t,j) > atstumas(t, j+1))std::swap(t[j], t[j+1]);
		}
	}

	//tikrinti kiek galime pasiekti
	int km=0;
	int aplankyta=0;
	std::string paskutinis;
	for(int i=0; i<t.size(); i++) {
		if(atstumas(t, i) + km <= m) {
			aplankyta ++;
			km += atstumas(t, i);
			paskutinis = t[i].pav;
		}
	}

	rasyti(aplankyta, km, paskutinis);


	return 0;
}
