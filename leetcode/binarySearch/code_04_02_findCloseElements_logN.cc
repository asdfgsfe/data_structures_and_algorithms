class Solution {
public:
	//���ֲ��ҵı��ʾ���̰���㷨
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0;
        int right=arr.size()-k; //��ֹmid+k���
		//�ƶ��Ĳ���λ����k���ȵ�����
		//ʼ�ձ������䳤��Ϊk
        while(right>left){
            int mid=(right+left)/2;
            if(abs(x-arr[mid])>abs(x-arr[mid+k])){//�����ߵ�Ҫ��һ������󻬣�����ұߵĽ������һ�
                left=mid+1;//���һ�
            }else{
                right=mid;//����
            }
            
        }
        return vector<int>(arr.begin()+left,arr.begin()+left+k);
    }
};
