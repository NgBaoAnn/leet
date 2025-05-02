#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string pushDominoes(string dominoes) {
    int n = dominoes.size();
    vector<int> count(n, 0);

    int f = 0;
    for (int i = 0; i < n; ++i) {
        if (dominoes[i] == 'R') {
            f = n;
        } else if (dominoes[i] == 'L') {
            f = 0;
        } else {
            f = max(f - 1, 0);
        }
        count[i] += f;
    }

    f = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (dominoes[i] == 'L') {
            f = n;
        } else if (dominoes[i] == 'R') {
            f = 0;
        } else {
            f = max(f - 1, 0);
        }
        count[i] -= f;
    }

    string res;
    for (int f : count) {
        if (f > 0) res += 'R';
        else if (f < 0) res += 'L';
        else res += '.';
    }

    return res;
}

int main() {
    string s = ".L.R...LR..L..";
    cout << pushDominoes(s) << endl;
    return 0;
}
