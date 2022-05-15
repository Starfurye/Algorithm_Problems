# 剑指 Offer II 085. 生成匹配的括号

正整数  `n`  代表生成括号的对数，请设计一个函数，用于能够生成所有可能的并且 **有效的** 括号组合。

示例 1：

```
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
```

示例 2：

```
输入：n = 1
输出：["()"]
```

提示：

-   `1 <= n <= 8`

注意：本题与主站 22  题相同： https://leetcode-cn.com/problems/generate-parentheses/

## Solution

### 回溯

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
    const backTrack = (index) => {
        if (temp.length == 2 * n) {
            if (checkPar(temp, n)) res.push(temp.join(""));
            return;
        }
        for (let i = index; i < 2 * n; i++) {
            temp.push("(");
            backTrack(i + 1);
            temp.pop();
            temp.push(")");
            backTrack(i + 1);
            temp.pop();
        }
    };

    let res = [],
        temp = [];
    backTrack(0);
    return res;
};
function checkPar(stack, n) {
    // 检测是否为正确的括号
    let left = 0,
        right = 0;
    for (let i = 0; i < stack.length; i++) {
        if (stack[i] == "(") {
            left++;
        } else right++;
        if (left - right > n || right > left) return false;
    }
    if (left == right) return true;
}
```
