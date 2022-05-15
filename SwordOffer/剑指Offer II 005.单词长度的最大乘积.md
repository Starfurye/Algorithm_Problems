# 剑指 Offer II 005. 单词长度的最大乘积

给定一个字符串数组 `words`，请计算当两个字符串 `words[i]` 和 `words[j]` 不包含相同字符时，它们长度的乘积的最大值。假设字符串中只包含英语的小写字母。如果没有不包含相同字符的一对字符串，返回 0。

示例 1:

```
输入: words = ["abcw","baz","foo","bar","fxyz","abcdef"]
输出: 16
解释: 这两个单词为 "abcw", "fxyz"。它们不包含相同字符，且长度的乘积最大。
```

示例 2:

```
输入: words = ["a","ab","abc","d","cd","bcd","abcd"]
输出: 4
解释: 这两个单词为 "ab", "cd"。
```

示例 3:

```
输入: words = ["a","aa","aaa","aaaa"]
输出: 0
解释: 不存在这样的两个单词。
```

提示：

-   `2 <= words.length <= 1000`
-   `1 <= words[i].length <= 1000`
-   `words[i]` 仅包含小写字母

注意：本题与主站 318 题相同：https://leetcode-cn.com/problems/maximum-product-of-word-lengths/

## Solution

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var maxProduct = function (words) {
    const trans = (word) => {
        let temp = 0;
        for (let i = 0; i < word.length; i++) {
            // 'a' to 'z' 低到高
            temp |= 1 << (word.charCodeAt(i) - "a".charCodeAt(0));
        }
        return temp;
    };

    let ans = 0;
    let letters = new Array(words.length).fill(0);
    for (let i = 0; i < letters.length; i++) {
        letters[i] = trans(words[i]);
        for (let j = 0; j < i; j++) {
            // 优先级注意
            if ((letters[i] & letters[j]) == 0) {
                ans = Math.max(ans, words[i].length * words[j].length);
            }
        }
    }

    return ans;
};
```
