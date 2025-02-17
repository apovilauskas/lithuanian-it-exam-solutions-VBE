#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Marsrutai{
    int kelintas;
    int ilipo =0;
    int islipo = 0;
    
    
};

int main()
{
    int k; //irasu
    std::ifstream fd("duom.txt");
    std::ofstream fr("rez.txt");
    fd >> k;
    
    std::vector<Marsrutai> m(k);
    
    int temp;
    for(int i=0; i<k; i++){
        fd >> m[i].kelintas >> temp;
        if(temp > 0) m[i].ilipo += temp;
        else m[i].islipo += temp;
        
    }
    
   std::sort(m.begin(), m.end(), [](Marsrutai &a, Marsrutai &b){
       return a.kelintas < b.kelintas;
       
   });
   std::vector<Marsrutai> m1;
         for(int i=0; i<k; i++){
             
             if(!m1.empty() && m1.back().kelintas == m[i].kelintas){
                 m1.back().ilipo += m[i].ilipo;
                 m1.back().islipo == m[i].islipo;
             }
            else {
                m1.push_back(m[i]);
            }
    }
   
 
 for(int i=0; i<m1.size(); i++){
     fr << m1[i].kelintas << ' ' <<m1[i].ilipo << ' '<< m1[i].islipo << '\n';
     
 }
    
  
    return 0;
}
