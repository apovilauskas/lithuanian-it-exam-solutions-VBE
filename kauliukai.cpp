#include <bits/stdc++.h>

struct dievas{
    int tasku=0;
    std::string vardas;
    int lyginiu=0;
};

int main()
{
    std::ifstream fd("U2.txt");
    std::ofstream fr("U2rez.txt");
    
    int n, k;
    fd >> n >>k;
    fd.ignore(80, '\n');
    
    std::vector<dievas> d(n);
    
    for(int i=0; i<d.size(); i++){
        char vardas[11];
        fd.get(vardas, 11);
        d[i].vardas = vardas;
        for(int j=0; j<k; j++){
            int temp;
            fd >> temp;
            if(temp % 2 == 0){
                d[i].lyginiu++;
                d[i].tasku+= temp;
            }
            else{
                d[i].tasku-= temp;
            }
        }
        fd.ignore(80,'\n');
        
    }
    
    for(int i=0; i<d.size(); i++){
        for(int j=0; j<d.size()-1; j++){
            if(d[j].tasku < d[j+1].tasku)std::swap(d[j], d[j+1]);
            if(d[j].tasku == d[j+1].tasku && d[j].lyginiu < d[j+1].lyginiu)std::swap(d[j], d[j+1]);
        }
    }
    
    for(int i=0; i<d.size(); i++){
        if(d[i].tasku != d[0].tasku || d[i].lyginiu!= d[0].lyginiu)break;
        fr << d[i].vardas << ' '<< d[i].tasku <<'\n';
    }

    return 0;
}
