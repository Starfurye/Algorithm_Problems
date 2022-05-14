# 剑指 Offer 56 - I. 数组中数字出现的次数

一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是 O(n)，空间复杂度是 O(1)。

示例 1：

```
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
```

示例 2：

```
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
```

限制：

-   2 <= nums.length <= 10000

## Solution

### 位运算

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumbers = function (nums) {
    let sum = 0,
        mask = 1;
    nums.forEach((num) => (sum ^= num));

    let res = sum & mask;
    while (res != mask) {
        // 找到两个数不同的位
        mask <<= 1;
        res = sum & mask;
    }

    let groupA = 0,
        groupB = 0;
    nums.forEach((num) => {
        if (num & mask) groupA ^= num;
        else groupB ^= num;
    });

    return [groupA, groupB];
};
```
