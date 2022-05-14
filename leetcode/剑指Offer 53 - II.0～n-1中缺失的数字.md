# 剑指 Offer 53 - II. 0 ～ n-1 中缺失的数字

一个长度为 n-1 的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围 0 ～ n-1 之内。在范围 0 ～ n-1 内的 n 个数字中有且只有一个数字不在该数组中，请找出这个数字。

**示例 1:**

```
输入: [0,1,3]
输出: 2
```

**示例 2:**

```
输入: [0,1,2,3,4,5,6,7,9]
输出: 8
```

**限制：**

```
1 <= 数组长度 <= 10000
```

## Solution

### 顺序查找

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function (nums) {
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] != i) return i;
    }
    return nums.length;
};
```

### 异或

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function (nums) {
    let temp = 0;
    for (let i = 0; i <= nums.length; i++) temp ^= i;
    for (let num of nums) temp ^= num;
    return temp;
};
```

### 二分法

由于递增，可以使用二分法。

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function (nums) {
    let left = 0,
        right = nums.length - 1;
    while (left <= right) {
        let mid = Math.floor((right - left) / 2 + left);
        if (nums[mid] == mid) {
            left = mid + 1;
        } else if (nums[mid] > mid) {
            // 当前位置大于索引，说明前面少了个数
            right = mid - 1;
        }
        // nums[mid]不可能小于mid
    }
    return left;
};
```
