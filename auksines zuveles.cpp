#include <bits/stdc++.h>


struct akvariumas{
int litru;
int zuvu;
};

void tikrinti( std::vector<akvariumas> &a, std::ofstream &fr, int &tinkamu, int &ok){

     for(int i=0; i<a.size(); i++){
    if(a[i].zuvu * 3 > a[i].litru){
        fr << i+1 ;
        fr << " akvariumas "<< (a[i].zuvu * 3 - a[i].litru)/3 << " zuveliu reikia perkelti\n";
        tinkamu += ((a[i].zuvu * 3 - a[i].litru)/3);
    }
    else if(a[i].zuvu * 3 == a[i].litru){
        fr << i+1 << " akvariumas pilnas\n";
        ok++;

    }
     else {
            fr << i+1 << " akvariumas nera perpildytas\n";
            ok++;
    }
   }

}

int main()
{
   std::ifstream fd("duom.txt");
   std::ofstream fr("rez.txt");
   int akvariumu;
   fd >> akvariumu;
   std::vector<akvariumas> a;
   a.resize(akvariumu);
   //nuskaitymas
   for(int i=0; i<akvariumu; i++){
        int templ, tempz;
    fd >> templ >> tempz;
    a[i].litru = templ;
    a[i].zuvu = tempz;
   }


    int tinkamu=0;
    int ok=0;
tikrinti(a, fr, tinkamu, ok);



fr << "Tinkami " << ok << " akvariumai\n";
fr  <<"Is viso reikia perkelti "<<  tinkamu<<'\n';
    return 0;
}
