//My solution is different and does not use LIS
//For each column we have a choice whether to delete it or not .

//My dp state is -:

//dp[i][0] ->  子序列的思想 要当前位置
//denotes the minimum deletions required for columns 0 to i such that we do not delete the ith column

//dp[i][1]-> 不要当前位置
//denotes that minimum deletions required for columns 0 to i such that we delete the ith column

class Solution {
public:
    
    int minDeletionSize(vector<string>& a) {
        vector < vector <int> > dp(a[0].size(),vector <int> (2,100000000));
        dp[0][0]=0;
        dp[0][1]=1;
        for(int i=1;i<a[0].size();i++){
            dp[i][1]=1+min(dp[i-1][0],dp[i-1][1]);
            dp[i][0]=i; //强要这么一列 因为如果他小于前面的一个字符 他的最长长度就是i为止了
            for(int j=0;j<i;j++){ //从0到i判断要了当前字符 能不能是删除变得更加少
                bool flag=true;
                for(int k=0;k<a.size();k++){ //判断实际能否要这
                    if(a[k][j]>a[k][i]){
                        flag=false;
                        break;
                    }
                }
				//到这个地方位ture表示从0~j之间的字符全部小于i位置的字符 也就是dp[j][0]
				//而j~i之间还有i-j+1个字符待验证，目前就假设全部要删除它们 总共删除操作i-j-1+dp[j][0]
				//由于每次都要验证j~i之间的字符取最小值 所以这个假设不影响最终结果
                if(flag) 
                    dp[i][0]=min(dp[i][0],i-j-1+dp[j][0]);
            }
        }
        return min(dp.back()[0],dp.back()[1]);
    }
};
I find this approach more intuitive than LIS.