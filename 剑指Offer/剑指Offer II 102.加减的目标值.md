# 剑指 Offer II 102. 加减的目标值

给定一个正整数数组 `nums` 和一个整数 `target` 。

向数组中的每个整数前添加  `'+'` 或 `'-'` ，然后串联起所有整数，可以构造一个 **表达式** ：

-   例如，`nums = [2, 1]` ，可以在 `2` 之前添加 `'+'` ，在 `1` 之前添加 `'-'` ，然后串联起来得到表达式 `"+2-1"` 。
    返回可以通过上述方法构造的、运算结果等于 `target` 的不同 **表达式** 的数目。

示例 1：

```
输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

示例 2：

```
输入：nums = [1], target = 1
输出：1
```

提示：

-   `1 <= nums.length <= 20`
-   `0 <= nums[i] <= 1000`
-   `0 <= sum(nums[i]) <= 1000`
-   `-1000 <= target <= 1000`

注意：本题与主站 494  题相同： https://leetcode-cn.com/problems/target-sum/

## Solution

![lc102.PNG](https://s2.loli.net/2022/02/10/GuWRgmpZtM9LHqT.png)

目标和为 `(sum - target) / 2`。

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var findTargetSumWays = function (nums, target) {
    const sum = nums.reduce((pre, next) => pre + next);
    const diff = sum - target;
    if (diff < 0 || diff & (1 == 1)) return 0;
    const tar = diff / 2;
    const dp = new Array(tar + 1).fill(0);
    dp[0] = 1;
    for (const num of nums) {
        for (let j = tar; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }
    return dp[tar];
};
```
