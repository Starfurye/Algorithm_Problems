# 剑指 Offer II 045. 二叉树最底层最左边的值

给定一个二叉树的 根节点 `root`，请找出该二叉树的 **最底层 最左边** 节点的值。

假设二叉树中至少有一个节点。

示例 1:

![](https://assets.leetcode.com/uploads/2020/12/14/tree1.jpg)

```
输入: root = [2,1,3]
输出: 1
```

示例 2:

![](https://assets.leetcode.com/uploads/2020/12/14/tree2.jpg)

```
输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
```

提示:

-   二叉树的节点个数的范围是 `[1,10^4]`
-   `-2^31 <= Node.val <= 2^31 - 1`

注意：本题与主站 513 题相同： https://leetcode-cn.com/problems/find-bottom-left-tree-value/

## Solution

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
var findBottomLeftValue = function (root) {
    let q = [root];
    let ans = []; // 记录最后一层的所有叶子结点的值
    while (q.length) {
        let len = q.length;
        ans = [];
        for (let i = 0; i < len; i++) {
            let top = q.shift();
            ans.push(top.val);
            if (top.left) q.push(top.left);
            if (top.right) q.push(top.right);
        }
    }
    return ans[0];
};
```
