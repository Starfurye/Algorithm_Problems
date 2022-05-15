# 剑指 Offer II 044. 二叉树每层的最大值

给定一棵二叉树的根节点 `root` ，请找出该二叉树中每一层的最大值。

示例 1：

```
输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]
解释:
          1
         / \
        3   2
       / \   \
      5   3   9
```

示例 2：

```
输入: root = [1,2,3]
输出: [1,3]
解释:
          1
         / \
        2   3
```

示例 3：

```
输入: root = [1]
输出: [1]
```

示例 4：

```
输入: root = [1,null,2]
输出: [1,2]
解释:
           1
            \
             2
```

示例 5：

```
输入: root = []
输出: []
```

提示：

-   二叉树的节点个数的范围是 `[0,10^4]`
-   `-2^31 <= Node.val <= 2^31 - 1`

注意：本题与主站 515 题相同： https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/

## Solution

### BFS

```javascript
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
var largestValues = function (root) {
    if (!root) return [];
    let q = [root];
    let res = [];
    while (q.length) {
        let len = q.length;
        let maxNum = Number.MIN_SAFE_INTEGER;
        for (let i = 0; i < len; i++) {
            let top = q.shift();
            maxNum = Math.max(maxNum, top.val);
            if (top.left) q.push(top.left);
            if (top.right) q.push(top.right);
        }
        res.push(maxNum);
    }
    return res;
};
```
