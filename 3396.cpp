#include <iostream>
#include <set>
#include <vector>
#include <set>
#include <map>
using namespace std;
int minimumOperations(vector<int>& nums) {
    int cntOp = 0;
    int n = nums.size();
    for (int i = 0; i < n; i += 3) {
        bool check = true;
        unordered_map<int, int> map;
        for (int j = i; j < n; j++) {
            map[nums[j]]++;
        }
        for (auto [_,count] : map) {
            if (count > 1) {
                check = false;
                break;
            }
                
        }
        if (!check) cntOp++;
        else break;
    }
    return cntOp;
}
int main() {

}