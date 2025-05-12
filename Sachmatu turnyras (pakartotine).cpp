#include <bits/stdc++.h>

int main()
{
	std::ifstream fd("U1.txt");
	std::ofstream fr("U1rez.txt");

	std::vector<int> turim(6, 0);
	std::vector<int> reikia{8,2,2,2,1,1};

	int n;
	fd >> n;

	for(int i=0; i<n; i++) {
		int p,b,z,r,k,v;
		fd >> p >> b >> z>>r >> k >>v;
		turim[0]+=(8-p);
		turim[1]+=(2-b);
		turim[2]+=(2-z);
		turim[3]+=(2-r);
		turim[4]+=(1-k);
		turim[5]+=(1-v);
	}

	for(int i=0; i<n; i++) {
		turim[i]/=reikia[i];
	}

	int min=INT_MAX;
	for(int i=0; i<turim.size(); i++) {
		if(turim[i]<min)min = turim[i];
	}

	fr <<min;

	return 0;
}
