# 剑指 Offer 46. 把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

**示例 1:**

```
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
```

 

**提示：**

- `0 <= num < 2^31`

## Solution

### 动态规划✔

```js
/**
 * @param {number} num
 * @return {number}
 */
var translateNum = function(num) {
    if (num < 10) return 1;

    const len = (num + "").length;
    const getNum = (i, j) => {  // [i, j]
        let temp = num + "";
        return parseInt(temp.substring(i, j + 1));
    };

    let dp = new Array(len).fill(0);
    let temp = getNum(0, 1);
    dp[0] = 1;
    dp[1] = 1 + (temp <= 25 ? 1 : 0);

    // dp[i] = dp[i - 1] + ((dp[i - 2] + 1) : 0)
    for (let i = 2; i < len; i++) {
        temp = getNum(i - 1, i);
        // 当前位直接转换的种数 + 当前和前一位合并转换的种数（前一位不能为0）
        dp[i] = dp[i - 1] + (temp <= 25 && getNum(i - 1, i - 1) != 0 ? dp[i - 2] : 0);
    }
    return dp[len - 1];
};
```

#### v2

```js
/**
 * @param {number} num
 * @return {number}
 */
var translateNum = function(num) {
    if (num < 10) return 1;

    const len = (num + "").length;
    const getNum = (i, j) => {  // [i, j]
        let temp = num + "";
        return parseInt(temp.substring(i, j + 1));
    };

    let temp = getNum(0, 1);
    let pre2 = 1, pre = 1 + (temp <= 25 ? 1 : 0), cur = pre;

    // dp[i] = max{dp[i - 1] + 1, (dp[i - 2] + 1) : 0}
    for (let i = 2; i < len; i++) {
        temp = getNum(i - 1, i);
        cur = pre + (temp <= 25 && getNum(i - 1, i - 1) != 0 ? pre2 : 0);
        pre2 = pre;
        pre = cur;
    }
    return cur;
};
```

