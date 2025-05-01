#include <iostream>
#include <vector>

using namespace std;
bool canPartition(vector<int>& nums) {
    int suma = 0, sumb = 0;
    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 0; i < nums.size(); i++) {
        if (suma <= sumb) 
            suma += nums[i];
        else 
            sumb += nums[i];
    }
    if (suma == sumb) return true;
    else return false;
}
int main() {
    vector<int> nums = {1,5,11,5};
    cout << canPartition(nums);
    return 0;

}