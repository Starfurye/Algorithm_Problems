# 剑指 Offer II 014. 字符串中的变位词

给定两个字符串 `s1` 和 `s2`，写一个函数来判断 `s2` 是否包含 `s1` 的某个变位词。

换句话说，第一个字符串的排列之一是第二个字符串的 **子串** 。

示例 1：

```
输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
```

示例 2：

```
输入: s1= "ab" s2 = "eidboaoo"
输出: False
```

提示：

-   `1 <= s1.length, s2.length <= 10^4`
-   `s1` 和 `s2` 仅包含小写字母

注意：本题与主站 567 题相同： https://leetcode-cn.com/problems/permutation-in-string/

## Solution

```js
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function (s1, s2) {
    const n = s1.length,
        m = s2.length;
    if (n > m) {
        return false;
    }
    const cnt1 = new Array(26).fill(0);
    const cnt2 = new Array(26).fill(0);

    // 比较s2中长度为n的子串
    for (let i = 0; i < n; ++i) {
        ++cnt1[s1[i].charCodeAt() - "a".charCodeAt()];
        ++cnt2[s2[i].charCodeAt() - "a".charCodeAt()];
    }
    if (cnt1.toString() === cnt2.toString()) {
        return true;
    }
    for (let i = n; i < m; ++i) {
        ++cnt2[s2[i].charCodeAt() - "a".charCodeAt()];
        --cnt2[s2[i - n].charCodeAt() - "a".charCodeAt()];
        if (cnt1.toString() === cnt2.toString()) {
            return true;
        }
    }
    return false;
};
```
