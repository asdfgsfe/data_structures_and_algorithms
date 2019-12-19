class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) 
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> s(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0) 
                {
                    for(int u=0; u<=j; u++) s[i][j] += mat[i][u];
                }
                else 
                {
                    s[i][j] = s[i-1][j];
                    for(int u=0; u<=j; u++) s[i][j] += mat[i][u];
                }
            }
        }
		//dump s for debug
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++) cout<<s[i][j]<<" ";
            cout<<endl;
        }

		//二分答案的方法 答案范围固定 在[l, r]之间 然后确定二分的策略
        int l = 1;
		int r = min(n,m)+1;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(check(mat, mid, s) == threshold) 
			{
				l = mid+1;
			}
            else if(check(mat, mid, s) > threshold)
			{
				r = mid;
			}
            else if(check(mat, mid, s) < threshold)
			{
				l = mid+1;
			}
        }
        return l-1;
    }
    
    int check(vector<vector<int>> mat, int len, vector<vector<int>> s)
    {
        int n = mat.size();
        int m = mat[0].size();
		//统计边长为len的最小面积
        int _min = INT_MAX;
        for(int i=0; i<=n-len; i++)
        {
            for(int j=0; j<=m-len; j++)
            {
                int res = 0;
                res = s[i+len-1][j+len-1]; // i=1 j=1 len =1 s[1][1] - s[0][1] - s[1][0] + s[0][0]
                if(i!=0) res-=s[i-1][j+len-1];
                if(j!=0) res-=s[i+len-1][j-1];
                if(i!=0 && j!=0) res+=s[i-1][j-1];
                _min = min(_min, res);
            }
        }
        return _min;
    }
};