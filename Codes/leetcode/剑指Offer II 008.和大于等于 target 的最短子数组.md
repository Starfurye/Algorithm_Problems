# 剑指 Offer II 008. 和大于等于 target 的最短子数组

给定一个含有 `n` 个正整数的数组和一个正整数 `target` 。

找出该数组中满足其和 `≥ target` 的长度最小的 **连续子数组** `[nums_l, nums_l+1, ..., nums_r-1, nums_r]` ，并返回其长度。如果不存在符合条件的子数组，返回 `0` 。

示例 1：

```
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
```

示例 2：

```
输入：target = 4, nums = [1,4,4]
输出：1
```

示例 3：

```
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
```

提示：

-   `1 <= target <= 10^9`
-   `1 <= nums.length <= 10^5`
-   `1 <= nums[i] <= 10^5`

进阶：

-   如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

注意：本题与主站 209 题相同：https://leetcode-cn.com/problems/minimum-size-subarray-sum/

## Solution

### 滑动窗口

```js
/**
 * @param {number} target
 * @param {number[]} nums
 * @return {number}
 */
var minSubArrayLen = function (target, nums) {
    let left = 0,
        right = 0,
        ans = Number.MAX_SAFE_INTEGER;
    let sum = nums[0];
    while (left <= right) {
        if (sum < target) {
            if (right == nums.length - 1) break;
            sum += nums[++right];
        } else if (sum >= target) {
            ans = Math.min(ans, right - left + 1);
            sum -= nums[left++];
        }
    }
    return ans == Number.MAX_SAFE_INTEGER ? 0 : ans;
};
```
