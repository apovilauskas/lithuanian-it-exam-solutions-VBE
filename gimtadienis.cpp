#include <bits/stdc++.h>

struct laikas{
    std::string diena;
    int valanda;
    std::vector<std::string> draugai;
};

int main()
{
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    int d, dr;
    fd >> d >> dr;
    fd.ignore(80, '\n');
    std::vector<laikas>vieta;
    for(int i=0; i<d; i++){
        char savd[4];
        fd.get(savd, 4);
        int temp;
        fd >> temp;
        for(int j=0; j<temp; j++){
            int vall;
            fd >> vall;
            vieta.push_back({savd, vall});
        }
        fd.ignore(80, '\n');
    }
    
    for(int i=0; i<dr; i++){
        char vard[13];
        fd.get(vard,13);
        int laiku;
        fd >> laiku;
        for(int j=0; j<laiku; j++){
            std::string savd;
            int vall;
            fd >> savd >> vall;
            vieta.push_back({savd, vall, {vard}});
        }
        fd.ignore(80, '\n');
    }
    
    for(int i=0; i<vieta.size(); i++){
        for(int j=0; j<vieta.size(); j++){
            if(vieta[j].diena == vieta[j+1].diena && vieta[j].valanda < vieta[j+1].valanda) std::swap(vieta[j], vieta[j+1]);
            else if(vieta[j].diena < vieta[j+1].diena) std::swap(vieta[j], vieta[j+1]);
        }
    }
    std::vector<laikas> tinkami;
    tinkami.push_back(vieta[0]);
    for(int i=1; i<vieta.size()-1; i++){
        if(vieta[i].diena != vieta[i-1].diena || vieta[i].valanda != vieta[i-1].valanda){
            tinkami.push_back(vieta[i]);
        }
        else tinkami.back().draugai.insert(tinkami.back().draugai.end(), vieta[i].draugai.begin(), vieta[i].draugai.end());
    }
    
    for(int i=0; i<tinkami.size(); i++){
        for(int j=0; j<tinkami.size()-1; j++){
            if(tinkami[j].draugai.size() < tinkami[j+1].draugai.size()) std::swap(tinkami[j], tinkami[j+1]);
        }
    }
    
    for(int i=0; i<tinkami.size(); i++){
        if(tinkami[i].draugai.size() >=4){
            fr << tinkami[i].diena << ' ' <<tinkami[i].valanda << ' ' << tinkami[i].draugai.size() << "\n";
        for(int j=0; j<tinkami[i].draugai.size(); j++){
            fr << tinkami[i].draugai[j] << '\n';
        }

        }
        
    }

    


    return 0;
}
