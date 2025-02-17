#include <bits/stdc++.h>

struct taskas{
    int x;
    int y;
};

int main()
{
    std::ifstream fd("U2.txt");
    std::ofstream fr("U2rez.txt");
    taskas pradinis, esamas, tikslas;
    std::vector<int> seka;
    fd >> pradinis.x >> pradinis.y;
    esamas =pradinis;
    fd >> tikslas.x>> tikslas.y;
    int n, k;
    fd >> n;
    for(int i=0; i<n; i++){
        fd >> k;
        bool pasiektas=0;
        for(int j=0; j<k; j++){
            int temp;
            fd >> temp;
            seka.push_back(temp);
            if(temp == 1)esamas.y++;
            if(temp == 2)esamas.x++;
            if(temp == 3)esamas.y--;
            if(temp == 4)esamas.x--;
            if(esamas.x == tikslas.x && esamas.y == tikslas.y) {
                pasiektas =1;
                fr<< "tikslas pasiektas: ";
                for(int p=0; p<seka.size(); p++){
                    fr << seka[p] << ' ';
                }
                fr << seka.size() << '\n';
                seka.clear();
        }
       
            
        }
         if(pasiektas == 0) {
            fr << "seka baigta: ";
            for(int p=0; p<seka.size(); p++){
                fr <<seka[p] << ' ' ;
            }
            fr <<seka.size() << '\n';
        }
    esamas = pradinis;
    seka.clear();
    }
    
    
    return 0;
}
