# LC-0028. Implement strStr()

Implement [strStr()](http://www.cplusplus.com/reference/cstring/strstr/).

Return the index of the first occurrence of needle in haystack, or `-1` if `needle` is not part of `haystack`.

**Clarification:**

What should we return when `needle` is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when `needle` is an empty string. This is consistent to C's [strstr()](http://www.cplusplus.com/reference/cstring/strstr/) and Java's [indexOf()](<https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)>).

**Example 1:**

```
Input: haystack = "hello", needle = "ll"
Output: 2
```

**Example 2:**

```
Input: haystack = "aaaaa", needle = "bba"
Output: -1
```

**Example 3:**

```
Input: haystack = "", needle = ""
Output: 0
```

**Constraints:**

-   `0 <= haystack.length, needle.length <= 5 * 10^4`
-   `haystack` and `needle` consist of only lower-case English characters.

## Solution

### Sunday 算法

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
    if (needle.length === 0) {
        return 0;
    }

    const shift = {};
    const patternLen = needle.length;
    for (let i = 0; i < patternLen; i++) {
        // 建立shift表，如果字母多次存在，后一次会覆盖前一次的位置
        shift[needle[i]] = i;
    }

    let j = 0;
    // 指针在模式串中的位置为j，指针在待匹配串中的位置为i+j
    for (let i = 0; i < haystack.length; ) {
        if (haystack[i + j] === needle[j]) {
            if (j === patternLen - 1) return i;
            else j++;
        } else if (haystack[i + j] !== needle[j]) {
            let index = shift[haystack[i + patternLen]]; // i+len为待匹配串中后一个位置
            if (index === undefined) {
                // 后一个位置的字母在模式串中不存在
                i += patternLen + 1;
            } else {
                i += patternLen - index;
            }
            j = 0;
        }
    }
    return -1;
};
```

### 库函数

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
    return haystack.indexOf(needle);
};
```
