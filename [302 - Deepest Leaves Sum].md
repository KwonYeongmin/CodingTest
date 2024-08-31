```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
    int deepestLeavesSum(TreeNode* root) 
    {
       if (nullptr == root)
       {
            return 0;
       }

        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;

        while (!q.empty()) 
        {
            int levelSize = q.size();
            // 새로운 레벨이 시작될 때 sum을 초기화
            sum = 0;  

            for (int i = 0; i < levelSize; ++i) 
            {
                TreeNode* currentNode = q.front();
                q.pop();
                sum += currentNode->val;

                if (nullptr != currentNode->left)
                {
                    q.push(currentNode->left);
                }
                if (nullptr != currentNode->right)
                {
                    q.push(currentNode->right);
                }
            }
        }
        // 마지막 레벨의 합을 반환
        return sum;  
    }
};


```
