# 剑指 Offer II 032. 有效的变位词

给定两个字符串 `s` 和 `t` ，编写一个函数来判断它们是不是一组变位词（字母异位词）。

**注意：** 若 `s` 和 `t` 中每个字符出现的次数都相同且**字符顺序不完全相同**，则称 `s` 和 `t` 互为变位词（字母异位词）。

示例 1:

```
输入: s = "anagram", t = "nagaram"
输出: true
```

示例 2:

```
输入: s = "rat", t = "car"
输出: false
```

示例 3:

```
输入: s = "a", t = "a"
输出: false
```

提示:

-   `1 <= s.length, t.length <= 5 * 10^4`
-   `s` and `t` 仅包含小写字母

**进阶:** 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

注意：本题与主站 242 题相似（字母异位词定义不同）：https://leetcode-cn.com/problems/valid-anagram/

## Solution

### 哈希表

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s == t) return false;
    let map = new Map();
    for (let i = 0; i < s.length; i++)
        map.set(s.charAt(i), (map.get(s.charAt(i)) || 0) + 1);
    for (let i = 0; i < t.length; i++) {
        let temp = map.get(t.charAt(i));
        if (temp == undefined) {
            return false;
        } else if (temp > 0) {
            if (temp == 1) map.delete(t.charAt(i));
            else map.set(t.charAt(i), temp - 1);
        }
    }
    return map.size == 0;
};
```
