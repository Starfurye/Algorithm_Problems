# 剑指 Offer 61. 扑克牌中的顺子

从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这 5 张牌是不是连续的。2 ～ 10 为数字本身，A 为 1，J 为 11，Q 为 12，K 为 13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

**示例 1:**

```
输入: [1,2,3,4,5]
输出: True
```

**示例 2:**

```
输入: [0,0,1,2,5]
输出: True
```

**限制：**

数组长度为 5

数组的数取值为 [0, 13] .

## Solution

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isStraight = function (nums) {
    nums.sort((a, b) => a - b);
    let zero = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] == 0) zero++;
        else if (nums[i] == nums[i - 1]) return false;
        else if (nums[i - 1] != 0 && nums[i] - nums[i - 1] > 1) {
            if (zero >= nums[i] - nums[i - 1] - 1) {
                zero -= nums[i] - nums[i - 1] - 1;
            } else return false;
        }
    }
    return true;
};
```
