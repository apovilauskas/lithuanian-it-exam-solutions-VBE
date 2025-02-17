#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

struct Gele{
    int nr;
    int pradzia;
    int galas;
    int suma =0;
};

int main()
{
    int n; //geliu
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    fd >> n;
    std::vector<Gele> g(n);
    
    for(int i=0; i<n; i++){
        int temp, temp1;
        fd>> g[i].nr;
        fd >> temp >> temp1;
        g[i].pradzia = 100*temp+temp1;
        fd >> temp >> temp1;
        g[i].galas = 100*temp+temp1;

    }
    
    std::sort(g.begin(), g.end(), [](Gele &a, Gele &b){
        return a.pradzia > b.pradzia;
    });
    
    for(int i=0; i<g.size(); i++){
        g[i].suma+= i;
        //fr << g[i].nr << g[i].suma;
    }
    
    std::sort(g.begin(), g.end(), [](Gele &a, Gele &b){
        return a.galas < b.galas;
    });
    
    for(int i=0; i<g.size(); i++){
        g[i].suma+= i;
        
    }
    int min = n+1;
    Gele mini;
    for(int i=0; i<g.size(); i++){
        if(g[i].suma<min) {
            min = g[i].suma;
            mini = g[i];
        }
    }
    int total=0;
    for(int i=0; i<g.size(); i++){
        if(g[i].pradzia <= mini.pradzia && g[i].galas >= mini.galas) total++;
        
    }
    fr << total << '\n';
    std::string str=  std::to_string(mini.pradzia);
    fr << str[0] << ' ' << str[1] <<str[2];
    fr <<  ' ';
    str=  std::to_string(mini.galas);
    fr << str[0] << ' ' << str[1] <<str[2];
    fr <<  ' ';
    

    
    
    return 0;
}
