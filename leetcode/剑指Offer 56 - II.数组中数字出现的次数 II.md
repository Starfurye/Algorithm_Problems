# 剑指 Offer 56 - II. 数组中数字出现的次数 II

在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

示例 1：

```
输入：nums = [3,4,3,3]
输出：4
```

示例 2：

```
输入：nums = [9,1,7,9,7,9,7]
输出：1
```

限制：

-   `1 <= nums.length <= 10000`
-   `1 <= nums[i] < 2^31`

注意：本题与主站 137 题相同：https://leetcode-cn.com/problems/single-number-ii/

## Solution

从二进制位角度看，第 i 位的 1 的总数 `count[i] = 3 * k + m`，当要求的数该位为 1 时，m 为 1。最后对所有位对 3 取模即可。

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function (nums) {
    let counts = new Array(32).fill(0);

    for (let num of nums) {
        let mask = 1;
        for (let i = 0; i < 32; i++) {
            if (mask & num) counts[i]++;
            mask <<= 1;
        }
    }

    const m = 3; // 通过修改m可以解决“除一个数字出现一次，其他数字出现m次”的问题
    let res = 0;
    for (let i = 0; i < counts.length; i++) {
        res <<= 1;
        res |= counts[31 - i] % m;
    }
    return res;
};
```
