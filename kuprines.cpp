#include <iostream>
#include <fstream>

int sunkiausia(){
    std::ifstream fd("U1.txt");
    
    int x, temp, maxi=0;
    fd >>x;
    for(int i=0; i<x; i++){
        fd >>temp;
        if(temp>maxi) maxi = temp;
    }
    return maxi;
}

int main()
{
 int maxi = sunkiausia();

std::ifstream fd("U1.txt");
int temp, x, suma=0;
fd >> x;
for(int i=0; i<x; i++){
    fd >> temp;
    if(temp * 2 <= maxi) suma++;
}
std::ofstream fr("U1rez.txt");
fr << maxi << ' ' <<suma;
    return 0;
}
