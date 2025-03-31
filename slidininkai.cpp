#include <bits/stdc++.h>

struct slidininkas{
    std::string vardas; //20 simb
    int sval, smin, ssek;
    int fval, fmin, fsek;
    bool fin = 0;
    int laikas; //sek
};

void skaitymas(int &n, int &m, std::vector<slidininkas> &s){
    std::ifstream fd("U2.txt");
    fd >> n;
    s.resize(n);
    fd.ignore(80, '\n');
    for(int i=0; i<n; i++){
        char temp[21];
        fd.get(temp, 21);
        s[i].vardas = temp;
        fd >> s[i].sval >> s[i].smin >> s[i].ssek;
        fd.ignore(80, '\n');
    }
    
    fd >> m;
    fd.ignore(80, '\n');
    for(int i=0; i<n; i++){
        char temp[21];
        fd.get(temp, 21);
        for(int j=0; j<s.size(); j++){
            if(s[j].vardas == temp){ //nuskaitom finiso laikus jei sutampa ID
                 fd >> s[j].fval >> s[j].fmin >> s[j].fsek;
                 s[j].fin =1;
            }
        }
        
       
        fd.ignore(80, '\n');
    }
}

void laikas(std::vector<slidininkas> &s){
    for(int i=0; i<s.size(); i++){ //konvertuojam laika i sekuindes del patogumo
        s[i].laikas = (s[i].fval * 3600 + s[i].fmin *60 + s[i].fsek)-(s[i].sval * 3600+s[i].smin*60+s[i].ssek);
    }
}

void rikiavimas(std::vector<slidininkas> &s){
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<s.size()-1; j++){
            if(s[j].laikas == s[j+1].laikas && s[j].vardas > s[j+1].vardas)std::swap(s[j], s[j+1]); //jei laikas vienodas tada tikrinam varda
            else if(s[j].laikas > s[j+1].laikas)std::swap(s[j], s[j+1]);
        }
    }
}

void rasymas(std::vector<slidininkas> &s){
        std::ofstream fr("U2rez.txt");
     for(int i=0; i<s.size(); i++){ //jei finisavo tada parasome
        if(s[i].fin)fr <<s[i].vardas << ' '<<s[i].laikas/60 <<' ' <<s[i].laikas%60 <<'\n';
    }
}

int main()
{
    

    
    int n, m; //pradejusiu ir finisavusiu kiekis 
    
    std::vector<slidininkas> s;
    skaitymas(n, m ,s);
    laikas(s);
    rikiavimas(s);
    rasymas(s);
   
    
    return 0;
}
