class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return {};
        }
        vector<vector<int>> answer;
        unordered_set<string> visited;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int twoSum = nums[i] + nums[j];
                unordered_map<int, int> sumToIds;
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    auto id = sumToIds.find(target - twoSum - nums[k]);
                    if (id != sumToIds.end())
                    {
                        vector<int> ids{nums[i], nums[j], nums[k], nums[id->second]};
                        std::sort(ids.begin(), ids.end());
                        string key = to_string(ids[0]) + to_string(ids[1]) + to_string(ids[2]) + to_string(ids[3]);
                        if (!visited.count(key))
                        {
                            answer.emplace_back(std::move(ids));
                            visited.emplace(std::move(key));
                        }
                    }
                    sumToIds[nums[k]] = k;
                }
            }
        }
        return answer;
    }
};