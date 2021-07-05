N 叉树的层序遍历
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。



作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/n-ary-tree/x0if1e/
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
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
        {
            return {};
        }
        queue<Node*> nodes;
        nodes.push(root);
        vector<vector<int>> levels;
        while (!nodes.empty())
        {
            int size = nodes.size();
            vector<int> values(size);
            int pos = 0;
            while (size--)
            {
                root = nodes.front();
                nodes.pop();
                values[pos++] = root->val;
                for (Node* node : root->children)
                {
                    if (node)
                    {
                        nodes.push(node);
                    }
                }
            }
            levels.emplace_back(std::move(values));
        }
        return levels;
    }
};
