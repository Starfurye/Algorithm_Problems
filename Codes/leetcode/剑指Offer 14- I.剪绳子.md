# 剑指 Offer 14- I. 剪绳子

给你一根长度为 `n` 的绳子，请把绳子剪成整数长度的 `m` 段（`m`、`n`都是整数，`n>1`并且`m>1`），每段绳子的长度记为 `k[0],k[1]...k[m-1]` 。请问 `k[0]*k[1]*...*k[m-1]` 可能的最大乘积是多少？例如，当绳子的长度是`8`时，我们把它剪成长度分别为`2、3、3`的三段，此时得到的最大乘积是`18`。

示例 1：

```
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
```

示例  2:

```
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
```

提示：

-   `2 <= n <= 58`

注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/

## Solution

```js
/**
 * @param {number} n
 * @return {number}
 */
var cuttingRope = function (n) {
    let ans = 0;
    for (let i = 2; i <= n; i++) {
        let len = Math.floor(n / i);
        let add = n % i;
        ans = Math.max(ans, Math.pow(len, i - add) * Math.pow(len + 1, add));
    }

    return ans;
};
```

实际上可由解最值问题证得每段长度为 3 时乘积最大。
