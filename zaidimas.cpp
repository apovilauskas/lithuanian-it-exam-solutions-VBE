#include <bits/stdc++.h>

struct mokinys {
	std::string vardas;
	std::vector<char> zyme;
	double santykis() {
		return w*1.0/l;
	};
	int lygiu=0;
	int w=0;
	int l=0;
};

void skaityti(std::vector<mokinys> &mok, int&m, int&e) {
	std::ifstream fd("U2.txt");

	fd >> m >>e;
	fd.ignore(80, '\n');
	mok.resize(m);
	for(int i=0; i<m; i++) {
		char temp[14];
		fd.get(temp, 14);
		mok[i].vardas = temp;
		mok[i].zyme.resize(e);
		for(int j=0; j<e; j++) {
			fd >> mok[i].zyme[j]>>std::ws;
		}
	}
}

void skaiciuoti(std::vector<mokinys> &mok, int & e){
    
	for(int k=0; k<e; k++) {
		for(int i=0; i<mok.size(); i++) {
			for(int j=0; j<mok.size(); j++) {
				if(i==j) continue;
				else {
					if(mok[i].zyme[k] == mok[j].zyme[k])mok[i].lygiu++;
					if(mok[i].zyme[k] == 'P' && mok[j].zyme[k] == 'A')mok[i].w++;
					if(mok[i].zyme[k] == 'A' && mok[j].zyme[k] == 'Z')mok[i].w++;
					if(mok[i].zyme[k] == 'Z' && mok[j].zyme[k] == 'P')mok[i].w++;
					if(mok[i].zyme[k] == 'P' && mok[j].zyme[k] == 'Z')mok[i].l++;
					if(mok[i].zyme[k] == 'A' && mok[j].zyme[k] == 'P')mok[i].l++;
					if(mok[i].zyme[k] == 'Z' && mok[j].zyme[k] == 'A')mok[i].l++;

				}
			}
		}




	}

	for(int i=0; i<mok.size(); i++) {
		for(int j=0; j<mok.size()-1; j++) {
			if(mok[j].santykis()<mok[j+1].santykis())std::swap(mok[j], mok[j+1]);
		}
	}
    
}


void rasyti(std::vector<mokinys> &mok){
    std::ofstream fr("U2rez.txt");

    	for(int i=0; i<mok.size(); i++) {
		fr << mok[i].vardas <<' ' <<std::fixed << std::setprecision(2) <<mok[i].santykis() << ' ' <<mok[i].lygiu <<'\n';
	}
    
}

int main()
{

	
	int m, e;
	std::vector<mokinys> mok;
    skaityti(mok, m, e);
    skaiciuoti(mok, e);
    rasyti(mok);



	return 0;
}
