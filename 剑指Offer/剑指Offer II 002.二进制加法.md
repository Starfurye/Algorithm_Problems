# 剑指 Offer II 002. 二进制加法

给定两个 01 字符串`a`和`b`，请计算它们的和，并以二进制字符串的形式输出。

输入为 非空 字符串且只包含数字`1`和`0`。

示例 1:

```
输入: a = "11", b = "10"
输出: "101"
```

示例 2:

```
输入: a = "1010", b = "1011"
输出: "10101"
```

提示：

-   每个字符串仅由字符 `'0'` 或 `'1'` 组成。
-   `1 <= a.length, b.length <= 10^4`
-   字符串如果不是 `"0"` ，就都不含前导零。

注意：本题与主站 67 题相同：https://leetcode-cn.com/problems/add-binary/

## Solution

```javascript
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function (a, b) {
    let ans = [];
    let carry = 0,
        i = 0;
    for (; i < Math.min(a.length, b.length); i++) {
        let sum =
            carry +
            parseInt(a.charAt(a.length - 1 - i)) +
            parseInt(b.charAt(b.length - 1 - i));
        ans.unshift(sum % 2);
        carry = Math.floor(sum / 2);
    }
    while (i < a.length) {
        let sum = carry + parseInt(a.charAt(a.length - 1 - i));
        i++;
        ans.unshift(sum % 2);
        carry = Math.floor(sum / 2);
    }
    while (i < b.length) {
        let sum = carry + parseInt(b.charAt(b.length - 1 - i));
        i++;
        ans.unshift(sum % 2);
        carry = Math.floor(sum / 2);
    }
    return carry === 0 ? ans.join("") : "1" + ans.join("");
};
```

```python
class Solution:
    def addBinary(self, a, b) -> str:
        x, y = int(a, 2), int(b, 2)
        while y:
            answer = x ^ y
            carry = (x & y) << 1
            x, y = answer, carry
        return bin(x)[2:]
```
