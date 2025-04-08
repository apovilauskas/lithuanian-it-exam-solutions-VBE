#include <bits/stdc++.h>

struct portalas {
	std::string pav;
	std::vector<std::string> kategor;
	std::vector<int> procentai;

};

void skaityti(int &n, std::vector<portalas> &p) {
	std::ifstream fd("U2.txt");
	fd >> n;
	p.resize(n);
	for(int i=0; i<n; i++)	{
		std::string temp;
		int temp1;
		fd   >> p[i].pav >> temp >> temp1;
		int melas=0;
		for(int k=0; k<temp1; k++) {
			char tipas;
			fd >> tipas;
			if(tipas == 'M')melas++;
		}
		if(melas*1.00/temp1 >= 0.75) {
			p[i].kategor.push_back(temp);
			p[i].procentai.push_back(melas*1.00/temp1*100.0);
		}
	}
}
//pagal pavadinima
void rikiuoti(std::vector<portalas> &p) {
	for(int i=0; i<p.size(); i++) {
		for(int k=0; k<p.size()-1; k++) {
			if(p[k].pav < p[k+1].pav)std::swap(p[k], p[k+1]);
		}
	}
}

void rikiuoti2(std::vector<portalas> &p){
   	for(int i=0; i<p.size(); i++) {
		for(int k=0; k<p.size()-1; k++) {
			if(p[k].kategor.size() == p[k+1].kategor.size() && p[k].pav > p[k+1].pav)std::swap(p[k], p[k+1]);
			else if(p[k].kategor.size() < p[k+1].kategor.size())std::swap(p[k], p[k+1]);
		}
	} 
    
}

void rasyti(std::vector<portalas> &tinka){
    	std::ofstream fr("U2rez.txt");
    bool tinkamas=0;
	for(int i=0; i<tinka.size(); i++) {
		if(tinka[i].kategor.size() != 0) {
		    tinkamas = 1;
			fr << tinka[i].pav << ' ' <<tinka[i].kategor.size() <<'\n';
			for(int k=0; k<tinka[i].kategor.size(); k++) {
				fr << tinka[i].kategor[k] << ' ' <<tinka[i].procentai[k] <<'\n';
			}
		}
	}
if(tinkamas == 0) fr<< "Neatitinka reikalavimo";
}

int main()
{


	int n;
	std::vector<portalas> p;
	std::vector<portalas>tinka;

	skaityti(n, p);
	rikiuoti(p);

	tinka.push_back(p[0]);
	for(int i=1; i<p.size(); i++) {
		if(p[i].pav != p[i-1].pav) {
			tinka.push_back(p[i]);
		}
		else {
			tinka.back().kategor.insert(tinka.back().kategor.end(), p[i].kategor.begin(), p[i].kategor.end());
			tinka.back().procentai.insert(tinka.back().procentai.end(), p[i].procentai.begin(), p[i].procentai.end());
		}
	}
	
    rikiuoti2(tinka);
    rasyti(tinka);

	return 0;
}
