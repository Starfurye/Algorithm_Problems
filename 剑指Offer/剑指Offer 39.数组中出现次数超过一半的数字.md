# 剑指 Offer 39. 数组中出现次数超过一半的数字

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

**示例  1:**

```
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
```

**限制：**

-   `1 <= 数组长度 <= 50000`

注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/

## Solution

### 摩尔投票法

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    let count = 0,
        candidate = 0; // count大于零时：遇到candidate就加一，否则减一；count为零时，设置当前数为candidate
    nums.forEach((num) => {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) count++;
        else if (num != candidate) count--;
    });
    return candidate;
};
```

### 排序

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    nums.sort((a, b) => a - b);
    return nums[Math.floor(nums.length / 2)];
};
```
