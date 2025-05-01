#include <iostream>
#include <vector>

using namespace std;

int maximumCount(vector<int>& nums) {
    int n = nums.size();

    int l = 0, r = n - 1;
    int firstPositive = n; 
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] > 0) {
            firstPositive = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    l = 0, r = n - 1;
    int firstZero = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] >= 0) {
            firstZero = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    int countNegative = firstZero;           
    int countPositive = n - firstPositive; 

    return max(countNegative, countPositive);
}


int main() {
    vector<int> nums = {-4,-3,0,1,1,1,1,1,1,1,1,1,1,1,1};
    cout << maximumCount(nums) << endl;
    return 0;
}
