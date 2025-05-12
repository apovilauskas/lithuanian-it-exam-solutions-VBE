#include <bits/stdc++.h>

struct stotis {
	int nr;
	int d;
	int in;
	int out; //ilipo / islipo
};

void skaityti(int &m, std::vector<stotis> &s) {
	std::ifstream fd("U1.txt");

	fd >> m;
	stotis temp;
	for(int i=0; i<m; i++) {
		fd >>temp.nr >> temp.d >> temp.in >> temp.out;
		s.push_back({temp});
	}

}

void skaiciuoti(std::vector<stotis> &s, std::vector<stotis> &tinka, int &maxx, int&maxnr, int &count) {
	for(int i=0; i<s.size(); i++) {
		for(int j=0; j<s.size()-1; j++) {
			if(s[j].nr > s[j+1].nr)std::swap(s[j],s[j+1]);
		}
	}

	tinka.push_back(s[0]);
	for(int i=1; i<s.size(); i++) {
		if(s[i].nr != s[i-1].nr)tinka.push_back(s[i]);
		else {
			tinka.back().in += s[i].in;
			tinka.back().out += s[i].out ;
		}
	}
	
	
	
    	for(int i=0; i<tinka.size(); i++) {
		if(tinka[i].in +tinka[i].out > maxx) {
			maxx = tinka[i].in +tinka[i].out;
			maxnr = tinka[i].nr;
		}
	}
	
	
	for(int i=0; i<tinka.size(); i++) {
		count += tinka[i].in;
	}
}

void rasyti(std::vector<stotis> &tinka, int&maxnr, int&count) {
	std::ofstream fr("U1rez.txt");

	for(int i=0; i<tinka.size(); i++) {
		fr <<std::setw(6)<<std::right<< tinka[i].nr ;
	}

	fr <<'\n'<< std::setw(6)<<std::right<<maxnr <<'\n';
	fr << std::setw(6)<<std::right<< count << '\n';


}


int main()
{
	int m; //duomenu
	std::vector<stotis> s;
	std::vector<stotis> tinka;
	int maxx=INT_MIN;
	int maxnr;
	int count =0;

	skaityti(m, s);
	skaiciuoti(s, tinka, maxx,  maxnr, count);
	rasyti(tinka, maxnr, count);

	return 0;
}
