# 剑指 Offer II 101. 分割等和子集

给定一个非空的正整数数组 `nums` ，请判断能否将这些数字分成元素和相等的两部分。

示例  1：

```
输入：nums = [1,5,11,5]
输出：true
解释：nums 可以分割成 [1, 5, 5] 和 [11] 。
```

示例  2：

```
输入：nums = [1,2,3,5]
输出：false
解释：nums 不可以分为和相等的两部分
```

提示：

-   `1 <= nums.length <= 200`
-   `1 <= nums[i] <= 100`

注意：本题与主站 416  题相同： https://leetcode-cn.com/problems/partition-equal-subset-sum/

## Solution

### 背包问题

`dp[i][j]`： 背包容量为 `j`，从 `nums[0..i]` 里选元素的最大和。

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function (nums) {
    let target = nums.reduce((pre, next) => pre + next) / 2;
    if (target != Math.floor(target)) return false;

    let dp = new Array(10001).fill(0);
    for (let i = 0; i < nums.length; i++) {
        for (let j = target; j >= nums[i]; j--) {
            // 不选 或 从少一个元素但和少 nums[i] 的情况里加上 nums[i]
            dp[j] = Math.max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }

    if (dp[target] == target) return true;
    return false;
};
```
