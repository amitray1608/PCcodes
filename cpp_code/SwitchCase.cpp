//to make a simple calculator
#include<bits/stdc++.h>
using namespace std;
int main(){
	// so what operations do we have in a simple calc???
	// +, -, *, /, % right
	//well first ask what operation do you want to perform
	
	cout << "Enter your choice:\n";
	cout << "Enter 1 for addition:\n";
	cout << "Enter 2 for subtraction:\n";
	cout << "Enter 3 for multiplication:\n";
	cout << "Enter 4 for dividion:\n";
	cout << "Enter 5 for modulo:\n";
	int n;
	cin >> n;
	// now we can ask for the operand and store it in two variables
	int a, b;
	cout << "Enter the two numbers to perform the operation:\n";
	cin >> a >> b;
	//~ now lets switch over the value of n:
	switch(n){
		case 1: 
			cout << "sum = " << a+b << endl;
			break;
		case 2:
			cout << "difference = " << a-b << endl;
			break;
		case 3:
			cout << "multiplication = " << a*b << endl;
			break;
		case 4:
			cout << "division = " << a/b << endl;
			break;
		case 5:
			cout << "modulo = " << a%b << endl;
			break;
			// here modulo means remainder....
	}
	
//lets compile and run it
	
	return 0;
}
//~ its not a really good calculator XD but its up to your creativity how you create 
//~ it
//~ and try making it yourself with features like square cube and so on


