# 剑指 Offer 54. 二叉搜索树的第 k 大节点

给定一棵二叉搜索树，请找出其中第 k 大的节点。

**示例 1:**

```
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
```

**示例 2:**

```
输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
```

**限制：**

-   `1 ≤ k ≤ 二叉搜索树元素个数`

## Solution

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthLargest = function (root, k) {
    const dfs = (cur) => {
        // 右中左
        if (!cur) return;
        dfs(cur.right);

        count++;
        if (count == k) {
            ans = cur.val;
            return;
        }

        dfs(cur.left);
    };

    if (!root) return null;
    let count = 0,
        ans = null;
    dfs(root);
    return ans;
};
```
