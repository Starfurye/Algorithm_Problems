# 剑指 Offer 53 - I. 在排序数组中查找数字 I

统计一个数字在排序数组中出现的次数。

**示例 1:**

```
输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
```

**示例 2:**

```
输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
```

**限制：**

```
0 <= 数组长度 <= 50000
```

## Solution

### 二分

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    // 找左边界
    let left = 0,
        right = nums.length;
    while (left < right) {
        let mid = Math.floor((right - left) / 2 + left);
        if (target <= nums[mid]) {
            right = mid;
        } else if (target > nums[mid]) {
            left = mid + 1;
        }
    }
    let count = 0;
    for (let i = left; i < nums.length; i++) {
        if (nums[i] == target) count++;
        else break;
    }
    return count;
};
```

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
    var binarySearch = () => {
        let left = 0,
            right = nums.length - 1; // 闭区间
        while (left <= right) {
            let mid = Math.floor((right - left) / 2 + left);
            if (nums[mid] === target) return mid;
            else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        return -1;
    };
    let res = binarySearch();
    if (res === -1) return 0; // 没有该数字
    let count = 0;
    for (let i = res - 1; i >= 0; i--) {
        // 统计左边的数字
        if (nums[i] === nums[res]) count++;
        else break;
    }
    for (let i = res + 1; i < nums.length; i++) {
        // 统计右边的数字
        if (nums[i] === nums[res]) count++;
        else break;
    }
    return count + 1; // 加上mid本身
};
```
