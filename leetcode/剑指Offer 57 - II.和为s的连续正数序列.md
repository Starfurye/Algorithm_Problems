# 剑指 Offer 57 - II. 和为 s 的连续正数序列

输入一个正整数 `target` ，输出所有和为 `target` 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例 1：

```
输入：target = 9
输出：[[2,3,4],[4,5]]
```

示例 2：

```
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
```

限制：

-   `1 <= target <= 10^5`

## Solution

### 双指针

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function (target) {
    let ans = [];
    let p = 1,
        q = 2; // [p, q]
    while (q > p && q < target) {
        let sum = ((p + q) * (q - p + 1)) / 2;
        if (sum == target) {
            let temp = [];
            for (let i = p; i <= q; i++) temp.push(i);
            ans.push([...temp]);
            p++;
        } else if (sum > target) p++;
        else q++;
    }

    return ans;
};
```
