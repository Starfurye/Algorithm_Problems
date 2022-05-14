# 剑指 Offer 66. 构建乘积数组

给定一个数组 `A[0,1,…,n-1]`，请构建一个数组 `B[0,1,…,n-1]`，其中 `B[i]` 的值是数组 `A` 中除了下标 `i` 以外的元素的积, 即 `B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]`。**不能使用除法**。

示例:

```
输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
```

提示：

-   所有元素乘积之和不会溢出 32 位整数
-   `a.length <= 100000`

## Solution

计算矩阵即可：![](https://pic.leetcode-cn.com/1624619180-vpyyqh-Picture1.png)

```js
/**
 * @param {number[]} a
 * @return {number[]}
 */
var constructArr = function (a) {
    let b = new Array(a.length).fill(1);
    let temp = 1;

    for (let i = 0; i < a.length; i++) b[i] = b[i - 1] * a[i - 1]; // 向下计算下三角
    for (let i = a.length - 2; i >= 0; i--) {
        temp *= a[i + 1]; // 向上计算上三角
        b[i] *= temp; // 同时计算答案
    }

    return b;
};
```
