#include <bits/stdc++.h>

struct vieta{
    std::string pav;
    int min;
};

void skaityti(int &n, std::vector<vieta> &v){
     std::ifstream fd("U2.txt");
     fd >> n;fd.ignore(80, '\n');
     
     v.resize(n);
    
    for(int i=0; i<n; i++){
        char temp[21];
        fd.get(temp, 21);
        v[i].pav = temp;
        fd >> v[i].min;
        fd.ignore(80, '\n');
    }
     
}


int main()
{
   
    std::ofstream fr("U2rez.txt");
    
    int n;
    std::vector<vieta> v;
    
    skaityti(n, v);

    std::vector<vieta> tinka;
    
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size()-1; j++){
            if(v[j].pav < v[j+1].pav) std::swap(v[j], v[j+1]);
        }
    }
    
    tinka.push_back(v[0]);
    for(int i=1; i<v.size(); i++){
        if(v[i].pav != v[i-1].pav) tinka.push_back(v[i]);
        else tinka.back().min += v[i].min;
    }

    for(int i=0; i<tinka.size(); i++){
        for(int j=0; j<tinka.size()-1; j++){
            if(tinka[j].min == tinka[j+1].min && tinka[j].pav > tinka[j+1].pav)std::swap(tinka[j], tinka[j+1]);
            if(tinka[j].min < tinka[j+1].min) std::swap(tinka[j], tinka[j+1]);
        }
    }

    for(int i=0; i<tinka.size(); i++){
        fr << tinka[i].pav <<  ' '<<tinka[i].min <<'\n';
    }



    return 0;
}
