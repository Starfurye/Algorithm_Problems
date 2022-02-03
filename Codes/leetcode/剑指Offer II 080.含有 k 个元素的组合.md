# 剑指 Offer II 080. 含有 k 个元素的组合

给定两个整数 `n` 和 `k`，返回 `1 ... n` 中所有可能的 `k` 个数的组合。

示例 1:

```
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

示例 2:

```
输入: n = 1, k = 1
输出: [[1]]
```

提示:

-   `1 <= n <= 20`
-   `1 <= k <= n`

注意：本题与主站 77 题相同： https://leetcode-cn.com/problems/combinations/

## Solution

### 回溯

```js
/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function (n, k) {
    const backTrack = (index) => {
        if (temp.length == k) {
            res.push([...temp]);
            return;
        }
        for (let i = index; i <= n; i++) {
            temp.push(i);
            backTrack(i + 1);
            temp.pop();
        }
    };

    let res = [],
        temp = [];
    backTrack(1);
    return res;
};
```
