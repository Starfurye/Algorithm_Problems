# 剑指 Offer 32 - III. 从上到下打印二叉树 III

请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

例如:
给定二叉树: `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

返回其层次遍历结果：

```
[
  [3],
  [20,9],
  [15,7]
]
```

**提示：**

1. `节点总数 <= 1000`

## Solution

和前两题一样，但要在奇数层（层数从 0 开始）反转。

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
 * @return {number[][]}
 */
var levelOrder = function (root) {
    if (!root) return [];
    let q = [root];
    let ans = [];
    let count = 0; // 控制反转
    while (q.length != 0) {
        let len = q.length;
        ans.push([]);
        for (let i = 0; i < len; i++) {
            let cur = q.shift();
            ans[ans.length - 1].push(cur.val); // 和剑指 Offer 32 - I. 从上到下打印二叉树的不同
            if (cur.left) q.push(cur.left);
            if (cur.right) q.push(cur.right);
        }
        if (count & (1 == 1)) ans[ans.length - 1].reverse();
        count++;
    }
    return ans;
};
```
