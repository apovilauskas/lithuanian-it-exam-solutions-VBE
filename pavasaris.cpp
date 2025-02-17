#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Dienos{
    int ryt, piet, vak;
    int nr;
};

int main()
{
    int n; //irasu
    std::vector<Dienos> d(31);
    std::vector<int> zemiau;
    std::ifstream fd("U1duom.txt");
    std::ofstream fr("U1rez.txt");
    fd >> n;
    int max =0;
    for(int i=0; i<n; i++){
        fd >> d[i].nr >> d[i].ryt >> d[i].piet >> d[i].vak;
        if(d[i].ryt > max) max = d[i].ryt;
        if(d[i].piet >max) max = d[i].piet;
        if(d[i].vak > max) max = d[i].vak;
        if(d[i].ryt >= 20 && d[i].piet >= 20 && d[i].vak >=20) zemiau.push_back(d[i].nr);
    }
   
    
    for(int i=0; i<d.size()-1; i++){
        if(d[i].ryt == max|| d[i].piet == max || d[i].vak == max) fr << d[i].nr << ' ';
        
        
    }
    
    std::sort(d.begin(), d.end(), [](Dienos &a, Dienos &b){
        return a.ryt+a.piet+a.vak > b.ryt + b.piet+b.vak;
        
    });
    
    fr << '\n';
    for(int i=0; i<zemiau.size(); i++){
        fr << zemiau[i] << ' ';
    }
    
    
    return 0;
}
