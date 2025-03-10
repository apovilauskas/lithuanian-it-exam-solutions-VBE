#include <bits/stdc++.h>

struct staciakampis {
    int r = 255, g = 255, b = 255;
    int x1, x2, y1, y2;
};

int main() {
    std::ifstream fd("U2.txt");
    std::ofstream fr("U2rez.txt");

    std::vector<std::vector<staciakampis>> lenta(100, std::vector<staciakampis>(100));

    int n;
    fd >> n;

    int maxx = INT_MIN, maxy = INT_MIN, minx = INT_MAX, miny = INT_MAX;

    for (int i = 0; i < n; i++) {
        int xx1, yy1, xx2, yy2, r1, g1, b1;
        fd >> xx1 >> yy1 >> xx2 >> yy2 >> r1 >> g1 >> b1;

        if(xx1 <minx)minx = xx1;
        if(xx2 >maxx)maxx = xx2;
        if(yy1 <miny)miny = yy1;
        if(yy2 >maxy)maxy = yy2;

        for (int j = xx1; j < xx2; j++) {
            for (int p = yy1; p < yy2; p++) {
                lenta[p][j].r = r1;
                lenta[p][j].g = g1;
                lenta[p][j].b = b1;
            }
        }
    }

    fr << (maxy - miny) << ' ' << (maxx - minx) << '\n';

    for (int i = miny; i < maxy; i++) {
        for (int j = minx; j < maxx; j++) {
            fr << lenta[i][j].r << ' ' << lenta[i][j].g << ' ' << lenta[i][j].b << '\n';
        }
    }

    return 0;
}
