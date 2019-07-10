int PreOrder(const BTreeNode* pRoot, 
             int sum, 
             int preSum, //���ڲ����ǻ��� �������ﲻ��������
             int level, 
             int& maxPath, 
             unordered_map<int, int>& sumToLevels)
{
  if (pRoot == nullptr)
  {
    return maxPath;
  }
  int curSum = preSum + pRoot->val;
  if (sumToLevels.find(curSum) == sumToLevels.end())
  {
    sumToLevels[curSum] = level;
  }
  if (sumToLevels.find(curSum - sum) != sumToLevels.end())
  {
    maxPath = std::max(maxPath, level - sumToLevel[curSum - sum]);
  }
  maxPath = PreOrder(pRoot->pLeft, sum, curSum, level + 1, maxPath, sumToLevels);
  maxPath = PreOrder(pRoot->pRight, sum, curSum, level + 1, maxPath, sumToLevels);
  if (sumToLevels[curSum] == level)
  {
    sumToLevels.erase(curSum);
  }
  return maxPath;
}

//������ һ�����������ۼӺ͵���sum��������� ֪��sum(0~i) ֪��sum(0~j) ��sum(j~i) = sum(0~j) - sum(0~i)
int longestPathSum(const BTreeNode* pRoot, int sum)
{
  if (Root == nullptr)
  {
    return 0;
  }
  unordered_map<int, int> sumToLevels;
  return PreOrder(pRoot, sum, 0, 1, 0, sumToLevels);
}

//ע�� ��������
public class MaxPathLenOfSumEqualsGivenValue {

    private int maxLen=0;

    /*
     * sumMap:�����head��ʼ��һ��·���ϵ��ۼӺͣ�
     *        key:����ĳ���ۼӺͣ�
     *        value:������ۼӺ���·���С����硷���ֵĲ���
     * ���ڵ�ǰ�ڵ㣬��Ҫ���ڵ���ۼӺ�+��ǰ�ڵ��ֵ��������Ҫ��������ı���Ӧ�ã�
     * ��֤levelΪ�����������ۼӺ͵Ĳ�����
     *     sumMap�м���ĳ���ۼӺ�ʱ���ж��Ƿ��Ѿ��и��ۼӺͣ�û���˼��룻�в����룻
     *     
     *  �����ÿ���ڵ��β������£��ۼӺ�Ϊ�涨ֵ���·�����ȣ�
     */
    public int getMaxLen(Node head,int sum){
        Map<Integer,Integer> sumMap=new HashMap<Integer,Integer>();
        sumMap.put(0, 0);
        return preOrder(head,sum,0,1,sumMap);       
    }

    private int preOrder(Node head, int sum, int preSum, int level,Map<Integer, Integer> sumMap) {
        if(head==null){
            return maxLen;
        }
        int curSum=preSum+head.value;

        if(!sumMap.containsKey(curSum)){  //��֤levelΪ�����������ۼӺ͵Ĳ���
            sumMap.put(curSum, level);
        }

        //�����ÿ���ڵ��β������£��ۼӺ�Ϊ�涨ֵ���·�����ȣ��������·������
        if(sumMap.containsKey(curSum-sum)){ 
            maxLen=Math.max(maxLen, level-sumMap.get(curSum-sum));
        }

        //������������
        preSum=curSum;
        preOrder(head.left,sum,preSum,level+1,sumMap);
        preOrder(head.right,sum,preSum,level+1,sumMap);


        //����֮ǰ�������ǰ�ۼӺ����¼���ģ�ͨ��level�жϣ�����ɾ��
        if(level==sumMap.get(curSum)){
            sumMap.remove(curSum);
        }

        return maxLen;
    }

}