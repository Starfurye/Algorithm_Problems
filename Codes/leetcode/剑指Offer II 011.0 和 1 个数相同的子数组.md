# 剑指 Offer II 011. 0 和 1 个数相同的子数组

给定一个二进制数组 `nums` , 找到含有相同数量的 `0` 和 `1` 的最长连续子数组，并返回该子数组的长度。

示例 1:

```
输入: nums = [0,1]
输出: 2
说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
```

示例 2:

```
输入: nums = [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量 0 和 1 的最长连续子数组。
```

提示：

-   `1 <= nums.length <= 10^5`
-   `nums[i]` 不是 `0` 就是 `1`

注意：本题与主站 525 题相同： https://leetcode-cn.com/problems/contiguous-array/

## Solution

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxLength = function (nums) {
    let map = new Map();
    map.set(0, -1);
    let res = 0,
        count = 0; // 将 0 看做 -1，计算前缀和

    for (let i = 0; i < nums.length; i++) {
        const num = nums[i];
        if (num === 1) count++;
        else count--;
        if (map.has(count)) {
            const prevIndex = map.get(count);
            res = Math.max(res, i - prevIndex);
        } else map.set(count, i);
    }
    return res;
};
```
