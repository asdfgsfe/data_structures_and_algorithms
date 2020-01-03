/**
    *   @Author Nyr
    *   @Date 2019/11/30 22:24
    *   @Param nums:�������飬
               y���ݹ�㼶����currentLevel,
               length�����鳤�ȣ���ֹÿ�㶼����һ�Σ� 
               beforeCoins��֮ǰ���в��õĽ�Һͣ���currentCoin
    *   @Return 
    *   @Exception 
    *   @Description  ���ݽⷨ 
    */
    public static void maxCoins2(int[] nums, int y, int length, int beforeCoins) {
        //�ع�����
        if (y == length) {
            if (beforeCoins > maxCoin) {
                maxCoin = beforeCoins;
            }
            return;
        }
        for (int i = 0; i < length; i++) {
            //�Թ��Ѿ����Ƶ�����
            if (nums[i] == -1) {
                continue;
            }
            //����Ѿ����Ƶ�����
            int temp = nums[i];
            nums[i] = -1;
            //��ȡ��һ�����������
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
            //��ȡ��һ�����������
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
            //������Ƶ�ǰ�����coin
            int tempCoin = temp * nextNum * beforeNum;
            //�ݹ������һ��
            maxCoins2(nums, y + 1, length, beforeCoins + 
            tempCoin);
            //���ݳ�����������
            nums[i] = temp;
        }
    }


//���λ�Ѿ�����Ĺ���ֵ��ѧϰ
//���ӣ�https://leetcode-cn.com/problems/burst-balloons/solution/chao-xiang-xi-hui-su-dao-fen-zhi-dao-dp-by-niu-you/
