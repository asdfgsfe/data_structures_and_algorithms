int PreOrder(const BTreeNode* pRoot, 
             int sum, 
             int preSum, //由于不能是环形 所以这里不能是引用
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

//类似于 一段数组中求累加和等于sum的最长子数组 知道sum(0~i) 知道sum(0~j) 求sum(j~i) = sum(0~j) - sum(0~i)
int longestPathSum(const BTreeNode* pRoot, int sum)
{
  if (Root == nullptr)
  {
    return 0;
  }
  unordered_map<int, int> sumToLevels;
  return PreOrder(pRoot, sum, 0, 1, 0, sumToLevels);
}

//注释 看看就行
public class MaxPathLenOfSumEqualsGivenValue {

    private int maxLen=0;

    /*
     * sumMap:保存从head开始的一条路径上的累加和；
     *        key:保存某个累加和；
     *        value:在这个累加和在路径中《最早》出现的层数
     * 对于当前节点，需要父节点的累加和+当前节点的值（所以需要先序遍历的变形应用）
     * 保证level为最早出现这个累加和的层数：
     *     sumMap中加入某个累加和时，判断是否已经有该累加和，没有了加入；有不加入；
     *     
     *  求解以每个节点结尾的情况下，累加和为规定值的最长路径长度；
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

        if(!sumMap.containsKey(curSum)){  //保证level为最早出现这个累加和的层数
            sumMap.put(curSum, level);
        }

        //求解以每个节点结尾的情况下，累加和为规定值的最长路径长度，更新最大路径长度
        if(sumMap.containsKey(curSum-sum)){ 
            maxLen=Math.max(maxLen, level-sumMap.get(curSum-sum));
        }

        //遍历左右子树
        preSum=curSum;
        preOrder(head.left,sum,preSum,level+1,sumMap);
        preOrder(head.right,sum,preSum,level+1,sumMap);


        //返回之前，如果当前累加和是新加入的（通过level判断），则删除
        if(level==sumMap.get(curSum)){
            sumMap.remove(curSum);
        }

        return maxLen;
    }

}