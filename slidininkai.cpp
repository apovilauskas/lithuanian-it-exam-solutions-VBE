#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Slidininkai{
    std::string vardas;
    int val, min, sek;
    int fval, fmin, fsek;
    int total=0;
};

void skaityti(std::vector<Slidininkai> &slid, int &n, std::vector<Slidininkai> &fin, int &m){
     std::ifstream fd("U2.txt");
   fd >> n;
 fd.ignore(80, '\n');
  slid.resize(n);
  char temp[21];
  for(int i=0; i<slid.size(); i++){
          fd.get(temp, 20) ;
          slid[i].vardas = temp;
        
      fd >> slid[i].val >> slid[i].min >> slid[i].sek;
   
      fd.ignore(80, '\n');
  }  
  
  
  
  fd >> m;
  fd.ignore(80, '\n');
  fin.resize(m);
  for(int i=0; i<m; i++){
      fd.get(temp,20);
      fin[i].vardas = temp;
      fd >> fin[i].val >> fin[i].min >> fin[i].sek;
      fd.ignore(80, '\n');
  }
    
}

void rasyti(std::vector<Slidininkai> &slid, int &n, std::vector<Slidininkai> &fin, int &m){
     std::ofstream fr("rez.txt");
  for(int i=0; i<n; i++){
      for(int p=0; p<m; p++){
          if(slid[i].vardas == fin[p].vardas){
              fin[p].total = (fin[p].val*3600+fin[p].min*60+fin[p].sek)-(slid[i].val*3600+slid[i].min*60+slid[i].sek);
          }
      }
  }
  std::sort(fin.begin(), fin.end(), [](Slidininkai &a, Slidininkai &b){
     if (a.total == b.total) return a.vardas < b.vardas;
     return a.total < b.total;
  });
  
  for(int i=0; i<m; i++){
      fr << fin[i].vardas << ' '<< fin[i].total/60 << ' ' << fin[i].total%60 << '\n';
  }
    
}

int main()
{
  std::vector<Slidininkai> slid;
  std::vector<Slidininkai> fin;
  int n;
  int m;
  skaityti(slid, n, fin, m);
 rasyti(slid, n, fin, m);
  
  
 

    return 0;
}
