# 剑指 Offer II 046. 二叉树的右侧视图

给定一个二叉树的 **根节点** `root`，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例 1:

![](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)

```
输入: [1,2,3,null,5,null,4]
输出: [1,3,4]
```

示例 2:

```
输入: [1,null,3]
输出: [1,3]
```

示例 3:

```
输入: []
输出: []
```

提示:

-   二叉树的节点个数的范围是 `[0,100]`
-   `-100 <= Node.val <= 100`

注意：本题与主站 199 题相同：https://leetcode-cn.com/problems/binary-tree-right-side-view/

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
 * @return {number[]}
 */
var rightSideView = function (root) {
    if (!root) return [];
    let q = [root];
    let ans = [];
    while (q.length) {
        let len = q.length;
        for (let i = 0; i < len; i++) {
            let top = q.shift();
            if (i == len - 1) ans.push(top.val);
            if (top.left) q.push(top.left);
            if (top.right) q.push(top.right);
        }
    }
    return ans;
};
```
