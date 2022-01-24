# 剑指 Offer II 016. 不含重复字符的最长子字符串

给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长连续子字符串** 的长度。

示例 1:

```
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子字符串是 "abc"，所以其长度为 3。
```

示例 2:

```
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子字符串是 "b"，所以其长度为 1。
```

示例 3:

```
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

示例 4:

```
输入: s = ""
输出: 0
```

提示：

-   `0 <= s.length <= 5 * 10^4`
-   `s` 由英文字母、数字、符号和空格组成

注意：本题与主站 3 题相同： https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

## Solution

### 滑动窗口

```js
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    if (s.length == 0) return 0;

    let map = new Map();
    let ans = 1;
    let left = 0,
        right = 1;
    map.set(s.charAt(0), 0);

    while (right < s.length) {
        if (map.has(s.charAt(right))) {
            let last = map.get(s.charAt(right));
            for (let i = left; i <= last; i++) {
                map.delete(s.charAt(i));
            }
            left = last + 1;
            map.set(s.charAt(right), right);
        } else {
            map.set(s.charAt(right), right);
            ans = Math.max(ans, right - left + 1);
        }
        right++;
    }
    return ans;
};
```
