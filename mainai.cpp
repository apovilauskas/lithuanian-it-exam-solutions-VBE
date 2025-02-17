#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <iostream>

struct Pinigai{
    int nominalai;
    int kiekiai;
};

void rasymas(int &suma, int &suma1, std::vector<Pinigai> &babkes, std::vector<Pinigai> &babkes1);

void nuskaitymas(){
    std::vector<Pinigai> babkes; //nominalai ir kiekiai
  std::vector<Pinigai> babkes1;
  std::ifstream fd("U1.txt");
  
   int x; //kiek
  
 fd>> x;
 babkes.resize(x);
 int suma=0; //vertes
for(int i=0; i<x; i++){
    fd >> babkes[i].nominalai; 
}
for(int i=0; i<x; i++){
    fd >> babkes[i].kiekiai; 
}
for(int i=0; i<babkes.size(); i++){
   suma+= babkes[i].kiekiai*babkes[i].nominalai;
}

 fd >> x;   
 babkes1.resize(x);
 int suma1=0;
 for(int i=0; i<x; i++){
    fd >> babkes1[i].nominalai; 
}
for(int i=0; i<x; i++){
    fd >> babkes1[i].kiekiai; 
}

for(int i=0; i<babkes.size(); i++){
   suma1+= babkes1[i].kiekiai*babkes1[i].nominalai;
}

rasymas(suma, suma1, babkes, babkes1);
}

void rasymas(int &suma, int &suma1, std::vector<Pinigai> &babkes, std::vector<Pinigai> &babkes1){
    std::ofstream fr("U1rez.txt");
    int monetu=0;
    
    for(int i=0; i<babkes1.size(); i++){
        fr << babkes1[i].nominalai << ' ' << suma/babkes1[i].nominalai << '\n';
        monetu += suma/babkes1[i].nominalai;
        suma = suma - babkes1[i].nominalai * (suma/babkes1[i].nominalai);

    }
    fr << monetu;
    fr << "\n\n";
    monetu =0;
    
    for(int i=0; i<babkes.size(); i++){
        fr << babkes[i].nominalai << ' ' << suma1/babkes[i].nominalai<< '\n';
        monetu += suma1/babkes[i].nominalai;
        suma1 = suma1 - babkes[i].nominalai * (suma1/babkes[i].nominalai);
        
    }
    fr << monetu;
    fr << "\n\n";
    
}

int main()
{
  nuskaitymas();
  
 
    
    return 0;
}
