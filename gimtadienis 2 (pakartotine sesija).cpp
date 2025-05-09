#include <bits/stdc++.h>

struct svecias{
    std::string vardas; //15 symb
    std::vector<int> kiekiai;
    std::vector<int> kainos;
};

void skaityti(int &P, int &N, std::vector<int> &kainos, std::vector<svecias> &s){
    std::ifstream fd("U2.txt");
    fd>> P;
    fd.ignore(80, '\n');
    
    kainos.resize(P);
    for(int i=0; i<kainos.size(); i++){
        fd>> kainos[i];
    }
    fd.ignore(80, '\n');
    
    fd >> N;
    s.resize(N);
    fd.ignore(80, '\n');
    for(int i=0; i<N; i++){
        char vardas[16];
        fd.get(vardas, 16);
        s[i].vardas = vardas;
        s[i].kainos = kainos;
        s[i].kiekiai.resize(kainos.size());
        for(int j=0; j< kainos.size(); j++){
            fd >> s[i].kiekiai[j];
        }
        fd.ignore(80, '\n');
    }
    
}

void rasyti(std::vector<svecias> s){
    std::ofstream fr("U2rez.txt");
    
    int summ = 0;
    for(int i=0; i<s.size(); i++){
        fr << s[i].vardas << ' ';
        int sum=0; 
        for(int j=0; j<s[i].kainos.size(); j++){
            sum+=(s[i].kainos[j]*s[i].kiekiai[j]);
        }
        fr << sum <<'\n';
        summ += sum;
    }
   fr << summ/100 << ' ' << summ%100;
    
}

int main()
{
    std::vector<svecias> s;
    int P, N;
    std::vector<int> kainos;
    
    skaityti(P,N, kainos, s);
    rasyti(s);

    return 0;
}
