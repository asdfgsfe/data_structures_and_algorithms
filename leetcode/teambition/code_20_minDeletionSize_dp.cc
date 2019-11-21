//My solution is different and does not use LIS
//For each column we have a choice whether to delete it or not .

//My dp state is -:

//dp[i][0] ->  �����е�˼�� Ҫ��ǰλ��
//denotes the minimum deletions required for columns 0 to i such that we do not delete the ith column

//dp[i][1]-> ��Ҫ��ǰλ��
//denotes that minimum deletions required for columns 0 to i such that we delete the ith column

class Solution {
public:
    
    int minDeletionSize(vector<string>& a) {
        vector < vector <int> > dp(a[0].size(),vector <int> (2,100000000));
        dp[0][0]=0;
        dp[0][1]=1;
        for(int i=1;i<a[0].size();i++){
            dp[i][1]=1+min(dp[i-1][0],dp[i-1][1]);
            dp[i][0]=i; //ǿҪ��ôһ�� ��Ϊ�����С��ǰ���һ���ַ� ��������Ⱦ���iΪֹ��
            for(int j=0;j<i;j++){ //��0��i�ж�Ҫ�˵�ǰ�ַ� �ܲ�����ɾ����ø�����
                bool flag=true;
                for(int k=0;k<a.size();k++){ //�ж�ʵ���ܷ�Ҫ��
                    if(a[k][j]>a[k][i]){
                        flag=false;
                        break;
                    }
                }
				//������ط�λture��ʾ��0~j֮����ַ�ȫ��С��iλ�õ��ַ� Ҳ����dp[j][0]
				//��j~i֮�仹��i-j+1���ַ�����֤��Ŀǰ�ͼ���ȫ��Ҫɾ������ �ܹ�ɾ������i-j-1+dp[j][0]
				//����ÿ�ζ�Ҫ��֤j~i֮����ַ�ȡ��Сֵ ����������費Ӱ�����ս��
                if(flag) 
                    dp[i][0]=min(dp[i][0],i-j-1+dp[j][0]);
            }
        }
        return min(dp.back()[0],dp.back()[1]);
    }
};
I find this approach more intuitive than LIS.