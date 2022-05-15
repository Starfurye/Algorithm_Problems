# 剑指 Offer 07. 重建二叉树

输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

**示例 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```

**示例 2:**

```
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```

**限制：**

```
0 <= 节点个数 <= 5000
```

注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function (preorder, inorder) {
    const build = (preorder, preBegin, preEnd, inorder, inBegin, inEnd) => {
        if (preBegin == preEnd) return null;

        // 先序的第一个元素为根结点元素
        let rootValue = preorder[preBegin];
        let root = new TreeNode(rootValue);
        if (preEnd - preBegin == 1) return root;

        // 找先序第一个元素在中序数组中的位置作为分割点
        let delim = inorder.indexOf(rootValue);

        root.left = build(
            preorder,
            preBegin + 1,
            preBegin + 1 + (delim - inBegin),
            inorder,
            inBegin,
            delim
        );

        root.right = build(
            preorder,
            preBegin + 1 + (delim - inBegin),
            preEnd,
            inorder,
            delim + 1,
            inEnd
        );
        return root;
    };

    if (preorder.length == 0 || inorder.length == 0) return null;
    return build(preorder, 0, preorder.length, inorder, 0, inorder.length); // 左闭右开
};
```
