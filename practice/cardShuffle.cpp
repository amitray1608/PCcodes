
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);

  vector<int> deck(52, 0);
  string S[] = {"HEARTS", "SPADES", "DIAMONDS", "CLUBS"};
  string R[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King","Ace"};

  int n = 52;
  for (int i = 0; i < n; i++) {
    deck[i] = i;
  }

  
  for (int i = 0; i < n; i++) {
    int index = (int)(rand() % n);
    int temp = deck[i];
    deck[i] = deck[index];
    deck[index] = temp;
  }

  cout << "\n\nShuffled Deck\n\n";  
  for (int i = 0; i < 52; i++) {
    string suit = S[deck[i] / 13];
    string rank = R[deck[i] % 13];
    cout << rank << " of " << suit << '\n';
  }

  cout << "\n\nSorted Deck\n\n";  

  sort(deck.begin(), deck.end());
  for (int i = 0; i < 52; i++) {
    string suit = S[deck[i] / 13];
    string rank = R[deck[i] % 13];
    cout << suit << " of " << rank << '\n';
  }

  return 0;
} //Hajimemashite

