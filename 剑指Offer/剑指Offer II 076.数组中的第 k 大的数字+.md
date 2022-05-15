# 剑指 Offer II 076. 数组中的第 k 大的数字

给定整数数组 `nums` 和整数 `k`，请返回数组中第 `k` 个最大的元素。

请注意，你需要找的是数组排序后的第 `k` 个最大的元素，而不是第 `k` 个不同的元素。

示例 1:

```
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
```

示例 2:

```
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
```

提示：

-   `1 <= k <= nums.length <= 10^4`
-   `-10^4 <= nums[i] <= 10^4`

注意：本题与主站 215 题相同： https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

## Solution

### 快速搜索（基于快排划分算法）

注意第 `k` 个数的索引 `k - 1`。

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function (nums, k) {
    const quickSearch = (l, r) => {
        let i = l,
            j = r;
        while (i < j) {
            while (i < j && nums[j] <= nums[l]) j--;
            while (i < j && nums[i] >= nums[l]) i++;
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
        [nums[l], nums[i]] = [nums[i], nums[l]];
        if (k - 1 < i) return quickSearch(l, i - 1);
        else if (k - 1 > i) return quickSearch(i + 1, r);
        else return nums[k - 1];
    };

    if (k == 0) return [];
    return quickSearch(0, nums.length - 1);
};
```

### 堆

```python
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        h = []
        for num in nums:
            heappush(h, num)
            if len(h) > k:
                heappop(h)
        return h[0]
```
