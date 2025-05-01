#include <iostream>
#include <map>

using namespace std;

bool divideArray(vector<int>& nums) {
    int sz = nums.size();
    map<int, int> m;
    for (int i = 0; i < sz; i++) {
        m[i]++;
    }
    for (auto pair : m) {
        cout << pair.first << " " << pair.second << endl;
    }
    return true;
}

int main() {
    vector<int> s = {3,2,3,2,2,2};
    cout << divideArray(s);
    return 0;
}