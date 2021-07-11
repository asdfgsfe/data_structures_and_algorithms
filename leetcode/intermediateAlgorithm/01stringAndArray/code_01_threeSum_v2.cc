//采用hash表的方法 超时 如果全部是0 这种方法就不行了
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        unordered_set<string> visited;
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                continue;
            }
            unordered_map<int, int> numIdxs;
            for (int j = i + 1; j < nums.size(); ++j) {
                auto it = numIdxs.find(-nums[i] - nums[j]);
                if (it != numIdxs.end()) {
                    vector<int> tmp{nums[i], nums[j], it->first};
                    std::sort(tmp.begin(), tmp.end());
                string v = std::to_string(tmp[0]) + "_" + std::to_string(tmp[1]) + "_" + std::to_string(tmp[2]);
                    if (!visited.count(v)) {
                        ret.emplace_back(tmp);
                        visited.emplace(std::move(v));
                    }
                }
                numIdxs[nums[j]] = j;
            }
        }
        return ret;
    }
};
