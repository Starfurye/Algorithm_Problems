# 剑指 Offer 42. 连续子数组的最大和

输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

**示例1:**

```
输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```

**提示：**

- `1 <= arr.length <= 10^5`
- `-100 <= arr[i] <= 100`

## Solution

### 贪心+滑动窗口

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let ans = nums[0];
    let sum = 0;
    for (let num of nums) {
        if (sum > 0) {
            sum += num;
        } else sum = num;
        ans = Math.max(ans, sum);
    }
    return ans;
};
```

### 动态规划

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let dp = new Array(nums.length).fill(0);
    dp[0] = nums[0];
    let ans = nums[0];
    for (let i = 1; i < nums.length; i++) {
        // nums[i]加入或单独成为一段
        dp[i] = Math.max(dp[i - 1] + nums[i], nums[i]);
        ans = Math.max(ans, dp[i]);
    }
    return ans;
};
```

#### 滚动数组

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let pre = nums[0];
    let ans = nums[0];
    for (let i = 1; i < nums.length; i++) {
        // nums[i]加入或单独成为一段
        pre = Math.max(pre + nums[i], nums[i]);
        ans = Math.max(ans, pre);
    }
    return ans;
};
```

