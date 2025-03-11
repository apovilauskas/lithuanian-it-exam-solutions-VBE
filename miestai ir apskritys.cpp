#include <bits/stdc++.h>

struct apskritis {
	std::string pav;
	std::vector<std::string> miestai;
	std::vector<int> zmoniu;
	int maziausia;
	int bendrai;
};

void skaityti(int &k, std::vector<apskritis> &a) {
	std::ifstream fd("U2.txt");
	fd >> k;

	fd.ignore(80, '\n');
	for(int i=0; i<k; i++) {
		char temp[21];
		fd.get(temp, 21);
		char temp1[11];
		fd.get(temp1, 11);
		int populiacija;
		fd >> populiacija;
		fd.ignore(80, '\n');
		a.push_back({temp1, {}, {}, 0, 0});
		a.back().miestai.push_back(temp);
		a.back().zmoniu.push_back(populiacija);
	}
}

void tikapskritys(std::vector<apskritis> &a, std::vector<apskritis> &tinka) {

	for(int i=0; i<a.size(); i++) {
		for(int j=0; j<a.size()-1; j++) {
			if(a[j].pav < a[j+1].pav) std::swap(a[j], a[j+1]);
		}
	}


	tinka.push_back(a[0]);
	for(int i=1; i<a.size(); i++) {
		if(a[i].pav != a[i-1].pav)tinka.push_back(a[i]);
		else {
			tinka.back().miestai.insert(tinka.back().miestai.end(), a[i].miestai.begin(), a[i].miestai.end());
			tinka.back().zmoniu.insert(tinka.back().zmoniu.end(), a[i].zmoniu.begin(), a[i].zmoniu.end());
		}
	}
}

void populiacijoms(std::vector<apskritis> &a, std::vector<apskritis> &tinka) {
	//skirta maziausios populiacijos ir bendros populiacijos radimui
	for(int i=0; i<tinka.size(); i++) {
		int minsk=INT_MAX;
		int total=0;

		for(int j=0; j<tinka[i].miestai.size(); j++) {
			total+= tinka[i].zmoniu[j];
			if(tinka[i].zmoniu[j] < minsk) minsk = tinka[i].zmoniu[j];
		}
		tinka[i].maziausia = minsk;
		tinka[i].bendrai = total;
	}
}

void rasyti(std::ofstream &fr, std::vector<apskritis> &tinka) {

	//surikiuojam pagal maziausia populiacija nes taip praso isvedimas
	for(int i=0; i<tinka.size(); i++) {
		for(int j=0; j<tinka.size()-1; j++) {
			if(tinka[j].maziausia > tinka[j+1].maziausia)std::swap(tinka[j], tinka[j+1]);
		}
	}

	fr <<tinka.size() <<'\n';
	for(int i=0; i<tinka.size(); i++) {
		fr << tinka[i].pav << ' '<<tinka[i].maziausia <<' ' <<tinka[i].bendrai<<'\n';
	}
}

int main()
{

	std::ofstream fr("U2rez.txt");
	int k;

	std::vector<apskritis> a;
	std::vector<apskritis> tinka;
	skaityti(k, a);
	tikapskritys(a, tinka);
	populiacijoms(a, tinka);
	rasyti(fr, tinka);





	return 0;
}
