# 剑指 Offer II 082. 含有重复元素集合的组合

给定一个可能有重复数字的整数数组 `candidates` 和一个目标数 `target` ，找出 `candidates` 中所有可以使数字和为 `target` 的组合。

`candidates` 中的每个数字在每个组合中只能使用一次，解集不能包含重复的组合。

示例 1:

```
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

示例 2:

```
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
```

提示:

-   `1 <= candidates.length <= 100`
-   `1 <= candidates[i] <= 50`
-   `1 <= target <= 30`

注意：本题与主站 40 题相同： https://leetcode-cn.com/problems/combination-sum-ii/

## Solution

### 回溯

```js
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function (candidates, target) {
    const backTrack = (sum, index) => {
        if (sum == target) {
            res.push([...temp]);
            return;
        } else if (sum > target) return;

        for (let i = index; i < candidates.length; i++) {
            // [1,1,5]这种情况每次index都是0，不会被去除
            if (i > index && candidates[i] == candidates[i - 1]) continue; // 去除相同元素
            temp.push(candidates[i]);
            backTrack(sum + candidates[i], i + 1);
            temp.pop();
        }
    };

    candidates.sort((a, b) => a - b);
    let res = [],
        temp = [];
    backTrack(0, 0);
    return res;
};
```
