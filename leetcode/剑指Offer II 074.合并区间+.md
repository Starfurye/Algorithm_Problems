# 剑指 Offer II 074. 合并区间

以数组 `intervals` 表示若干个区间的集合，其中单个区间为 `intervals[i] = [starti, endi]` 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

示例 1：

```
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

示例 2：

```
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
```

提示：

-   `1 <= intervals.length <= 10^4`
-   `intervals[i].length == 2`
-   `0 <= starti <= endi <= 10^4`

注意：本题与主站 56 题相同： https://leetcode-cn.com/problems/merge-intervals/

## Solution

后一个区间的左边界小于结果中最后一个区间的右边界时，更新最后一个区间的右边界或将这个区间加入结果。

```js
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
    intervals.sort((a, b) => a[0] - b[0]); // 按区间左边界排序
    let res = [intervals[0]];
    for (let i = 1; i < intervals.length; i++) {
        if (res[res.length - 1][1] >= intervals[i][0]) {
            res[res.length - 1][1] = Math.max(
                res[res.length - 1][1],
                intervals[i][1]
            );
        } else {
            res.push(intervals[i]);
        }
    }
    return res;
};
```
