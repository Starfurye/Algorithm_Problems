# 剑指 Offer 50. 第一个只出现一次的字符

在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

**示例 1:**

```
输入：s = "abaccdeff"
输出：'b'
```

**示例 2:**

```
输入：s = "" 
输出：' '
```

**限制：**

```
0 <= s 的长度 <= 50000
```

## Solution

### 哈希表

```js
/**
 * @param {string} s
 * @return {character}
 */
var firstUniqChar = function(s) {
    // js中的map以插入的顺序返回键值
    const map = new Map();
    for (let i = 0; i < s.length; i++) {
        let c = s.charAt(i);
        if (!map.has(c)) {
            map.set(c, false);
        } else {
            map.set(c, true);
        }
    }

    for (let [key, value] of map.entries()) {
        if (value == false) return key;
    }
    return ' ';
};
```

