# 剑指 Offer II 013. 二维子矩阵的和

给定一个二维矩阵 `matrix`，以下类型的多个请求：

-   计算其子矩形范围内元素的总和，该子矩阵的左上角为 `(row1, col1)` ，右下角为 `(row2, col2)` 。

实现 `NumMatrix` 类：

-   `NumMatrix(int[][] matrix)` 给定整数矩阵 `matrix` 进行初始化
-   `int sumRegion(int row1, int col1, int row2, int col2)` 返回左上角 `(row1, col1)` 、右下角 `(row2, col2)` 的子矩阵的元素总和。

示例 1：

![](https://pic.leetcode-cn.com/1626332422-wUpUHT-image.png)

```
输入:
["NumMatrix","sumRegion","sumRegion","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
输出:
[null, 8, 11, 12]

解释:
NumMatrix numMatrix = new NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)
```

提示：

-   `m == matrix.length`
-   `n == matrix[i].length`
-   `1 <= m, n <= 200`
-   `-10^5 <= matrix[i][j] <= 10^5`
-   `0 <= row1 <= row2 < m`
-   `0 <= col1 <= col2 < n`
-   最多调用 `10^4` 次 `sumRegion` 方法

注意：本题与主站 304 题相同：https://leetcode-cn.com/problems/range-sum-query-2d-immutable/

## Solution

```js
/**
 * @param {number[][]} matrix
 */
var NumMatrix = function (matrix) {
    this.preSum = new Array(matrix.length)
        .fill(0)
        .map(() => new Array(matrix[0].length).fill(0));
    this.preSum[0][0] = matrix[0][0];
    for (let i = 1; i < matrix[0].length; i++)
        this.preSum[0][i] = this.preSum[0][i - 1] + matrix[0][i];
    for (let i = 1; i < matrix.length; i++)
        this.preSum[i][0] = this.preSum[i - 1][0] + matrix[i][0];

    for (let i = 1; i < matrix.length; i++) {
        for (let j = 1; j < matrix[0].length; j++) {
            this.preSum[i][j] =
                this.preSum[i - 1][j] +
                this.preSum[i][j - 1] -
                this.preSum[i - 1][j - 1] +
                matrix[i][j];
        }
    }
};

/**
 * @param {number} row1
 * @param {number} col1
 * @param {number} row2
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function (row1, col1, row2, col2) {
    // 处理第一行和第一列的情况
    let left = col1 == 0 ? 0 : this.preSum[row2][col1 - 1];
    let up = row1 == 0 ? 0 : this.preSum[row1 - 1][col2];
    let leftUp = 0;
    if (col1 == 0 || row1 == 0) leftUp = 0;
    else leftUp = this.preSum[row1 - 1][col1 - 1];
    return this.preSum[row2][col2] - left - up + leftUp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
```
