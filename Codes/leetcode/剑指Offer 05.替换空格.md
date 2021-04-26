# 剑指 Offer 05. 替换空格

请实现一个函数，把字符串 `s` 中的每个空格替换成"%20"。

**示例 1：**

```
输入：s = "We are happy."
输出："We%20are%20happy."
```

**限制：**

```
0 <= s 的长度 <= 10000
```

## Solution

```js
var replaceSpace = function(s) {
    s = s.split('');					// 注意String不会自动扩展
    let spaceCount = 0;
    for (let c of s) {
        if (c === ' ') spaceCount++;
    }

    let left = s.length - 1;
    s.length += 2 * spaceCount;
    let right = s.length - 1;
    while (left >= 0) {
        if (s[left] === ' ') {
            s[right--] = '0';
            s[right--] = '2';
            s[right--] = '%'; 
        } else {
            s[right--] = s[left];
        }
        left--;
    }
    return s.join('');
};
```

