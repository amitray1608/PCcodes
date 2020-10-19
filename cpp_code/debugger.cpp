#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl;

template<typename... T>
void read(T&... args){
	((cin >> args), ...);
}

template<typename... T>
void write(T&... args){
	((cout << args << " "), ...);
}


int main(){
	int x, y, z, zz;
	read(x, y, z , zz);
	//cin >> x >> y >> z;
	//deb(x);
	//deb(y);
	//deb(z);
	write(x, y, z, zz);
return 0;
}
