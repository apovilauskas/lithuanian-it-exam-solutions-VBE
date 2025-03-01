#include <bits/stdc++.h>

std::string konvert(int sk){
    std::string ats[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    return ats[sk/16]+ats[sk%16];
    
}


int main()
{
    std::ifstream fd("U1.txt");
    std::ofstream fr("U1rez.txt");
    int a,b;
    fd >> a >> b;
    
    for(int i = 0; i<a; i++){
        for(int j=0; j<b; j++){
            if(j!=0) fr <<';';
            int sk;
            fd >> sk;
            fr << konvert(sk);
            fd >> sk;
            fr << konvert(sk);
            fd >> sk;
            fr <<konvert(sk);
        }
        fr << '\n';
    }
    

    return 0;
}
