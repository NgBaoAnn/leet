#include <iostream>
#include <vector>
using namespace std;
void findSubsets(std::vector<int>& nums, std::vector<int>& currentSubset, int index) {
    std::cout << "{ ";
    for (int num : currentSubset) {
        std::cout << num << " ";
    }
    std::cout << "}\n";

    for (int i = index; i < nums.size(); ++i) {
        currentSubset.push_back(nums[i]);
        findSubsets(nums, currentSubset, i + 1); 
        currentSubset.pop_back();
    }
}
   
int main() {
    std::vector<int> nums = {1, 2, 3}; 
    std::vector<int> currentSubset;
    findSubsets(nums, currentSubset, 0);
    return 0;
}
