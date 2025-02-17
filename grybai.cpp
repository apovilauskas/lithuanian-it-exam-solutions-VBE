#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Grybautojas{
    std::string vardas;
    int bar=0; //baravykai, raudonikiai, lepsiai
    int rau=0;
    int lep=0;
    int total; //bendrai
    
};
//funkcijos
void rasyti(int &n, std::vector<Grybautojas> &gr);
void skaityti();

int main()
{
    skaityti();
    
    return 0;
}


void skaityti(){
    std::ifstream fd("duom.txt");
    int n; //grybautoju
    int kartu; //grybavimo kartai kiekvienam atskirai
    int a; //laikinam duomenu laikymui
    
    char temp[16]; //laikinai vardams
    
    fd >> n;
    fd.ignore(80, '\n');
    std::vector<Grybautojas> gr(n);
    
    for(int i=0; i<n; i++){
        fd.get(temp, 15);
        gr[i].vardas = temp;
        fd >> kartu;
        fd.ignore(80, '\n');
        for(int j=0; j<kartu; j++){
            fd >> a;
            gr[i].bar += a;
            fd >> a;
            gr[i].rau += a;
            fd >> a;
            gr[i].lep += a;
            gr[i].total = gr[i].bar + gr[i].rau + gr[i].lep;
            fd.ignore(80, '\n');
        }
        
    }
    
    rasyti(n, gr);
}

void rasyti(int &n, std::vector<Grybautojas>&gr){
    std::ofstream fr("rez.txt");
  
  for(int i=0; i<n; i++){
      fr << gr[i].vardas << gr[i].bar<< ' ' << gr[i].rau << ' ' << gr[i].lep << '\n';
  }
    
    std::sort(gr.begin(), gr.end(), [](Grybautojas &a, Grybautojas &b){
        return a.total>b.total;
        
    });
    
    fr << gr[0].vardas << ' ' <<gr[0].total;
    
}
