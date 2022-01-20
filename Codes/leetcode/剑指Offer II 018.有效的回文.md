# 剑指 Offer II 018. 有效的回文

给定一个字符串 `s` ，验证 `s` 是否是 **回文串** ，只考虑字母和数字字符，可以忽略字母的大小写。

本题中，将空字符串定义为有效的 **回文串** 。

示例 1:

```
输入: s = "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串
```

示例 2:

```
输入: s = "race a car"
输出: false
解释："raceacar" 不是回文串
```

提示：

-   `1 <= s.length <= 2 * 10^5`
-   字符串 `s` 由 ASCII 字符组成

注意：本题与主站 125 题相同： https://leetcode-cn.com/problems/valid-palindrome/

## Solution

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
    let arr = [];
    for (let i = 0; i < s.length; i++) {
        if (/[a-zA-Z0-9]/.test(s.charAt(i)))
            arr.push(s.charAt(i).toLowerCase());
    }
    for (let i = 0; i < Math.floor(arr.length / 2); i++) {
        if (arr[i] != arr[arr.length - 1 - i]) return false;
    }
    return true;
};
```

### 库函数

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
    let newS = s.trim();
    if (newS == "") return true;
    let arrStr = newS
        .split("")
        .filter((ele) => /[a-zA-Z0-9]/.test(ele))
        .join("")
        .toLowerCase();
    let arr = arrStr.split("");
    return arr.reverse().join("") == arrStr;
};
```
