#include <bits/stdc++.h>

struct begimas {
	int trukme;
	int md;
	bool tinka=1;
	int pirma, antra;
};

void skaiciavimai(std::vector<begimas> &a, int &d, begimas &min) {
	std::ifstream fd("U1.txt");
	fd>>d;
	a.resize(d);

	for(int i=0; i<d; i++) {
		fd >> a[i].md;
		int temp,temp1,temp2,temp3;
		fd >> temp >> temp1 >> temp2 >>temp3;
		if(temp==0 & temp1==0 & temp2==0 & temp3==0) a[i].tinka =0;
		a[i].pirma = (temp2*60+temp3)-(temp*60+temp1);
		fd >> temp >> temp1 >> temp2 >>temp3;
		if(temp==0 & temp1==0 & temp2==0 & temp3==0) a[i].tinka =0;
		a[i].antra = (temp2*60+temp3)-(temp*60+temp1);
		a[i].trukme = a[i].pirma+a[i].antra;
	}
	min.trukme=INT_MAX;
	for(int i=0; i<a.size(); i++) {
		if(a[i].tinka == 1 && a[i].trukme < min.trukme) min=a[i];
	}
}

int main()
{
	std::ofstream fr("U1rez.txt");
	std::vector<begimas> a;
	int d;
	begimas min;
	skaiciavimai(a,d, min);

	fr <<"minimalus laikas \n" << min.trukme << '\n';
	fr << "dienos\n";
	for(int i=0; i<a.size(); i++) {
		if(a[i].tinka == 1 && a[i].trukme == min.trukme) fr<< a[i].md<<' ';
	}

	return 0;
}
