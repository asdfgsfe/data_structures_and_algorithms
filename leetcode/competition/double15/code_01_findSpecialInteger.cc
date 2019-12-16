class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if (arr.empty())
        {
            return 0x7fffffff;
        }
        int times = arr.size() / 4;
        int p = 0;
        int n = 0;
        while (n < arr.size())
        {
            if (arr[n] == arr[p])
            {
                ++n;
            }
            else
            {
                if (n - p > times)
                {
                    return arr[p];
                }
                p = n;
            }
        }
        return arr[p];
    }
};