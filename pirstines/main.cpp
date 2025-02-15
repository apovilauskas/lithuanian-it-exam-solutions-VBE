#include <bits/stdc++.h>

struct pirstine{
    int lytis; //3 vyras 4 moteris
    int ranka; //1 kaire 2 desine
    int dydis;
    bool naudojama = 1;
};

int main()
{
    std::ifstream fd("U1.txt"); 
    std::ofstream fr("U1rez.txt");
    
    int n;
    fd >> n;
    int vyrisku=0, moterisku=0;
    int tvyr=0, tmot=0;
    std::vector<pirstine> a(n);
    std::vector<pirstine> b;
    for(int i=0; i<n; i++){
        fd >> a[i].lytis >> a[i].ranka >> a[i].dydis;
        if(a[i].lytis == 3)vyrisku++;
        else moterisku++;
    }
    
    for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a.size(); j++){
            if(a[i].lytis == a[j].lytis && a[i].ranka != a[j].ranka && 
            a[i].dydis == a[j].dydis && a[i].naudojama ==1){
                b.push_back(a[i]);
                a[i].naudojama =0;
                a[j].naudojama = 0;
            }
        }
    }
    
    for(int i=0; i<b.size(); i++){
        if(b[i].lytis == 3) tvyr ++;
        else tmot++;
    }
    
    fr << tmot <<'\n';
    fr << tvyr <<'\n';
    fr << moterisku-(tmot*2) <<'\n';
    fr << vyrisku-tvyr*2 <<'\n';

    return 0;
}
