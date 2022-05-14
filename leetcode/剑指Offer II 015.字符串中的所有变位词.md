# 剑指 Offer II 015. 字符串中的所有变位词

给定两个字符串 `s` 和 `p`，找到 `s` 中所有 `p` 的 **变位词** 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

**变位词** 指字母相同，但排列不同的字符串。

示例 1:

```
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的变位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的变位词。
```

示例 2:

```
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的变位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的变位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的变位词。
```

提示:

-   `1 <= s.length, p.length <= 3 * 10^4`
-   `s` 和 `p` 仅包含小写字母

注意：本题与主站 438 题相同： https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/

## Solution

```javascript
const A_CODE = "a".charCodeAt(0);
/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function (s, p) {
    if (s.length < p.length) return [];

    let sCount = new Array(26).fill(0),
        pCount = new Array(26).fill(0);
    let ans = [];

    for (let i = 0; i < p.length; i++) {
        sCount[s.charCodeAt(i) - A_CODE]++;
        pCount[p.charCodeAt(i) - A_CODE]++;
    }
    if (sCount.toString() == pCount.toString()) ans.push(0);

    for (let i = 1; i < s.length; i++) {
        sCount[s.charCodeAt(i + p.length - 1) - A_CODE]++;
        sCount[s.charCodeAt(i - 1) - A_CODE]--;
        if (sCount.toString() == pCount.toString()) ans.push(i);
    }
    return ans;
};
```
