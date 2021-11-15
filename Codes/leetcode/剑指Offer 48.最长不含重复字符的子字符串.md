# 剑指 Offer 48. 最长不含重复字符的子字符串

请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

 

**示例 1:**

```
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

**示例 2:**

```
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```

**示例 3:**

```
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

 

提示：

- `s.length <= 40000`

注意：本题与主站 3 题相同：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

## Solution

```js
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    const findPre = (cur, index) => {
        for (let j = index - 1; j >= 0; j--) {
            if (s.charAt(j) == cur) return j; 
        }
        return -1;
    };

    if (s.length == 0) return 0;

    // dp[i] 代表以字符 s[i] 为结尾的 “最长不重复子字符串” 的长度。
    let dp = new Array(s.length).fill(0);
    let ans = 1;
    dp[0] = 1;

    for (let i = 1; i < s.length; i++) {
        // 向左找第一个和当前相等的字符位置pre
        let pre = findPre(s.charAt(i), i);
        // 没有找到或者和当前位置差大于dp[i - 1]，表明dp[i - 1]的起始位置在pre前
        if (pre == -1 || i - pre > dp[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            // dp[i - 1]的起始位置在pre后
            dp[i] = i - pre;
        }
        ans = Math.max(ans, dp[i]);
    }
    return ans;
};
```

