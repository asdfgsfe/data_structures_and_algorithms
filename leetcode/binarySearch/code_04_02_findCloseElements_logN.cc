class Solution {
public:
	//二分查找的本质就是贪心算法
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0;
        int right=arr.size()-k; //防止mid+k溢出
		//移动的步骤位整个k长度的区间
		//始终保持区间长度为k
        while(right>left){
            int mid=(right+left)/2;
            if(abs(x-arr[mid])>abs(x-arr[mid+k])){//如果左边的要近一点就向左滑，如果右边的近就向右划
                left=mid+1;//向右划
            }else{
                right=mid;//向左划
            }
            
        }
        return vector<int>(arr.begin()+left,arr.begin()+left+k);
    }
};
