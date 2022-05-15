# 剑指 Offer 11. 旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为 1。

**示例 1：**

```
输入：[3,4,5,1,2]
输出：1
```

**示例 2：**

```
输入：[2,2,2,0,1]
输出：0
```

注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

## Solution

```javascript
/**
 * @param {number[]} numbers
 * @return {number}
 */
var minArray = function (numbers) {
    let left = 0,
        right = numbers.length - 1;
    while (left < right) {
        let mid = Math.floor((right - left) / 2 + left);
        // 和numbers[right]比较
        // 无法判断 m 在左和右哪个排序数组中，numbers[mid]和numbers[right]相等时mid右移以缩小范围
        while (numbers[mid] == numbers[right] && mid <= right - 2) {
            // 注意是right - 2，如果是right - 1，mid++后，mid = right，等于没有更新right
            mid++;
        }
        if (numbers[right] >= numbers[mid]) {
            right = mid;
        } else if (numbers[right] < numbers[mid]) {
            left = mid + 1;
        }
    }
    return numbers[left];
};
```
