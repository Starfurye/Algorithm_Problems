# 剑指 Offer II 099. 最小路径之和

给定一个包含非负整数的 `m x n`  网格  `grid` ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

**说明：**一个机器人每次只能向下或者向右移动一步。

示例 1：

![](https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg)

```
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
```

示例 2：

```
输入：grid = [[1,2,3],[4,5,6]]
输出：12
```

提示：

-   `m == grid.length`
-   `n == grid[i].length`
-   `1 <= m, n <= 200`
-   `0 <= grid[i][j] <= 100`

注意：本题与主站 64  题相同： https://leetcode-cn.com/problems/minimum-path-sum/

## Solution

### 动态规划

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function (grid) {
    let dp = new Array(grid.length)
        .fill(0)
        .map(() => new Array(grid[0].length).fill(0));
    dp[0][0] = grid[0][0];
    for (let i = 1; i < grid.length; i++) dp[i][0] = grid[i][0] + dp[i - 1][0];
    for (let i = 1; i < grid[0].length; i++)
        dp[0][i] = grid[0][i] + dp[0][i - 1];
    for (let i = 1; i < grid.length; i++) {
        for (let j = 1; j < grid[0].length; j++) {
            dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[grid.length - 1][grid[0].length - 1];
};
```

滚动数组优化：

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function (grid) {
    let dp = new Array(grid[0].length).fill(0);
    dp[0] = grid[0][0];
    for (let i = 1; i < grid[0].length; i++) dp[i] = grid[0][i] + dp[i - 1];
    for (let i = 1; i < grid.length; i++) {
        dp[0] += grid[i][0];
        for (let j = 1; j < grid[0].length; j++) {
            dp[j] = Math.min(dp[j - 1], dp[j]) + grid[i][j];
        }
    }
    return dp[grid[0].length - 1];
};
```
