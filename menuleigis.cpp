#include <bits/stdc++.h>

struct kord {
	int x,y;
};

int main()
{
	std::ifstream fd("U1.txt");
	std::ofstream fr("U1rez.txt");

	kord prad;
	kord dabar;
	fd >> prad.x >>prad.y;
	dabar = prad;

	int n;
	fd >> n;


	for(int i=0; i<n ; i++) {
		int k;
		bool buvo=0;
		fd >> k;
		int j=0;
		std::vector<int>seka;
		for(j; j<k; j++) {
			int kom;
			fd >> kom;
			seka.push_back(kom);
			if(kom == 1) {
				dabar.x++;
				dabar.y++;
			}
			if(kom == 2) {
				dabar.x++;
				dabar.y--;
			}
			if(kom == 3) {
				dabar.x--;
				dabar.y--;
			}
			if(kom == 4) {
				dabar.x--;
				dabar.y++;
			}
			if(dabar.x == prad.x && dabar.y ==prad.y) {
				buvo = 1;
				fd.ignore(80,'\n');
				break;
			}
		}
		if(buvo ==1) {
			fr << std::left <<std::setw(20)<<"pasiektas tikslas";
			for(int i=0; i<seka.size(); i++) {
				fr << seka[i] <<' ';

			}
			fr << seka.size()<<'\n';

		}
		
		if(buvo ==0) {
			fr << std::setw(20) << std::left <<"sekos pabaiga";
			for(int i=0; i<seka.size(); i++) {
				fr << seka[i] <<' ';

			}
			fr << seka.size() <<' ';
			fr << dabar.x << ' ' <<dabar.y<<'\n';
		}
        dabar = prad;
	}





	return 0;
}
