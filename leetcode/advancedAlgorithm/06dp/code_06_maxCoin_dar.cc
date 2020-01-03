 /**
    *   @Author Nyr
    *   @Date 2019/11/30 0:23
    *   @Param  nums:�������飻length:���鳤�ȣ�����ÿ�㶼����һ�Σ�begin:��ʼ�±ꣻend:�����±ꣻcache:���棬�����ظ�����
    *   @Return 
    *   @Exception 
    *   @Description ״̬ת�Ʒ��� def( i, j ) = max { def( i , k ) + def( k , j )+nums[ i ][ j ][ k ] } | i<k<j ��ʵ��
    */
    public static int maxCoins4(int[] nums, int length, int begin, int end,int[][] cache) {
        //�ع�����������ֽ⵽��С������
        if (begin == end - 1) {
            return 0;
        }
        //���棬�����ظ�����
        if(cache[begin][end]!=0){
            return cache[begin][end];
        }
        //ά��һ�����ֵ
        int max = 0;
        //״̬ת�Ʒ��� def( i, j ) = max { def( i , k ) + def( k , j )+nums[ i ][ j ][ k ] } | i<k<j
        for (int i = begin + 1; i < end; i++) {
            int temp = maxCoins4(nums, length, begin, i,cache) +
                    maxCoins4(nums, length, i, end,cache) + nums[begin] * nums[i] * nums[end];
            if (temp > max) {
                max = temp;
            }
        }
        //���棬�����ظ�����
        cache[begin][end]=max;
        return max;
    }
 
�����ٷ�װһ�㷽�����Կ�������д�����Ϊ def( i , j ) �������������߽����������Ϊ���������������ı߽磺
 
    public static final int maxCoins4MS(int[] nums) {
        //�����鴦��
        if (nums == null) {
            return maxCoin;
        }
        //������߽�
        int length = nums.length;
        int[] nums2=new int[length+2];
        System.arraycopy(nums,0,nums2,1,length);
        nums2[0]=1;
        nums2[length+1]=1;
        length=nums2.length;
        //������������
        int[][] cache=new int[length][length];
        //���÷��κ���
        return maxCoins4M(nums2, length,cache);
    }

    public static int maxCoins4M(int[] nums, int length,int[][] cache) {
        int max = maxCoins4(nums, length, 0, length - 1,cache);
        return max;
    }
 
ʵ�ֺܼ򵥣�һ��������ĵݹ���ã���������һ��Ч�������Դ������£�
 
public static void main(String[] args) {
        int[] nums = {3,4,5,6,7,5,7,8,5,3,2,5};
        long start = System.currentTimeMillis();
        start = System.currentTimeMillis();
        System.out.println(maxCoins(nums));
        System.out.println("ԭʼ������ʱ   ��   " + 
        String.valueOf(System.currentTimeMillis() - start)+"  ����� 
        ����"+sum3);
        start = System.currentTimeMillis();
        System.out.println(maxCoins4MS(nums));
        System.out.println("������ʱ   ��   " + 
        String.valueOf(System.currentTimeMillis() - start)+"  ����� 
        ����"+sum1+"  ʵ�����������"+sum2);
    }


���ߣ�niu-you-rou
���ӣ�https://leetcode-cn.com/problems/burst-balloons/solution/chao-xiang-xi-hui-su-dao-fen-zhi-dao-dp-by-niu-you/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������