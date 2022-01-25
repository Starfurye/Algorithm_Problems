# 剑指 Offer II 038. 每日温度

请根据每日 `气温` 列表 `temperatures` ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 `0` 来代替。

示例 1:

```
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
```

示例 2:

```
输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
```

示例 3:

```
输入: temperatures = [30,60,90]
输出: [1,1,0]
```

提示：

-   `1 <= temperatures.length <= 10^5`
-   `30 <= temperatures[i] <= 100`

注意：本题与主站 739 题相同： https://leetcode-cn.com/problems/daily-temperatures/

## Solution

### 栈

```js
/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function (temperatures) {
    let ans = new Array(temperatures.length).fill(0);
    let stack = [];
    for (let i = 0; i < temperatures.length; i++) {
        let temperature = temperatures[i];
        while (
            stack.length > 0 &&
            temperature > temperatures[stack[stack.length - 1]]
        ) {
            let prevIndex = stack.pop();
            ans[prevIndex] = i - prevIndex;
        }
        stack.push(i);
    }
    return ans;
};
```
