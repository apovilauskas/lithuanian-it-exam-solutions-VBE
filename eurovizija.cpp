#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Salis {
	std::string dave;
	std::string gavo;
	int t;
	int kaupimas=0;
};

void skaitymas(std::vector<Salis> &eilute);
void rasymas(std::vector<Salis> &eilute);

int main() {
	std::vector<Salis> eilute;
	skaitymas(eilute);
	rasymas(eilute);

	return 0;
}

void skaitymas(std::vector<Salis> &eilute) {
	std::ifstream fd("duom.txt");

	Salis temp;
	while (getline(fd, temp.dave, ';') &&
	        getline(fd, temp.gavo, ';') &&
	        (fd >> temp.t)) {
		eilute.push_back(temp);
		fd.ignore(80, '\n');
	}


	std::sort(eilute.begin(), eilute.end(), [](Salis &pirmas, Salis &antras) {
		if(pirmas.dave== antras.dave) return pirmas.t > antras.t;
		return pirmas.dave < antras.dave;
	});
}

void rasymas(std::vector<Salis> &eilute) {
	std::ofstream fr("rez.txt");

	std::vector<Salis> sal;
	fr << "Pradinis sąrašas:\n";
	for (int i=0; i<eilute.size(); i++) {
		
		fr << eilute[i].dave << ' ' << eilute[i].gavo << ' ' <<eilute[i].t << '\n';

	}
std::sort(eilute.begin(), eilute.end(), [](Salis &pirmas, Salis &antras) {
		return pirmas.gavo > antras.gavo;
	});


	int k=0;
		for (int i=0; i<eilute.size(); i++) {
		    k=eilute[i].t;
            for(int p=i+1; p<eilute.size(); p++){
                if(eilute[i].gavo ==eilute[p].gavo) k+= eilute[p].t;
            }
        eilute[i].kaupimas = k;

	}
		for (int i=0; i<eilute.size(); i++) {
        if(eilute[i].gavo != eilute[i+1].gavo) sal.push_back(eilute[i]);
        

	}
	
	
	
	fr<<"\nŠaliu gauti taskai:\n";
	for (int i=0; i<sal.size(); i++) {
		fr <<  sal[i].gavo << ' ' <<sal[i].kaupimas << '\n';

	}


}
