#include <bits/stdc++.h>
#include <vector>

using namespace std;


bool iscycle(char c, bool graph[][26], bool visited[]) {
    if (visited[c - 'A']) return true;
    visited[c - 'A'] = true;
    for (int i = 0; i < 26; i++) {
        if (graph[c -'A'][i]) {
            if (iscycle((char)('A' + i), graph, visited)) {
                    return true;
            }
        }
    }
    return false;
}


string express(char root, bool graph[][26]) {

    string left = "";
    string right = "";
    for (int i = 0; i < 26; i++) {
        if (graph[root - 'A'][i]) {
            left = express((char)('A' + i), graph);
            for (int j = i + 1; j < 26; j++) {
                    if (graph[root - 'A'][j]) {
                            right = express((char)('A' + j), graph);
                            break;
                    }
            }
            break;
        }
    }
    return "(" + root + left + right + ")";
}

string sExpression(string s) {
// cout << nodes << endl;
    bool graph[26][26];
    set<char> ss;
    bool E2 = false;
    int countE = 0;
    for (int i = 1; i < s.length(); i += 6) {
            int x = s[i] - 'A';
            int y = s[i + 2] - 'A';
            if (graph[x][y]) {
                    E2 = true;
            }
            graph[x][y] = true;
            ss.insert(s[i]);
            ss.insert(s[i + 2]);
            countE++;
    }
    bool E1 = false;
    for (int i = 0; i < 26; i++) {
            int count = 0;
            for (int j = 0; j < 26; j++) {
                    if (graph[i][j]) {
                            count++;
                    }
            }
            if (count > 2) {
                    return "E1";
            }
    }
    if (E2) 
        return "E2";
    int roots = 0;
    char root = ' ';
    // System.out.println(ss);
    for (char c : ss) {
        for (int i = 0; i < 26; i++) {
            if (graph[i][c - 'A']) {
                break;
            }
            if (i == 25) {
                roots++;
                root = c;
                bool visited[26];
                if (iscycle(c, graph, visited)) {
                        return "E3";
                }
            }
        }
    }
    if (roots == 0) return "E3";
    if (roots > 1) return "E4";
    return express(root, graph);
}

int main(){
string nodes;
getline(cin, nodes);
string result = sExpression(nodes);
cout << result << "\n";
return 0;
}
