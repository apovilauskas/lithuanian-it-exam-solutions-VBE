#include <bits/stdc++.h>

struct testas{
    std::string pav;
    int islaike=0;
    int neislaike = 0;
    int maxx=INT_MIN;
    int mokiniu=1;
    double proc(){
        return islaike * 100.00 / (islaike+neislaike);
    }
    
};

int main()
{
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    
    int m;
    fd >> m;
    fd.ignore(80, '\n');
    
    std::vector<testas> t;
    t.resize(m);
    
    for(int i=0; i<m; i++){
        char temp[7];
        fd.get(temp, 7);
        t[i].pav = temp;
        int sum=0;
        for(int j=0; j<10; j++){
            int tempnr;
            fd >> tempnr;
            sum += tempnr;
        }
        if(sum >= 15) t[i].islaike ++;
        else t[i].neislaike ++;
        if(sum > t[i].maxx) t[i].maxx = sum;
        fd.ignore(80, '\n');
    }
    
    for(int i=0; i<t.size(); i++){
        for(int j=0; j<t.size()-1; j++){
            if(t[j].pav >t[j+1].pav){
                std::swap(t[j], t[j+1]);
            }
        }
    }
    std::vector<testas> tinka;
    tinka.push_back(t[0]);
    for(int i=1; i<t.size(); i++){
        if(t[i].pav != tinka.back().pav){
            tinka.push_back(t[i]);
        }
        else{
            tinka.back().mokiniu++;
            tinka.back().islaike += t[i].islaike;
            tinka.back().neislaike += t[i].neislaike;
            if(t[i].maxx > tinka.back().maxx) tinka.back().maxx = t[i].maxx;
        }
    }

    
    for(int i=0; i<tinka.size(); i++){
        fr << tinka[i].pav << ' ' <<tinka[i].mokiniu << ' ' <<std::fixed << std::setprecision(0) << tinka[i].proc()<< "% " <<tinka[i].maxx << '\n';
    }
    
    

    return 0;
}
