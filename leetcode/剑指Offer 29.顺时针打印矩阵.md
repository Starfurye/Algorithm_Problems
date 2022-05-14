# 剑指 Offer 29. 顺时针打印矩阵

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：

```
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
```

示例 2：

```
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
```

限制：

-   0 <= matrix.length <= 100
-   0 <= matrix[i].length <= 100

注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/

## Solution

```js
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function (matrix) {
    // leftBound, rightBound, upBound, downBound
    if (matrix.length == 0) return [];
    let elemNum = matrix.length * matrix[0].length;
    let lB = 0,
        rB = matrix[0].length - 1,
        uB = 0,
        dB = matrix.length - 1;
    let ans = [];
    while (lB <= rB && uB <= dB && ans.length < elemNum) {
        for (let col = lB; col <= rB; col++) {
            ans.push(matrix[uB][col]);
        }
        if (ans.length == elemNum) break;
        uB++;
        for (let row = uB; row <= dB; row++) {
            ans.push(matrix[row][rB]);
        }
        if (ans.length == elemNum) break;
        rB--;
        for (let col = rB; col >= lB; col--) {
            ans.push(matrix[dB][col]);
        }
        if (ans.length == elemNum) break;
        dB--;
        for (let row = dB; row >= uB; row--) {
            ans.push(matrix[row][lB]);
        }
        if (ans.length == elemNum) break;
        lB++;
    }
    return ans;
};
```
