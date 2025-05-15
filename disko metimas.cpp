#include <bits/stdc++.h>

struct metikas {
	std::string kodas;
	double olimp;
	double iki; //geriausias iki
	int data;
	std::string salis;
};

void skaityti(int n, std::vector<metikas> &met) {
	std::ifstream fd("Olimpines.csv");
	fd >> n;
	metikas temp;
	for(int i=0; i<n; i++) {
		fd >> temp.kodas >>temp.olimp;
		met.push_back(temp);
		fd.ignore(80,'\n');
	}

	std::string antraste;
	std::getline(fd, antraste, '\n');
	std::getline(fd, antraste, '\n');
	while(std::getline(fd, temp.kodas,';')) {
		char skyr;
		fd >> temp.iki >> skyr >> temp.data >> skyr;
		std::getline(fd, temp.salis, '\n');
		met.push_back(temp);

	}
}

void pilnai(std::vector<metikas> &met) {

	for(int i=0; i<met.size(); i++){
		for(int j=0; j<met.size()-1; j++) {
			if(met[j].kodas < met[j+1].kodas)std::swap(met[j], met[j+1]);
		}
}

	std::vector<metikas>pilni;
	pilni.push_back(met[0]);
	for(int i=1; i<met.size(); i++) {
		if(met[i].kodas != met[i-1].kodas)pilni.push_back(met[i]);
		else {
			pilni.back().iki = met[i].iki;
			pilni.back().data = met[i].data;
			pilni.back().salis = met[i].salis;
		}
	}
	met = pilni;
}

double vidurkis (std::vector<metikas> &met){
    double vid=0;
    for(int i=0; i<met.size(); i++){
        vid += met[i].olimp;
    }
    return vid/met.size();
} 

double skirtumas(std::vector<metikas> &met){
    double min=INT_MAX, max =INT_MIN;
    for(int i=0; i<met.size(); i++){
        if(met[i].olimp >max)max = met[i].olimp;
        if(met[i].olimp <min)min = met[i].olimp;
    }
    return max-min;
    
}

double vidgeriausiu(std::vector<metikas> &met){
    double vidurkis=0;
    for(int i=0; i<met.size(); i++){
        vidurkis += met[i].iki;
    }
    return vidurkis/met.size();
    
}

double lyginimas(std::vector<metikas> &met){
    double vido=0, vid=0;
    for(int i=0; i<met.size(); i++){
        vido+=met[i].olimp;
    
    }
    vido/=met.size();
    
    for(int i=0; i<met.size(); i++){
        vid+= met[i].iki;
    }
    vid/=met.size();
    return vid-vido;
}

int seniausiasbest(std::vector<metikas> &met){
    int index;
    int seniausia=INT_MAX;
    for(int i=0; i<met.size(); i++){
        if(met[i].data < seniausia){
            index = i;
            seniausia = met[i].data;
        }
    }
    return index;
}

void skirtumai(std::vector<metikas> &met, std::ofstream &fr){
    
    for(int i=0; i<met.size(); i++){
        for(int j=0; j<met.size()-1; j++){
            if(met[j].iki-met[j].olimp >met[j+1].iki - met[j+1].olimp)std::swap(met[j], met[j+1]);
             if(met[j].iki-met[j].olimp ==met[j+1].iki - met[j+1].olimp && met[j].kodas.substr(1)>met[j+1].kodas.substr(1))std::swap(met[j], met[j+1]);
        }
    }
    
    for(int i=0; i<met.size(); i++){
        fr << met[i].kodas.substr(1) <<' '<< met[i].iki-met[i].olimp << " m"<<'\n';
    }
    
}


void rasyti(std::vector<metikas> &met){
    std::ofstream fr("Rezultatai.txt");
    
    fr <<"Disko metimo duomenų analizės rezultatai:\n-\nOlimpinės žaidynės:\nVidutiniškai diskas skriejo ";
    fr <<std::fixed << std::setprecision(2)<< vidurkis(met) <<" m." ;
    fr <<"\nSkirtumas tarp didžiausio ir mažiausio rezultato: ";
    fr <<skirtumas(met) << " m.";
    fr <<"\n-\nGeriausi rezultatai:\nVidutiniškai diskas skriejo ";
    fr <<vidgeriausiu(met)<<" m.";
    fr <<"\nVidurkis ";
    fr <<lyginimas(met);
    fr <<" m didesnis negu olimpinėse žaidynėse\n-\nSeniausiai pasiektas geriausias rezultatas:\n";
    int ix= seniausiasbest(met);
    fr << met[ix].kodas.substr(1) << ' ' <<met[ix].iki << ' '<<met[ix].data/10000 << ' '<<met[ix].salis;
fr <<"\n-\nSkirtumas tarp sportininkų pasiekimų:\n";
    skirtumai(met, fr);
    
}

int main()
{

	
	int n;
	std::vector<metikas> met;

	skaityti(n, met);
	pilnai(met);
	rasyti(met);
	

	return 0;
}
