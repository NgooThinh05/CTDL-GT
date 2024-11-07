
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int x = target - nums[i];
        if (map.find(x) != map.end()) {
            return {i, map[x]};
        }
        else {
            map.insert({nums[i], i});
        }
    }
    return {};
}
