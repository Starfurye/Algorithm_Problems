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
    const twoNumIsLetter = (index) => {
        // 判断从index开始的两位数能否翻译成字符串
        let thisNum =
            parseInt(numArr.charAt(index)) * 10 +
            parseInt(numArr.charAt(index + 1));
        if (thisNum <= 25 && thisNum >= 10) {
            return true;
        } else return false;
    };

    if (num < 10) return 1;
    let numArr = "" + num;
    let dp = new Array(numArr.length).fill(0);
    dp[0] = 1;
    dp[1] = twoNumIsLetter(0) ? 2 : 1;

    // 当前位直接转换的种数 + 当前和前一位合并转换的种数
    // dp[i] = dp[i - 1] + (twoNumIsLetter(i - 1) ? dp[i - 2] : 0)
    for (let i = 2; i < numArr.length; i++) {
        dp[i] = dp[i - 1] + (twoNumIsLetter(i - 1) ? dp[i - 2] : 0);
    }
    return dp[numArr.length - 1];
};
```

使用两个额外空间：

```js
/**
 * @param {number} num
 * @return {number}
 */
var translateNum = function (num) {
    const twoNumIsLetter = (index) => {
        let thisNum =
            parseInt(numArr.charAt(index)) * 10 +
            parseInt(numArr.charAt(index + 1));
        if (thisNum <= 25 && thisNum >= 10) {
            return true;
        } else return false;
    };

    if (num < 10) return 1;
    let numArr = "" + num;
    let pre = 1,
        cur = twoNumIsLetter(0) ? 2 : 1;
    for (let i = 2; i < numArr.length; i++) {
        [pre, cur] = [cur, cur + (twoNumIsLetter(i - 1) ? pre : 0)];
    }
    return cur;
};
```
