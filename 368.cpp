#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int m = 0;
    int pos = 0;
    int n = nums.size();
    
    
    cout << m << " " << pos << endl;
    vector<int> res;
    for (int i = pos; i < n; i++) {
        if (nums[i] % m == 0) res.push_back(nums[i]);
    }
    return res;
}

int subsetXORSum(vector<int>& nums) {
    int sum = 0;
    
    for (int x : nums) {
        sum += x;
    } 
        
    int n = nums.size();

}
int main() {
    cout << (5 ^ 1 ^ 6) << endl;
    return 0;

}