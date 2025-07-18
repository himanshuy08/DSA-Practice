#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twosum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // Map to store number and its index
    vector<int> result; // Vector to store the result indices

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Calculate the complement
        if (num_map.find(complement) != num_map.end()) {
            // If complement exists in the map, we found a pair
            result.push_back(num_map[complement]);
            result.push_back(i);
            return result; // Return the indices of the two numbers
        }
        num_map[nums[i]] = i; // Store the index of the current number
    }
    
    return result; // Return empty if no pair found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twosum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices of the two numbers that add up to " << target << ": ";
        cout << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers add up to " << target << endl;
    }
    
    return 0;
}
