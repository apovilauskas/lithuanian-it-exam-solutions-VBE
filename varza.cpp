#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main()
{
    std::ifstream fd("duom.txt");
    std::ofstream fr("rez.txt");


    int n;
    double m, temp;
    fd >> n;
    double sumsum = 0;

    for (int i = 0; i < n; i++) {
        fd >> m;
        double suma = 0;
        for (int p = 0; p < m; p++) {
            fd >> temp;
            suma += 1 / temp;
        }
        sumsum += (1 / suma);
    }

    fr << std::fixed << std::setprecision(2) << sumsum;
    return 0;
}
