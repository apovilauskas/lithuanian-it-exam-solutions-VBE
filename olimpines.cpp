#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Atletas{
    std::string pavarde;
    double metrai;
    long data;
    std::string salis;
    
};

void pasiekimai(std::vector<Atletas> at, Atletas &maxi, Atletas &mini, double &skirtumas){
    
    std::sort(at.begin(), at.end(), [](Atletas &pirmas, Atletas &antras){
        return pirmas.metrai < antras.metrai;
        
    });
    
   
    mini = at.front();
    maxi = at.back();
    skirtumas = maxi.metrai - mini.metrai;
}

int main()
{
   std::ifstream fd("duom.txt");
   std::ofstream fr("pisau.txt");
   std::vector<Atletas> at;
   
   Atletas temp;
   while(
       getline(fd, temp.pavarde, ';') &&
       fd >> temp.metrai &&
       fd.ignore() &&
       fd >> temp.data &&
       fd.ignore() &&
       fd >> temp.salis 
       
       ){
          at.push_back(temp);
          fd.ignore(20, '\n');
       }
   Atletas maxi, mini;
   double skirtumas = 0;
   pasiekimai(at, maxi, mini, skirtumas);
   
   
   for(int i=0; i<at.size(); i++){
       fr << at[i].pavarde << ' '<< at[i].metrai << ' '<< at[i].data << ' '<< at[i].salis << '\n';
   }
   fr << maxi.metrai;
   fr << ' '<<mini.metrai;
   fr << ' ' <<skirtumas;

    return 0;
}
