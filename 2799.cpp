#include <iostream>
#include <map>
#include <set>

using namespace std;

int countCompleteSubarrays(vector<int>& nums) {
    int res = 0;
    int sz = nums.size();

    unordered_map<int, int> m1;
    for (int i = 0; i < sz; i++)
        m1[nums[i]]++;
    int cnt = m1.size();
    cout << "cnt: " << cnt << endl;


    int l = 0;
    while (sz - l + 1 >= cnt) {
        int r = sz - 1;
        while (r - l + 1 >= cnt) {
            unordered_map<int, int> m;
            for (int i = l; i <= r; i++) {
                m[nums[i]]++;
            }
            if (m.size() == cnt) res++;
            r--;
        }
        l++;
    }
    return res;
}

int main() {
    vector<int> nums = {5,5,5,5};
    cout << "res: " << countCompleteSubarrays(nums) << endl;
    return 0;
}