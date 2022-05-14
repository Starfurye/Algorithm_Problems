# LC-0050. Pow(x, n)

Implement [pow(x, n)](http://www.cplusplus.com/reference/valarray/pow/), which calculates `x` raised to the power `n` (i.e., `xn`).

**Example 1:**

```
Input: x = 2.00000, n = 10
Output: 1024.00000
```

**Example 2:**

```
Input: x = 2.10000, n = 3
Output: 9.26100
```

**Example 3:**

```
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```

**Constraints:**

-   `-100.0 < x < 100.0`
-   `-2^31 <= n <= 2^31-1`
-   `-10^4 <= xn <= 10^4`

## Solution

### 快速幂

计算$x^n$时，可以递归地计算$y=x^{\lfloor\frac{n}{2}\rfloor}$，根据结果，如果$n$为偶数则$x^{n}=y^{2}$，如果$n$为奇数，则$x^{n}=y^{2}\times x$。递归边界$n=0$。

```javascript
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function (x, n) {
    return n >= 0 ? quickMul(x, n) : 1.0 / quickMul(x, -n);
};
const quickMul = (x, N) => {
    if (N === 0) return 1.0;
    let y = quickMul(x, Math.floor(N / 2));
    return N % 2 === 0 ? y * y : y * y * x;
};
```

### 快速幂+迭代

如果$n$可以拆分为：

$$
n = 2^{i_{0}} + 2^{i_{1}} + ... + 2^{i_{k}}
$$

则：

$$
x^{n} = x^{2^{i_{0}}} \times x^{2^{i_{1}}} \times ... \times x^{2^{i_{k}}}
$$

如果$n$的第$k$个二进制位为 1，就将$x^{2^{i_{0}}}$计入。

```javascript
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function (x, n) {
    return n >= 0 ? quickMul(x, n) : 1.0 / quickMul(x, -n);
};
const quickMul = (x, N) => {
    let ans = 1.0;
    let x_contri = x;
    while (N > 0) {
        if (N % 2 === 1) {
            ans *= x_contri;
        }
        x_contri *= x_contri;
        N >>= 1;
    }
    return ans;
};
```

_该方法通不过样例`myPow(2.00000, -2147483648)`。_
