# 剑指 Offer II 001. 整数除法

给定两个整数 `a` 和 `b` ，求它们的除法的商 `a/b` ，要求不得使用乘号 `'*'`、除号 `'/'` 以及求余符号 `'%'`。

注意：

-   整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
-   假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31, 2^31−1]。本题中，如果除法结果溢出，则返回 2^31 − 1

示例 1：

```
输入：a = 15, b = 2
输出：7
解释：15/2 = truncate(7.5) = 7
```

示例 2：

```
输入：a = 7, b = -3
输出：-2
解释：7/-3 = truncate(-2.33333..) = -2
```

示例 3：

```
输入：a = 0, b = 1
输出：0
```

示例 4：

```
输入：a = 1, b = 1
输出：1
```

提示:

-   `-2^31 <= a, b <= 2^31 - 1`
-   b != 0

-   注意：本题与主站 29 题相同：https://leetcode-cn.com/problems/divide-two-integers/

## Solution

```js
/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var divide = function (a, b) {
    if (!a) return 0;
    const [MIN, MAX] = [-(2 ** 31), 2 ** 31 - 1];
    if (a == MIN && b == -1) return MAX;
    if (a == MIN && b == 1) return MIN;

    // 异或判断结果是否为负数
    const isNeg = (a ^ b) < 0;
    [a, b] = [Math.abs(a), Math.abs(b)];
    let res = 0;
    for (let i = 31; i >= 0; i--) {
        // 找出满足条件的最大的倍数
        if (a >>> i >= b) {
            // 累加上这个倍数
            res += 1 << i;
            // 被除数减去这个倍数*b
            a -= b << i;
        }
    }

    return isNeg ? -res : res;
};
```
