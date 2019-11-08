class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
       dfs(0,n,nums);
        return arr;
    }
    
    
    void dfs(int i,int n,vector<int> &nums)
    {
        arr.push_back(tmp);
        if(i == n)
        {
            return;
        } 
        for(int j = i;j < n;j++)
        {
            tmp.push_back(nums[j]);
            dfs(j+1,n,nums);
            tmp.pop_back();
        }
    }
private:
    vector<vector<int>> arr;
    vector<int> tmp;
};