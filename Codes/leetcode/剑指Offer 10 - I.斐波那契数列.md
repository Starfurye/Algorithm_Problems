# 剑指 Offer 10- I. 斐波那契数列

写一个函数，输入 `n` ，求斐波那契（Fibonacci）数列的第 `n` 项（即 `F(N)`）。斐波那契数列的定义如下：

```
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
```

斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

**示例 1：**

```
输入：n = 2
输出：1
```

**示例 2：**

```
输入：n = 5
输出：5
```

**提示：**

-   `0 <= n <= 100`

## Solution

### 动态规划

#### v1

```js
/**
 * @param {number} n
 * @return {number}
 */
var fib = function (n) {
    if (n === 0) return 0;
    else if (n === 1) return 1;

    let front = 1,
        back = 0;
    for (let i = 2; i <= n; i++) {
        [back, front] = [front, back + front];
        front %= 1e9 + 7;
        back %= 1e9 + 7;
    }
    return front;
};
```

#### v2

```js
/**
 * @param {number} n
 * @return {number}
 */
var fib = function (n) {
    if (n == 0 || n == 1) return n;
    let pre = 0,
        cur = 1;
    for (let i = 2; i <= n; i++) {
        [pre, cur] = [cur, (pre + cur) % (1e9 + 7)];
    }
    return cur;
};
```

### 矩阵快速幂

![image-20210904111318734.png](https://i.loli.net/2021/09/04/sP7Sk5gahuvFOim.png)

```js
var fib = function (n) {
    if (n < 2) {
        return n;
    }
    const q = [
        [1, 1],
        [1, 0],
    ];
    const res = pow(q, n - 1);
    return res[0][0];
};

const pow = (a, n) => {
    let ret = [
        [1, 0],
        [0, 1],
    ];
    while (n > 0) {
        if ((n & 1) === 1) {
            ret = multiply(ret, a);
        }
        n >>= 1;
        a = multiply(a, a);
    }
    return ret;
};

const multiply = (a, b) => {
    const c = new Array(2).fill(0).map(() => new Array(2).fill(0));
    for (let i = 0; i < 2; i++) {
        for (let j = 0; j < 2; j++) {
            c[i][j] =
                (BigInt(a[i][0]) * BigInt(b[0][j]) +
                    BigInt(a[i][1]) * BigInt(b[1][j])) %
                BigInt(1000000007);
        }
    }
    return c;
};
```
