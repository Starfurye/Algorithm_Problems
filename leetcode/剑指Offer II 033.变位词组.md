# 剑指 Offer II 033. 变位词组

给定一个字符串数组 `strs` ，将 **变位词** 组合在一起。 可以按任意顺序返回结果列表。

**注意：**若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。

示例 1:

```
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

示例 2:

```
输入: strs = [""]
输出: [[""]]
```

示例 3:

```
输入: strs = ["a"]
输出: [["a"]]
```

提示：

-   `1 <= strs.length <= 10^4`
-   `0 <= strs[i].length <= 100`
-   `strs[i]` 仅包含小写字母

注意：本题与主站 49 题相同： https://leetcode-cn.com/problems/group-anagrams/

## Solution

### 哈希表

排序后的串作为键：

```javascript
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
    let map = new Map();
    for (let str of strs) {
        let sorted = str.split("").sort().join("");
        let arr = map.get(sorted) ? map.get(sorted) : [];
        arr.push(str);
        map.set(sorted, arr);
    }
    return Array.from(map.values()); // from用法
};
```

按字母计数的结果作为键：

```javascript
var groupAnagrams = function (strs) {
    const map = new Object();
    for (let s of strs) {
        const count = new Array(26).fill(0);
        for (let c of s) {
            count[c.charCodeAt() - "a".charCodeAt()]++;
        }
        // 数组作为键
        map[count] ? map[count].push(s) : (map[count] = [s]);
    }
    return Object.values(map);
};
```
