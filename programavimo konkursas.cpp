#include <bits/stdc++.h>

struct mokinys{
    std::string vardas; 
    std::vector<int> min; //sugaistas laikas kiekvienam uzdaviniui atskirai
    int taskai=0; //bendri taskai
    int issprende; //issprestu uzd kiekis
    int total=0; //bendras laikas
    
};

void skaityti(int u, std::vector<mokinys> &mok, std::vector<int> &umin, std::vector<int> &utaskai){
        
    std::ifstream fd("U1.txt");
    
    fd >> u;
    
    //uzduociu nuskaitymai
      for(int i=0; i<u; i++){
        int temp;
        fd >> temp;
        umin.push_back(temp);
    }
    
     for(int i=0; i<u; i++){
        int temp;
        fd >> temp;
        utaskai.push_back(temp);
    }
    
    //kiekvieno mokinio duomenu skaitymas
    fd.ignore(80,'\n');
    for(int i=0; i<5; i++){
        char temp[11];
        fd.get(temp, 11);
        mok[i].vardas = temp;
        for(int j=0; j<umin.size(); j++){
            int tempe;
            fd >> tempe;
            mok[i].min.push_back(tempe);
        }
        fd.ignore(80,'\n');
        
    }
    
}

void skaiciuoti(std::vector<mokinys> &mok, std::vector<int> &umin, std::vector<int> &utaskai, int &max){
    
    //tasku skyrimas pagal laika
    for(int i=0; i<mok.size(); i++){
        mok[i].issprende = mok[i].min.size();
        for(int j=0; j<mok[i].min.size(); j++){
            if(mok[i].min[j] > umin[j])mok[i].taskai+=(utaskai[j]/2);
            else if(mok[i].min[j] > 0)mok[i].taskai+=(utaskai[j]);
            else mok[i].issprende--;
        }
    }
    
    //max radimas
    for(int i=0; i<mok.size(); i++){
        if(mok[i].taskai > max)max = mok[i].taskai;
    }
    
    //rikiavimas
    for(int i=0; i<mok.size(); i++){
        for(int j=0; j<mok.size()-1; j++){
            if(mok[j].issprende < mok[j+1].issprende)std::swap(mok[j], mok[j+1]);
        }
    }
    
    //bendras sugaistas laikas
    for(int i=0; i<mok.size(); i++){
        for(int j=0; j<mok[i].min.size(); j++){
            mok[i].total+= mok[i].min[j];
        }
    }
}

void rasyti(int max, std::vector<mokinys> mok){
    std::ofstream fr("U1rez.txt");
    fr << max <<'\n';
    for(int i=0; i<mok.size(); i++){
        if(mok[i].taskai == max)fr << mok[i].vardas <<' ' <<mok[i].issprende << ' ' <<mok[i].total <<'\n';
    }
}

int main()
{
    
    
    
    int u; //uzdaviniu
    std::vector<mokinys> mok(5); //mokiniu
    std::vector<int> umin; //visu uzdaviniu laikai
    std::vector<int> utaskai; //ir maximalus taskai
    int max=INT_MIN; //didziausias surinktu tasku skaicius

    skaityti(u,mok,umin,utaskai);
    skaiciuoti(mok,umin,utaskai, max);
    rasyti(max, mok);
    

    return 0;
}
