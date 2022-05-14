# 剑指 Offer 16. 数值的整数次方

实现 `pow(x, n)` ，即计算 x 的 n 次幂函数（即，$x^{n}$）。不得使用库函数，同时不需要考虑大数问题。

示例 1：

```
输入：x = 2.00000, n = 10
输出：1024.00000
```

示例 2：

```
输入：x = 2.10000, n = 3
输出：9.26100
```

示例 3：

```
输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
```

提示：

-   `-100.0 < x < 100.0`
-   `-2^31 <= n <= 2^31-1`
-   `-10^4 <= x^n <= 10^4`

注意：本题与主站 50 题相同：https://leetcode-cn.com/problems/powx-n/

## Solution

### 快速幂迭代

如果$n$可以拆分为：

$$
n = 2^{i_{0}} + 2^{i_{1}} + ... + 2^{i_{k}}
$$

则：

$$
x^{n} = x^{2^{i_{0}}} \times x^{2^{i_{1}}} \times ... \times x^{2^{i_{k}}}
$$

如果$n$的第$k$个二进制位为 1，就将$x^{2^{i_{0}}}$计入。

```js
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function (x, n) {
    const quickMul = (m) => {
        let ans = 1.0;
        let x_contri = x;
        while (m > 0) {
            if (m & (1 == 1)) {
                ans *= x_contri;
            }
            x_contri *= x_contri;
            m >>= 1;
        }
        return ans;
    };
    return n >= 0 ? quickMul(n) : 1.0 / quickMul(-n);
};
```

_该方法通不过样例`myPow(2.00000, -2147483648)`。_

### 暴力优化

由一般的每次都乘`x`，改为指数逼近。

```js
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function (x, n) {
    const pow = (k) => {
        let i = 2,
            res = x;
        while (i <= k) {
            res *= res;
            i *= 2;
        }
        for (let j = i / 2; j < k; j++) {
            res *= x;
        }
        return res;
    };

    if (n == 0) {
        return 1;
    } else if (n > 0) return pow(n);
    else return 1 / pow(-n);
};
```
