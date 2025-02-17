#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

struct Pinigs{
    
    std::string vards;
    double babks;
};

int main()
{
    std::ifstream fd("U2duom.txt");
    std::ofstream fr("U2rez.txt");
    int n;
    fd >> n;
    fd.ignore(80, '\n');
    std::vector<Pinigs> babkes(n);
    char vardas[16];
    double temp1, temp2;
    double viso=0;
    for(int i=0; i<n; i++){
        fd.get( vardas, 15);
        babkes[i].vards =(vardas);
        fd >> temp1 >> temp2;
        fd.ignore(80, '\n');
        babkes[i].babks=(temp1*temp2);
         viso += temp1 * temp2;
         
    }
    fr << std::fixed << std::setprecision(2) << viso;
    int virs=0;
    for(int i=0; i<babkes.size(); i++){
       if(babkes[i].babks >= viso/babkes.size()) virs++;
    }
    fr << "\n" <<virs << '\n';
    for(int i=0; i<babkes.size(); i++){
        fr << babkes[i].vards << ' '<<std::right << std::setw(6)  << std::fixed << std::setprecision(2) << babkes[i].babks << '\n';
    }
    return 0;
}
