#include<bits/stdc++.h>
using namespace std;
class A{
	int a;
	public:
	void Demo(int x){
		a = x;
	}
	void display(){
		cout << a << endl;
	}
};
int main(){
	A o;
	int x = 5;
	o.get(x);
	o.display();
	return 0;
}
