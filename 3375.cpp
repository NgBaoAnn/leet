#include <iostream>
#include <set>

using namespace std;

int minOperations(vector<int>& nums, int k) {
    set<int> distinct(nums.begin(), nums.end());
    if (k < *distinct.begin()) return distinct.size();
    if (k == *distinct.begin()) return distinct.size() - 1;
    return -1;
}

int main() {
    vector<int> nums = {5,2,5,4,5};
    int k = 2;
    cout << minOperations(nums, k) << endl;
}