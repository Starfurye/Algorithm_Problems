# 剑指 Offer II 039. 直方图最大矩形面积

给定非负整数数组 `heights`，数组中的数字用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 `1` 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

示例 1:

![](https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg)

```
输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
```

示例 2：

![](https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg)

```
输入： heights = [2,4]
输出： 4
```

提示：

-   `1 <= heights.length <= 10^5`
-   `0 <= heights[i] <= 10^4`

注意：本题与主站 84 题相同： https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

## Solution

```python
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        res = 0
        heights = [0] + heights + [0]   # 放入哨兵
        stack = [0]
        for i in range(1, len(heights)):
            while heights[i] < heights[stack[-1]]:
                cur_height = heights[stack.pop()]
                cur_width = i - stack[-1] - 1
                res = max(res, cur_height * cur_width)
            stack.append(i)
        return res

```
