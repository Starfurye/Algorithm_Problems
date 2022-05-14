# 剑指 Offer 10- II. 青蛙跳台阶问题

一只青蛙一次可以跳上 1 级台阶，也可以跳上 2 级台阶。求该青蛙跳上一个 `n` 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

**示例 1：**

```
输入：n = 2
输出：2
```

**示例 2：**

```
输入：n = 7
输出：21
```

**示例 3：**

```
输入：n = 0
输出：1
```

**提示：**

-   `0 <= n <= 100`

注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/climbing-stairs/，区别在求0级时本题答案为1。

## Solution

### 动态规划

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numWays = function (n) {
    if (n == 0 || n == 1) return 1;

    let dp = new Array(n + 1).fill(0);
    dp[0] = dp[1] = 1;
    dp[2] = 2;

    for (let i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % (1e9 + 7);
    }
    return dp[n];
};
```

使用两个空间：

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numWays = function (n) {
    if (n == 0 || n == 1) return 1;
    else if (n == 2) return 2;
    let pre = 1,
        cur = 2; // 上一层和两层
    for (let i = 3; i <= n; i++) {
        [pre, cur] = [cur, (pre + cur) % (1e9 + 7)];
    }
    return cur;
};
```
