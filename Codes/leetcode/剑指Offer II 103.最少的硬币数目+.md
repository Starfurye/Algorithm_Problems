# 剑指 Offer II 103. 最少的硬币数目

给定不同面额的硬币 `coins` 和一个总金额 `amount`。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 `-1`。

你可以认为每种硬币的数量是无限的。

示例  1：

```
输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1
```

示例 2：

```
输入：coins = [2], amount = 3
输出：-1
```

示例 3：

```
输入：coins = [1], amount = 0
输出：0
```

示例 4：

```
输入：coins = [1], amount = 1
输出：1
```

示例 5：

```
输入：coins = [1], amount = 2
输出：2
```

提示：

-   `1 <= coins.length <= 12`
-   `1 <= coins[i] <= 2^31 - 1`
-   `0 <= amount <= 10^4`

注意：本题与主站 322  题相同： https://leetcode-cn.com/problems/coin-change/

## Solution

### 动态规划

`dp[j]`: 凑足总额为`j`所需钱币的最少个数为`dp[j]`

```js
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function (coins, amount) {
    let dp = new Array(amount + 1).fill(Number.MAX_SAFE_INTEGER);
    dp[0] = 0;
    for (let i = 0; i < coins.length; i++) {
        for (let j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != Number.MAX_SAFE_INTEGER) {
                dp[j] = Math.min(dp[j - coins[i]] + 1, dp[j]);
            }
        }
    }
    if (dp[amount] === Number.MAX_SAFE_INTEGER) return -1;
    return dp[amount];
};
```
