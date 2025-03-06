#include <bits/stdc++.h>

struct indai {
	int vienas=0, trys=0, penki=0;
};

void skaitymas(indai &turimi, indai &kainos, int &aliejus, int &islaidos) {
	std::ifstream fd("U1.txt");
	fd >> turimi.vienas >> turimi.trys >> turimi.penki >> aliejus;
	fd >> islaidos >> kainos.vienas >> kainos.trys >> kainos.penki;


}

void pilstymas(indai &turimi, int &aliejus, indai &pripilti) {

	while(aliejus >= 5 && turimi.penki >0) {
		turimi.penki--;
		pripilti.penki ++;
		aliejus-= 5;
	}
	while(aliejus >= 3 && turimi.trys >0) {
		turimi.trys--;
		pripilti.trys ++;
		aliejus-= 3;
	}

	while(aliejus >= 1 && turimi.vienas >0) {
		turimi.vienas--;
		pripilti.vienas ++;
		aliejus-= 1;
	}

}

void rasymas(indai &turimi, indai &pripilti, int &aliejus, int &islaidos, indai&kainos ) {
	std::ofstream fr("U1rez.txt");
	indai perkami;

	fr << pripilti.vienas << ' ' <<pripilti.trys << ' ' <<pripilti.penki <<' ' <<aliejus <<'\n';
	fr << turimi.vienas << ' ' <<turimi.trys << ' ' <<turimi.penki <<'\n';

	while(aliejus >= 5) {
		perkami.penki++;
		aliejus-= 5;
	}
	while(aliejus >= 3) {
		perkami.trys++;
		aliejus-= 3;
	}

	while(aliejus >= 1) {
		perkami.vienas++;
		aliejus-= 1;
	}
	fr << perkami.vienas << ' ' <<perkami.trys << ' ' <<perkami.penki <<'\n';
	int pelnas;
	fr << ((pripilti.penki + perkami.penki)*kainos.penki +
	       (pripilti.trys + perkami.trys)*kainos.trys +
	       (pripilti.vienas + perkami.vienas)*kainos.vienas)-islaidos;
}

int main()
{

	indai turimi, pripilti, kainos;
	int aliejus, islaidos;
	skaitymas(turimi, kainos, aliejus, islaidos);
	pilstymas(turimi, aliejus, pripilti);
	rasymas(turimi, pripilti, aliejus, islaidos, kainos);


	return 0;
}
