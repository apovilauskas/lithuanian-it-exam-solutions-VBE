#include <bits/stdc++.h>

struct veliava {
	char spalva;
	int kiekis=0;
};

void skaityti(int &n, std::vector<veliava> &s) {
	std::ifstream fd("U1.txt");

	fd >> n;
	s.resize(n);

	for(int i=0; i<s.size(); i++) {
		fd >> s[i].spalva >> s[i].kiekis;
	}
}

void skaiciuoti(std::vector<veliava> &s, int &min) {

	//sukategorizuoja i spalvas kad nesikartotu
	for(int i=0; i<s.size(); i++) {
		for(int j=0; j<s.size()-1; j++) {
			if(s[j].spalva > s[j+1].spalva)std::swap(s[j], s[j+1]);
		}
	}
	std::vector<veliava> tinka;
	tinka.push_back(s[0]);
	for(int i=1; i<s.size(); i++) {
		if(s[i].spalva != s[i-1].spalva)tinka.push_back(s[i]);
		else {
			tinka.back().kiekis+=s[i].kiekis;
		}
	}

	//geltona zalia, raudoona-aa!
	std::vector<veliava> eile(3);
	for(int i=0; i<tinka.size(); i++) {
		if(tinka[i].spalva == 'G')eile[0] =tinka[i];
		if(tinka[i].spalva == 'Z')eile[1] =tinka[i];
		if(tinka[i].spalva == 'R')eile[2] =tinka[i];
	}
	//veliavu kiekis bus min/2 (abi puses)
	for(int i=0; i<eile.size(); i++) {
		if(eile[i].kiekis < min ){
		    if(eile[i].kiekis %2 ==0) min = eile[i].kiekis;
		    else min = eile[i].kiekis-1;
		}

	}
	s= eile;

}

void rasyti(int min, std::vector<veliava> &s) {
	std::ofstream fr("U1rez.txt");

	fr << min/2 <<'\n';
	for(int i=0; i<s.size(); i++) {
		fr << s[i].spalva << " = " <<s[i].kiekis-min <<'\n';
	}



}

int main()
{

	int n;
	std::vector<veliava> s;
	int min=INT_MAX;

	skaityti(n, s);
	skaiciuoti(s, min);
	rasyti(min, s);


	return 0;




}
