# 剑指 Offer II 040. 矩阵中最大的矩形

给定一个由 `0` 和 `1` 组成的矩阵 `matrix` ，找出只包含 `1` 的最大矩形，并返回其面积。

**注意：** 此题 `matrix` 输入格式为一维 `01` 字符串数组。

示例 1：

![](https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg)

```
输入：matrix = ["10100","10111","11111","10010"]
输出：6
解释：最大矩形如上图所示。
```

示例 2：

```
输入：matrix = []
输出：0
```

示例 3：

```
输入：matrix = ["0"]
输出：0
```

示例 4：

```
输入：matrix = ["1"]
输出：1
```

示例 5：

```
输入：matrix = ["00"]
输出：0
```

提示：

-   `rows == matrix.length`
-   `cols == matrix[0].length`
-   `0 <= row, cols <= 200`
-   `matrix[i][j]` 为 `'0'` 或 `'1'`

注意：本题与主站 85 题相同（输入参数格式不同）： https://leetcode-cn.com/problems/maximal-rectangle/

## Solution

### 单调栈

每一层看作是柱状图，可以套用[前一题](https://leetcode-cn.com/problems/0ynMMM/)的最大面积。

以 `matrix = ["10100","10111","11111","10010"]` 为例：

第一层柱状图的高度["1","0","1","0","0"]，最大面积为 1；

```
xoxoo(10100)
```

第二层柱状图的高度["2","0","2","1","1"]，最大面积为 3；

```
xoxoo
xoxxx(20211)
```

第三层柱状图的高度["3","1","3","2","2"]，最大面积为 6；

```
xoxoo
xoxxx
xxxxx(31322)
```

第四层柱状图的高度["4","0","0","3","0"]，最大面积为 4；

```
xoxoo
xoxxx
xxxxx
xooxo(40030)
```

```python
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        # 记录当前位置上方连续“1”的个数
        heights = [0] * (n + 2)
        res = 0
        for i in range(m):
            for j in range(1, n + 1):
                # 前缀和
                # 注意边界，heights[0 .. n + 1]，matrix[0 .. m - 1][0 .. n - 1]
                heights[j] = heights[j] + 1 if matrix[i][j - 1]=="1" else 0
            # 单调栈
            stack=[0]
            for k in range(1, len(heights)):
                while heights[k] < heights[stack[-1]]:
                    cur_height = heights[stack.pop()]
                    cur_width = k - stack[-1] - 1
                    res = max(res, cur_height * cur_width)
                stack.append(k)

        return res
```
