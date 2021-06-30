# 168. Excel Sheet Column Title

Given an integer `columnNumber`, return *its corresponding column title as it appears in an Excel sheet*.

For example:

```
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
```

**Example 1:**

```
Input: columnNumber = 1
Output: "A"
```

**Example 2:**

```
Input: columnNumber = 28
Output: "AB"
```

**Example 3:**

```
Input: columnNumber = 701
Output: "ZY"
```

**Example 4:**

```
Input: columnNumber = 2147483647
Output: "FXSHRXW"
```

 

**Constraints:**

- `1 <= columnNumber <= 2^31 - 1`

## Solution

```js
/**
 * @param {number} columnNumber
 * @return {string}
 */
var convertToTitle = function(columnNumber) {
    let ans = [];
    while (columnNumber > 0) {
        const temp = (columnNumber - 1) % 26 + 1;
        ans.push(String.fromCharCode(temp - 1 + 'A'.charCodeAt()));
        columnNumber = Math.floor((columnNumber - temp) / 26);	// *
    }
    return ans.reverse().join('');
};
```

