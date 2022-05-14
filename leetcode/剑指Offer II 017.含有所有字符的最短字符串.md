# 剑指 Offer II 017. 含有所有字符的最短字符串

给定两个字符串 `s` 和 `t` 。返回 `s` 中包含 `t` 的所有字符的最短子字符串。如果 `s` 中不存在符合条件的子字符串，则返回空字符串 `""` 。

如果 `s` 中存在多个符合条件的子字符串，返回任意一个。

**注意：** 对于 `t` 中重复字符，我们寻找的子字符串中该字符数量必须不少于 `t` 中该字符数量。

示例 1：

```
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最短子字符串 "BANC" 包含了字符串 t 的所有字符 'A'、'B'、'C'
```

示例 2：

```
输入：s = "a", t = "a"
输出："a"
```

示例 3：

```
输入：s = "a", t = "aa"
输出：""
解释：t 中两个字符 'a' 均应包含在 s 的子串中，因此没有符合条件的子字符串，返回空字符串。
```

**提示：**

-   `1 <= s.length, t.length <= 10^5`
-   `s` 和 `t` 由英文字母组成

**进阶：** 你能设计一个在 `o(n)` 时间内解决此问题的算法吗？

注意：本题与主站 76 题相似（本题答案不唯一）：https://leetcode-cn.com/problems/minimum-window-substring/

## Solution

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function (s, t) {
    let map = new Map();
    for (let i = 0; i < t.length; i++) {
        map.set(t.charAt(i), (map.get(t.charAt(i)) || 0) + 1);
    }
    let needCount = t.length;

    let res = [0, Number.MAX_SAFE_INTEGER];
    let left = 0;
    for (let right = 0; right < s.length; right++) {
        let c = s.charAt(right);
        if (map.get(c) > 0) needCount--;
        map.set(c, (map.get(c) || 0) - 1);
        if (needCount == 0) {
            while (true) {
                c = s.charAt(left);
                if (map.get(c) == 0) break; //碰到必要元素
                map.set(c, (map.get(c) || 0) + 1);
                left++;
            }
            if (right - left < res[1] - res[0]) {
                res = [left, right];
            }
            map.set(s.charAt(left), (map.get(s.charAt(left)) || 0) + 1);
            needCount++;
            left++;
        }
    }

    // 若res[1]没更新过则不满足条件
    return res[1] > s.length ? "" : s.slice(res[0], res[1] + 1);
};
```
