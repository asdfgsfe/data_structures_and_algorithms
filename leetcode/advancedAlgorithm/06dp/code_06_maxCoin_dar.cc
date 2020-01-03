 /**
    *   @Author Nyr
    *   @Date 2019/11/30 0:23
    *   @Param  nums:气球数组；length:数组长度，避免每层都计算一次；begin:开始下标；end:结束下标；cache:缓存，避免重复计算
    *   @Return 
    *   @Exception 
    *   @Description 状态转移方程 def( i, j ) = max { def( i , k ) + def( k , j )+nums[ i ][ j ][ k ] } | i<k<j 的实现
    */
    public static int maxCoins4(int[] nums, int length, int begin, int end,int[][] cache) {
        //回归条件，问题分解到最小子问题
        if (begin == end - 1) {
            return 0;
        }
        //缓存，避免重复计算
        if(cache[begin][end]!=0){
            return cache[begin][end];
        }
        //维护一个最大值
        int max = 0;
        //状态转移方程 def( i, j ) = max { def( i , k ) + def( k , j )+nums[ i ][ j ][ k ] } | i<k<j
        for (int i = begin + 1; i < end; i++) {
            int temp = maxCoins4(nums, length, begin, i,cache) +
                    maxCoins4(nums, length, i, end,cache) + nums[begin] * nums[i] * nums[end];
            if (temp > max) {
                max = temp;
            }
        }
        //缓存，避免重复计算
        cache[begin][end]=max;
        return max;
    }
 
我们再封装一层方法，对空数组进行处理。因为 def( i , j ) 并不戳破两个边界的气球，我们为气球数组加上虚拟的边界：
 
    public static final int maxCoins4MS(int[] nums) {
        //空数组处理
        if (nums == null) {
            return maxCoin;
        }
        //加虚拟边界
        int length = nums.length;
        int[] nums2=new int[length+2];
        System.arraycopy(nums,0,nums2,1,length);
        nums2[0]=1;
        nums2[length+1]=1;
        length=nums2.length;
        //创建缓存数组
        int[][] cache=new int[length][length];
        //调用分治函数
        return maxCoins4M(nums2, length,cache);
    }

    public static int maxCoins4M(int[] nums, int length,int[][] cache) {
        int max = maxCoins4(nums, length, 0, length - 1,cache);
        return max;
    }
 
实现很简单，一个带缓存的递归调用，我们来看一下效果，测试代码如下：
 
public static void main(String[] args) {
        int[] nums = {3,4,5,6,7,5,7,8,5,3,2,5};
        long start = System.currentTimeMillis();
        start = System.currentTimeMillis();
        System.out.println(maxCoins(nums));
        System.out.println("原始回溯用时   ：   " + 
        String.valueOf(System.currentTimeMillis() - start)+"  运算次 
        数："+sum3);
        start = System.currentTimeMillis();
        System.out.println(maxCoins4MS(nums));
        System.out.println("分治用时   ：   " + 
        String.valueOf(System.currentTimeMillis() - start)+"  运算次 
        数："+sum1+"  实际运算次数："+sum2);
    }


作者：niu-you-rou
链接：https://leetcode-cn.com/problems/burst-balloons/solution/chao-xiang-xi-hui-su-dao-fen-zhi-dao-dp-by-niu-you/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。