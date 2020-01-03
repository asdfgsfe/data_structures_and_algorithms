/**
    *   @Author Nyr
    *   @Date 2019/11/30 22:24
    *   @Param nums:气球数组，
               y：递归层级，即currentLevel,
               length：数组长度，防止每层都计算一次， 
               beforeCoins：之前所有层获得的金币和，即currentCoin
    *   @Return 
    *   @Exception 
    *   @Description  回溯解法 
    */
    public static void maxCoins2(int[] nums, int y, int length, int beforeCoins) {
        //回归条件
        if (y == length) {
            if (beforeCoins > maxCoin) {
                maxCoin = beforeCoins;
            }
            return;
        }
        for (int i = 0; i < length; i++) {
            //略过已经戳破的气球
            if (nums[i] == -1) {
                continue;
            }
            //标记已经戳破的气球
            int temp = nums[i];
            nums[i] = -1;
            //获取上一个气球的数字
            int before = i - 1;
            int beforeNum = 0;
            while (before > -1 && nums[before] == -1) {
                before--;
            }
            if (before < 0) {
                beforeNum = 1;
            } else {
                beforeNum = nums[before];
            }
            //获取下一个气球的数字
            int next = i + 1;
            int nextNum = 0;
            while (next < length && nums[next] == -1) {
                next++;
            }
            if (next > length - 1) {
                nextNum = 1;
            } else {
                nextNum = nums[next];
            }
            //计算戳破当前气球的coin
            int tempCoin = temp * nextNum * beforeNum;
            //递归进行下一戳
            maxCoins2(nums, y + 1, length, beforeCoins + 
            tempCoin);
            //回溯尝试其它戳法
            nums[i] = temp;
        }
    }


//标记位已经处理的过程值得学习
//链接：https://leetcode-cn.com/problems/burst-balloons/solution/chao-xiang-xi-hui-su-dao-fen-zhi-dao-dp-by-niu-you/
