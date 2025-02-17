#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void kateriai(int pr, int pb, int m1, int m2){
    std::ifstream fd("kateriai_data.txt");
    std::ofstream fr("rez.txt");
    fd >> pr >> pb >> m1 >> m2;
    std::vector<int>pirminiai;
       pr = pr*60;
int pr1 = pr;
int pr2 = pr;
   pb = pb*60; //verciam i minutes
  while(pr <= pb){
       pr += m1;
       pirminiai.push_back(pr);
       
   }
   
   for(int i=0; i<pirminiai.size(); i++){
       pr1 = pr2;
       while(pr1 <= pb){
           pr1 += m2;
           if(pr1 == pirminiai[i]){
               fr << pr1 / 60 << ' '<< pr1%60 << '\n';
               return;
           
           
       }
       }
   }
 
}

int main()
{
   int pr, pb; //valandos
   int m1, m2;
   
   kateriai(pr, pb, m1, m2 );
   std::cout << " ga;im";
    return 0;
}
