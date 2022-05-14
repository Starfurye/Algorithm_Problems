# 剑指 Offer 55 - I. 二叉树的深度

输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

例如：

给定二叉树 `[3,9,20,null,null,15,7]`,

```
  3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度 3 。

**提示：**

-   节点总数 <= 10000

注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

## Solution

### DFS

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function (root) {
    const dfs = (node, depth) => {
        if (!node.left && !node.right) {
            ans = Math.max(ans, depth);
            return;
        }
        node.left && dfs(node.left, depth + 1);
        node.right && dfs(node.right, depth + 1);
    };

    let ans = 1;
    if (root === null) return 0;
    dfs(root, 1);
    return ans;
};
```

### BFS

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function (root) {
    if (root === null) return 0;
    let ans = 0;
    let q = [root];
    while (q.length !== 0) {
        ans++;
        let len = q.length;
        for (let i = 0; i < len; i++) {
            let top = q.shift();
            top.left && q.push(top.left);
            top.right && q.push(top.right);
        }
    }
    return ans;
};
```
