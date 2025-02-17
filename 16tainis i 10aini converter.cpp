#include <iostream>
#include <fstream>
#include <vector>

int convert(char temp) {
    if (temp >= 'A' && temp <= 'F') return temp - 'A' + 10;
    return temp - '0';
}

int main() {
    int ilgis, plotis;
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");

    if (!fd.is_open() || !fr.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    fd >> ilgis >> plotis;

    std::vector<int> a;
    for (int i = 0; i < ilgis * plotis * 3; i++) {
        char temp, temp1;
        fd >> temp >> temp1; // Read two characters (hexadecimal digits)
        a.push_back(convert(temp) * 16 + convert(temp1));
    }

    for (int i = 0; i < a.size(); i++) {
        fr << a[i];
        if ((i + 1) % 3 == 0) fr << "; ";
        else fr << ' ';
    }

    return 0;
}
