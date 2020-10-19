#include<bits/stdc++.h>
using namespace std;
int a[20][5];
class Student{
	public:
	int  n = 4;
	int count = 0;
	// make n = 20 for the real input.
	void GetInfo(){
		cout << "Enter the  marks of each sub for 5 students:\n";
		for(int i = 0; i<4; i++){ //
			cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
		}
	}
	void ShowAvg(){
		cout << "Averages are as follows:\n";
		double average = 0.0, sum = 0.0;
		for(int i = 0; i<n; i++){
			sum = 0.0;
			for(int j = 0; j < 5; j++)
				sum += a[i][j];
				
			average = sum / 5.0;	
			if(average < 50.0) count++;		
			cout << average << endl;
		}
	}
	void BelowAvg(){
		cout << "Students below 50 are:\n";
		cout << count << endl;
	}
	
	void Disp(){
		cout << "Displaying marks:\n";
		for(int i = 0; i<n; i++){
			for(int j = 0; j <5; j++)
			cout << a[i][0] << " "; 		
		}
		cout << endl;
	}
};

int main(){
	Student obj;
	obj.GetInfo();
	obj.ShowAvg();
	obj.BelowAvg();
	obj.Disp();
	return 0;
}
