#include<iostream>
using namespace std;

class amit{
	private:
	int a;
	string name;
	
	public:
	void trial(){
		a = 4;
		name = "amit";
	}
	
};

int main(){
	//int s;
	//std::cin >> s;
	//std::cout << s;
	//for(int i = 1; i <= 10; i++){
		//cout << i*n << endl;
	//}
	amit obj;
	obj.trial();
	
	return 0;
}
