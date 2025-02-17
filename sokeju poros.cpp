#include <bits/stdc++.h>

struct pora {
	std::string pav;
	int sum1=0;
	int sum2=0;

};
void skaitymas(int &n, int &k,std::vector<pora> &a);
void rikiavimas(std::vector<pora> &a);
int balai(std::vector<int> &b);



int main()
{
    int n, k;
    	std::vector<pora> a(n);
skaitymas(n, k, a);


 
 rikiavimas(a);
std::ofstream fr("U2rez.txt");
    for(int i=0; i<a.size(); i++){
        fr << a[i].pav << a[i].sum1 + a[i].sum2 << '\n';
    }

	return 0;
}


void rikiavimas(std::vector<pora> &a){
       for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a.size(); j++){
            if(a[i].sum1 + a[i].sum2 < a[j].sum1 + a[j].sum2) std::swap(a[i], a[j]);
        }
    }
}


int balai(std::vector<int> &b){
    for(int i=0; i<b.size(); i++){
        for(int j=i+1; j<b.size(); j++){
            if(b[i] < b[j]) std::swap(b[i], b[j]);
        }
    }
    b.erase(b.begin());
    b.pop_back();
    
    int suma=0;
    for(int i=0; i<b.size(); i++){
        suma += b[i];
    }
    return suma;
}

void skaitymas(int &n, int &k, std::vector<pora> &a){
    	
	std::ifstream fd("U2.txt");
	fd >> n >> k;
a.resize(n);
	std::vector<int> b;
	fd.ignore(80, '\n');
	char temp[21];
	int tempa;
	for(int i=0; i<n; i++) {
		fd.get(temp, 20);
		a[i].pav = temp;
			fd.ignore(1, '\n');
        for(int j=0; j<k; j++){
            fd >> tempa;
            b.push_back(tempa);
        }
        a[i].sum1 = balai(b);
        b.clear();
        	fd.ignore(80, '\n');
        for(int j=0; j<k; j++){
            fd >> tempa;
            b.push_back(tempa);
        }
        a[i].sum2 = balai(b);
        b.clear();
        	fd.ignore(80, '\n');
	}
}
