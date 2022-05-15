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

```javascript
/**
 * @param {number[]} postorder
 * @return {boolean}
 */
var verifyPostorder = function (postorder) {
    const rec = (left, right) => {
        if (left >= right) return true;
        let p = left;
        while (postorder[p] < postorder[right]) p++; // 找左右子树的划分
        let m = p;
        while (postorder[p] > postorder[right]) p++;
        // p == right判断此树是否正确，如果p<right说明右子树右边还有元素，不正确
        return p == right && rec(left, m - 1) && rec(m, right - 1);
    };
    return rec(0, postorder.length - 1);
};
```
