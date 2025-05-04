#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    for (int can = 1; can <= 6; can++) {
        int resTop = 0, resBot = 0;
        bool ok = true;
        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] != can && bottoms[i] != can) {
                ok = false;
                break;
            }
            if (tops[i] != can) resTop++;
            if (bottoms[i] != can) resBot++;

        }
        if (ok)
            return min(resTop, resBot);
    }
    return -1;
}

int main() {

    vector<int> tops = {2,1,2,4,2,2}, bottoms = {5,2,6,2,3,2};
    cout << minDominoRotations(tops, bottoms);
    return 0;
}