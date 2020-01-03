class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if (s.empty())
        {
            return {string()};
        }
        unordered_set<string> expressions;
        int lRem = 0;
        int rRem = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                ++lRem;
            }
            else if (s[i] == ')')
            {
                rRem = lRem == 0 ? rRem + 1 : rRem;
                lRem = lRem > 0 ? lRem - 1 : lRem;
            }
        }
        string exp;
        RemoveProcess(s, 0, 0, 0, lRem, rRem, exp, expressions);
        return vector<string>(expressions.begin(), expressions.end());
    }
    
    void RemoveProcess(const string& s, 
                       int i, 
                       int lCount, 
                       int rCount,
                       int lRem,
                       int rRem,
                       string& exp,
                       unordered_set<string>& expressions)
    {
        if (i == s.size())
        {
            if (lRem == 0 && rRem == 0)
            {
                expressions.emplace(exp);
            }
            return;
        }
        if ((s[i] == '(' && lRem > 0) || (s[i] == ')' && rRem > 0))
        {
            RemoveProcess(s,
                          i + 1,
                          lCount,
                          rCount, s[i] == '(' ? lRem - 1 : lRem,
                          s[i] == ')' ? rRem - 1 : rRem,
                          exp,
                          expressions);
        }
        exp.push_back(s[i]);
        if (s[i] != '(' && s[i] != ')')
        {
            RemoveProcess(s, i + 1, lCount, rCount, lRem, rRem, exp, expressions);
        }
        else if (s[i] == '(')
        {
            RemoveProcess(s, i + 1, lCount + 1, rCount, lRem, rRem, exp, expressions);
        }
        else
        {
            if (lCount > rCount)
            {
                RemoveProcess(s, i + 1, lCount, rCount + 1, lRem, rRem, exp, expressions);
            }
        }
        exp.pop_back();
    }
};


//暴力方法
class Solution {

  private Set<String> validExpressions = new HashSet<String>();
  private int minimumRemoved;

  private void reset() {
    this.validExpressions.clear();
    this.minimumRemoved = Integer.MAX_VALUE;
  }

  private void recurse(
      String s,
      int index,
      int leftCount,
      int rightCount,
      StringBuilder expression,
      int removedCount) {

    // If we have reached the end of string.
    if (index == s.length()) {

      // If the current expression is valid.
      if (leftCount == rightCount) {

        // If the current count of removed parentheses is <= the current minimum count
        if (removedCount <= this.minimumRemoved) {

          // Convert StringBuilder to a String. This is an expensive operation.
          // So we only perform this when needed.
          String possibleAnswer = expression.toString();

          // If the current count beats the overall minimum we have till now
          if (removedCount < this.minimumRemoved) {
            this.validExpressions.clear();
            this.minimumRemoved = removedCount;
          }
          this.validExpressions.add(possibleAnswer);
        }
      }
    } else {

      char currentCharacter = s.charAt(index);
      int length = expression.length();

      // If the current character is neither an opening bracket nor a closing one,
      // simply recurse further by adding it to the expression StringBuilder
      if (currentCharacter != '(' && currentCharacter != ')') {
        expression.append(currentCharacter);
        this.recurse(s, index + 1, leftCount, rightCount, expression, removedCount);
        expression.deleteCharAt(length);
      } else {

        // Recursion where we delete the current character and move forward
        this.recurse(s, index + 1, leftCount, rightCount, expression, removedCount + 1);
        expression.append(currentCharacter);

        // If it's an opening parenthesis, consider it and recurse
        if (currentCharacter == '(') {
          this.recurse(s, index + 1, leftCount + 1, rightCount, expression, removedCount);
        } else if (rightCount < leftCount) {
          // For a closing parenthesis, only recurse if right < left
          this.recurse(s, index + 1, leftCount, rightCount + 1, expression, removedCount);
        }

        // Undoing the append operation for other recursions.
        expression.deleteCharAt(length);
      }
    }
  }

  public List<String> removeInvalidParentheses(String s) {

    this.reset();
    this.recurse(s, 0, 0, 0, new StringBuilder(), 0);
    return new ArrayList(this.validExpressions);
  }
}


作者：LeetCode
链接：https://leetcode-cn.com/problems/remove-invalid-parentheses/solution/shan-chu-wu-xiao-de-gua-hao-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。