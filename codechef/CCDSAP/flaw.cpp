/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	//Write code here
	//int n;
	//cin >> n;
	//string s[n];
	//map<string, int>check;
	//for(int i = 0; i < n; i++)
		//cin >> s[i], check[s[i]] = i;
	//int m;
	//cin >> m;
	//string a, b;
	//for(int i = 0; i < m; i++){
		//cin >> a >> b;
		//int posa = check[a], posb = check[b];
		//string r = s[posa+1];
		//swap(s[posa+1], s[posb]);
		//check[b] = posa+1;
		//check[r] = posb;
	//}
	//for(auto &i : s)
for (int i = 1; i <= 5; i++) {
   for (int j = 1; j <= i-1; j++) {
      cout << (" ");
   }
   for (int j = 1; j <= (5-i+1)*2-1; j++) {
      cout <<("*");
   }
   cout << endl;
}

}
