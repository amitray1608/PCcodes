
#include<bits/stdc++.h>
#include<threads.h>

using namespace std;
using namespace std::chrono;

using ll = unsigned long long;

ll OddSum = 0;
ll EvenSum = 0;

void findOdd(ll s, ll e) {
  for (ll i = s; i <= e; i++) {
    if (i & 1)
      OddSum += i;
  }
}

void findEven(ll s, ll e) {
  for (ll i = s; i <= e; i++) {
    if (~i & 1) 
      EvenSum += i;
  }
}

int main() {
  ll start = 0, end = 1900000000;

  auto startTime = high_resolution_clock::now();
  
  std::thread t1(findEven, start, end);
  std::thread t2(findOdd, start, end);

  t1.join();
  t2.join();
//
//  findOdd(start, end);
//  findEven(start, end);
  
  auto stopTime = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stopTime - startTime);
  
  cout << "OddSum : " << OddSum << '\n';
  cout << "EvenSum : " << EvenSum << '\n';

  cout << "Sec: " << duration.count() / 1000000 << '\n';

  return 0;
} //Hajimemashite

