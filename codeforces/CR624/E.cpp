#include <bits/stdc++.h>
using namespace std;
vector<int> v; 
vector<int> v2; 
void printDivisors1(int n) 
{ 
    // Vector to store half of the divisors 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i==0) 
        { 
            if (n/i == i) // check if divisors are equal 
               v.push_back(n/i); 
            else
            { 
                v.push_back(i);  
  
                // push the second divisor in the vector 
                v.push_back(n/i); 
            } 
        } 
    } 
}
void printDivisors2(int n) 
{ 
    // Vector to store half of the divisors 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i==0) 
        { 
            if (n/i == i) // check if divisors are equal 
               v2.push_back(n/i); 
            else
            { 
                v2.push_back(i);  
  
                // push the second divisor in the vector 
                v2.push_back(n/i); 
            } 
        } 
    } 
}

int main() {
    int t;
    cin >> t;
    while(t--){ 
    int min = INT_MAX;
    int a, b, c;int x[3];
    cin >> a >> b >> c;
    for(int k = 1; k <= 10000; k++)
    { 
        printDivisors1(k); 
    for(unsigned int i = 0; i < v.size(); i++)
    {
        printDivisors2(v[i]); 
        for(unsigned int j = 0; j < v2.size(); j++)
        {
            int a1 = abs(a- v2[j]);
            int a2 = abs(b-v[i]);
            int a3 = abs(c-k);
            if(a1 + a2 + a3 < min && v[i] >= v2[j])
            {
                min = a1 + a2 + a3;
                x[0] = v2[j]; x[1] = v[i]; x[2] = k;
            }
        }
        v2.clear();
    }
    v.clear();
    }
   cout << min << endl;
   cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }
      } 
