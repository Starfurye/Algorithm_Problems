# 剑指 Offer 33. 二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 `true`，否则返回 `false`。假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：

```
     5
    / \
   2   6
  / \
 1   3
```

示例 1：

```
输入: [1,6,3,2,5]
输出: false
```

示例 2：

```
输入: [1,3,2,6,5]
输出: true
```

提示：

-   数组长度 <= 1000

## Solution

```js
/**
 * @param {number[]} postorder
 * @return {boolean}
 */
var verifyPostorder = function (postorder) {
    const rec = (i, j) => {
        if (i >= j) return true;
        let p = i;
        while (postorder[p] < postorder[j]) p++; // 找左子树
        let m = p;
        while (postorder[p] > postorder[j]) p++;
        // p == j判断此树是否正确，如果p<j说明右子树右边还有元素，不正确
        return p == j && rec(i, m - 1) && rec(m, j - 1);
    };
    return rec(0, postorder.length - 1);
};
```
