# 剑指 Offer 46. 把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

**示例 1:**

```
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
```

**提示：**

-   `0 <= num < 2^31`

## Solution

### 动态规划

```js
/**
 * @param {number} num
 * @return {number}
 */
var translateNum = function (num) {
    const checkTwo = (index) => {
        // 判断从index开始的两位数能否翻译成字符串
        if (arr[index] === "0") return false;
        let num = +(arr[index] + arr[index + 1]);
        return num <= 25 && num >= 10;
    };

    if (num < 10) return 1;
    let arr = ("" + num).split("");
    let dp = new Array(arr.length).fill(0);
    [dp[0], dp[1]] = [1, checkTwo(0) ? 2 : 1];

    // 当前位直接转换的种数 + 当前和前一位合并转换的种数
    // dp[i] = dp[i - 1] + (twoNumIsLetter(i - 1) ? dp[i - 2] : 0)
    for (let i = 2; i < arr.length; i++) {
        dp[i] = dp[i - 1] + (checkTwo(i - 1) ? dp[i - 2] : 0);
    }
    return dp[arr.length - 1];
};
```

使用两个额外空间：

```js
/**
 * @param {number} num
 * @return {number}
 */
var translateNum = function (num) {
    const checkTwo = (index) => {
        if (arr[index] === "0") return false;
        let num = +(arr[index] + arr[index + 1]);
        return num <= 25 && num >= 10;
    };

    if (num < 10) return 1;
    let arr = ("" + num).split("");
    let pre = 1,
        cur = checkTwo(0) ? 2 : 1;
    for (let i = 2; i < arr.length; i++) {
        [pre, cur] = [cur, cur + (checkTwo(i - 1) ? pre : 0)];
    }
    return cur;
};
```
