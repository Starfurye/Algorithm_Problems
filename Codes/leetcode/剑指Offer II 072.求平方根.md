# 剑指 Offer II 072. 求平方根

给定一个非负整数 `x` ，计算并返回 `x` 的平方根，即实现 `int sqrt(int x)`函数。

正数的平方根有两个，只输出其中的正数平方根。

如果平方根不是整数，输出只保留整数的部分，小数部分将被舍去。

示例 1:

```
输入: x = 4
输出: 2
```

示例 2:

```
输入: x = 8
输出: 2
解释: 8 的平方根是 2.82842...，由于小数部分将被舍去，所以返回 2
```

提示:

`0 <= x <= 2^31 - 1`

注意：本题与主站 69 题相同：https://leetcode-cn.com/problems/sqrtx/

## Solution

### 二分法

```js
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function (x) {
    if (x <= 1) return x;
    let left = 0,
        right = Math.floor(x / 2);
    while (left <= right) {
        let mid = Math.floor((right - left) / 2 + left);
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid > x) {
            right = mid - 1;
        } else if (mid * mid < x) {
            left = mid + 1;
        }
    }
    return left - 1;
};
```
