#include <bits/stdc++.h>

struct dalykas{
    std::string pav;
    std::vector<std::string>mokiniai;
    std::vector<int>paz;
};

int main()
{
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    int n;
    fd >> n;
    
    std::vector<dalykas> a(n);
    
    for(int i=0; i<n; i++){
        std::string tempv, tempp;
        fd >> tempv >> tempp;
        
        int pz;
        fd >> pz;
        double vidurkis=0;
        for(int j=0; j<pz; j++){
            int temp;
            fd >> temp;
            vidurkis+= temp;
        }
        vidurkis/= pz;
        if(vidurkis >= 9){
            a[i].pav = tempp;
        a[i].mokiniai.push_back(tempv);
        }
    }
    
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a.size()-1; j++){
            if(a[j].pav > a[j+1].pav)std::swap(a[j], a[j+1]);
        }
    }
        std::vector<dalykas> b;
        b.push_back(a[0]);
        for(int i=1; i<a.size(); i++){
            if(a[i].pav != a[i-1].pav) b.push_back(a[i]);
            else{
                b.back().mokiniai.insert(b.back().mokiniai.end(), a[i].mokiniai.begin(), a[i].mokiniai.end());
            }
        }

        for(int i=1; i<b.size(); i++){
            fr << b[i].pav << ' ' <<b[i].mokiniai.size() << '\n';
            for(int j=0; j<b[i].mokiniai.size(); j++){
                fr << b[i].mokiniai[j] <<'\n';
            }
            
        }

    return 0;
}
