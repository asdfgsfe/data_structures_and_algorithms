class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty() || k < 0 || k > nums.size()) {
            return {};
        }
        unordered_map<int, int> numTimes;
        for (int n : nums) {
            ++numTimes[n];
        }
        vector<pair<int,int>> topk;
        for (auto& tmp : numTimes) {
            if (topk.size() < k) {
                topk.emplace_back(std::move(tmp));
                HeapInsert(topk, topk.size() - 1);
                continue;
            }
            if (tmp.second > topk[0].second) {
                topk[0] = tmp;
                Heapify(topk, 0, k);
            }
        }
        vector<int> ret;
        for (auto& pair : topk) {
            ret.push_back(pair.first);
        }
        return ret;
    }

    void HeapInsert(vector<pair<int, int>>& topk, int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (topk[i].second >= topk[p].second) {
                break;
            }
            std::swap(topk[i], topk[p]);
            i = p;
        }
    }

    void Heapify(vector<pair<int, int>>& topk, int i, int n) {
        int child = 2 * i + 1;
        while (child < n) {
            if (child + 1 != n && topk[child + 1].second < topk[child].second) {
                ++child;
            }
            if (topk[i].second >= topk[child].second) {
                return;
            }
            std::swap(topk[i], topk[child]);
            i = child;
            child = 2 * i + 1;
        }
    }
};
