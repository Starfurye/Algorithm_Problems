# 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

**示例：**

```
输入：nums = [1,2,3,4]
输出：[1,3,2,4]
注：[3,1,2,4] 也是正确的答案之一。
```

**提示：**

1. `0 <= nums.length <= 50000`
2. `0 <= nums[i] <= 10000`

## Solution

### 双指针

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function (nums) {
    let left = 0,
        right = nums.length - 1;
    while (left < right) {
        // 注意js里位运算的优先级
        while ((nums[left] & 1) == 1 && left < nums.length) left++;
        while ((nums[right] & 1) == 0 && right >= 0) right--;
        if (left < right) [nums[left], nums[right]] = [nums[right], nums[left]];
    }
    return nums;
};
```
