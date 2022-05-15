# 剑指 Offer II 035. 最小时间差

给定一个 24 小时制（小时:分钟 "**HH:MM**"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。

示例 1：

```
输入：timePoints = ["23:59","00:00"]
输出：1
```

示例 2：

```
输入：timePoints = ["00:00","23:59","00:00"]
输出：0
```

提示：

-   `2 <= timePoints <= 2 * 10^4`
-   `timePoints[i]` 格式为 "**HH:MM**"

注意：本题与主站 539 题相同： https://leetcode-cn.com/problems/minimum-time-difference/

## Solution

```javascript
/**
 * @param {string[]} timePoints
 * @return {number}
 */
var findMinDifference = function (timePoints) {
    timePoints.sort();
    let nums = timePoints.map(convert2Num);
    let ans = 1440 - nums[nums.length - 1] + nums[0];
    for (let i = 0; i < nums.length - 1; i++) {
        ans = Math.min(ans, nums[i + 1] - nums[i]);
    }
    return ans;
};

const convert2Num = (str) => {
    let arr = str.split(":");
    return parseInt(arr[0]) * 60 + parseInt(arr[1]);
};
```
