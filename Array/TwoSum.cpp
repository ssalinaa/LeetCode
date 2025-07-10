#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> indices;
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        return { }; 
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;

    std::vector<int> result1 = solution.twoSum(nums1, target1);
    std::vector<int> result2 = solution.twoSum(nums2, target2);
    std::vector<int> result3 = solution.twoSum(nums3, target3);

    auto printResult = [](const std::vector<int>& result) {
        if(result.empty()) {
            std::cout << "Empty vector!" << std::endl;
        } else {
            std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
        }
    };

    std::cout << "Result1: ";
    printResult(result1);
    std::cout << std::endl;

    std::cout << "Result2: ";
    printResult(result2);
    std::cout << std::endl;

    std::cout << "Result3: ";
    printResult(result3);
    std::cout << std::endl;

    return 0;
}