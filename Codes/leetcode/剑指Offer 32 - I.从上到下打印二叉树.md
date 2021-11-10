# 剑指 Offer 32 - I. 从上到下打印二叉树

从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

 

例如:
给定二叉树: `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

返回：

```
[3,9,20,15,7]
```

 

**提示：**

1. `节点总数 <= 1000`

## Solution

### 层序遍历

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var levelOrder = function(root) {
    let res = [];
    if (!root) return res;

    const queue = [];
    queue.push(root);
    while (queue.length != 0) {
        let len = queue.length;         // 当层元素数量
        // res.push([]); 如果答案格式要求不同层放在不同括号内
        for (let i = 0; i < len; i++) {
            let cur = queue.shift();
            // res[res.length - 1].push(cur.val); 如果答案格式要求不同层放在不同括号内
            res.push(cur.val);
            if (cur.left) queue.push(cur.left);
            if (cur.right) queue.push(cur.right);
        }
    }
    
    return res;
};
```