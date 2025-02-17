#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Marsrutai{
    
int nr;//marsruto nr
int ilipo=0;
int islipo=0;
};

int main()
{
    int n;//irasu
    int m; //marsrutu
    std::ifstream fd("U1.txt");
    std::ofstream fr("r.txt");
    
    fd >> n;
    std::vector<Marsrutai> mar;

std::vector<Marsrutai>temp(n);
int tempe;
    for(int i=0; i<n; i++){
        fd >> temp[i].nr;
        fd >> tempe;
        if(tempe > 0) temp[i].ilipo += tempe;
        else if(tempe <0) temp[i].islipo += tempe;
    }
    
   for(int i=0; i<temp.size(); i++){
      // fr << temp[i].nr<< ' ' << temp[i].ilipo << ' '<<temp[i].islipo << '\n';
      bool yra =0;
      for(int p=0; p<mar.size(); p++){
          if(mar[p].nr == temp[i].nr){
              yra=1;
              mar[p].ilipo += temp[i].ilipo;
              mar[p].islipo += temp[i].islipo;
          }
      }
      if(yra ==0) mar.push_back(temp[i]);
   } 
    
    std::sort(mar.begin(), mar.end(), [](Marsrutai &a, Marsrutai &b){
        return a.nr < b.nr;
    });
    
    for(int i=0; i<mar.size(); i++){
       fr << std::fixed << std::right << std::setw(4) << mar[i].nr << ' '; 
    }
    fr << '\n';
     for(int i=0; i<mar.size(); i++){
       fr << std::fixed << std::right << std::setw(4) << mar[i].ilipo << ' '; 
    }
     fr << '\n';
      for(int i=0; i<mar.size(); i++){
       fr << std::fixed << std::right << std::setw(4) <<mar[i].islipo << ' '; 
    }
    int maxi =0;
    int maxii=0;
    for(int i=0; i<mar.size(); i++){
        if(mar[i].ilipo > maxi) {
            maxi = mar[i].ilipo;
            maxii = mar[i].nr;
        }
    }
    fr << '\n' << maxii;
    return 0;
}
