# 剑指 Offer 27. 二叉树的镜像

请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

```
	4
	/  \
	2   7
	/ \  / \
	1  3 6  9
```

镜像输出：

```
   4
   /  \
   7   2
   / \  / \
   9  6 3  1
```

**示例 1：**

```
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```

**限制：**

```
0 <= 节点个数 <= 1000
```

注意：本题与主站 226 题相同：https://leetcode-cn.com/problems/invert-binary-tree/

## Solution

### DFS-递归

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
 * @return {TreeNode}
 */
var mirrorTree = function (root) {
    if (!root) return null;
    [root.left, root.right] = [root.right, root.left];
    mirrorTree(root.left);
    mirrorTree(root.right);
    return root;
};
```

### BFS

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
 * @return {TreeNode}
 */
var mirrorTree = function (root) {
    if (!root) return root;
    let queue = [root];
    while (queue.length != 0) {
        const cur = queue.shift();
        [cur.left, cur.right] = [cur.right, cur.left];
        if (cur.left) queue.push(cur.left);
        if (cur.right) queue.push(cur.right);
    }
    return root;
};
```
