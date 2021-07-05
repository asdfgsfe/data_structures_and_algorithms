N 叉树的后序遍历
给定一个 N 叉树，返回其节点值的 后序遍历 。

N 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

 

进阶：

递归法很简单，你可以使用迭代法完成此题吗?

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/n-ary-tree/x0i5yi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
	vector<int> postorder(Node* root) {
		if (!root)
		{
			return {};
		}
		vector<int> values;
		stack<Node*> nodes;
		nodes.push(root);
		unordered_set<Node*> visited;
		while (!nodes.empty())
		{
			root = nodes.top();
			//std::cout << "nodes.size=" << nodes.size() << " val=" << root->val << std::endl;
			bool pop = true;
			for (Node* node : root->children)
			{
				if (node && !visited.count(node))
				{
					nodes.push(node);
					pop = false;
					break;
				}
			}
			if (pop)
			{
				nodes.pop();
				//std::cout << " pop: " << root->val << std::endl;
				values.emplace_back(root->val);
				visited.emplace(root);
			}
		}
		return values;
	}
};
