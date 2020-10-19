#include<iostream>
using namespace std;
int x = 1;
class A{
	public:
	static void function(){
		static int p = 1;
		cout << "(staic)I have been called " << p << "times\n";
		p++;
		cout << "(global) I have been called " << x << "times\n";
		x++; 
	}
};

int main(){
	int n = 10; 
	A o;
	for(int i = 0; i < n; i++)
		o.function();
}
