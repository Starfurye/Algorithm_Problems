# 剑指 Offer II 010. 和为 k 的子数组

给定一个整数数组和一个整数 `k` ，请找到该数组中和为 `k` 的连续子数组的个数。

示例 1 :

```
输入:nums = [1,1,1], k = 2
输出: 2
解释: 此题 [1,1] 与 [1,1] 为两种不同的情况
```

示例 2:

```
输入:nums = [1,2,3], k = 3
输出: 2
```

提示:

-   `1 <= nums.length <= 2 * 10^4`
-   `-1000 <= nums[i] <= 1000`
-   `-10^7 <= k <= 10^7`

注意：本题与主站 560 题相同： https://leetcode-cn.com/problems/subarray-sum-equals-k/

## Solution

### 哈希表+前缀和

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function (nums, k) {
    let map = new Map();
    map.set(0, 1);
    let count = 0,
        pre = 0;

    for (const num of nums) {
        pre += num;
        if (map.has(pre - k)) {
            count += map.get(pre - k);
        }
        map.set(pre, (map.get(pre) || 0) + 1);
    }

    return count;
};
```
