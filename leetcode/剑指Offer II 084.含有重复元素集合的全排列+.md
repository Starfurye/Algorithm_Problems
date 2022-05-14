# 剑指 Offer II 084. 含有重复元素集合的全排列

给定一个可包含重复数字的整数集合  `nums` ，**按任意顺序** 返回它所有不重复的全排列。

示例 1：

```
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

示例 2：

```
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

提示：

-   `1 <= nums.length <= 8`
-   `-10 <= nums[i] <= 10`

注意：本题与主站 47  题相同： https://leetcode-cn.com/problems/permutations-ii/

## Solution

### 回溯

```js
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function (nums) {
    const backTrack = () => {
        if (temp.length == nums.length) {
            res.push([...temp]);
            return;
        }
        for (let i = 0; i < nums.length; i++) {
            // 从当前元素开始且前一个元素还未被访问过，则会重复
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0)
                continue;
            if (visited[i] == 1) continue;
            visited[i] = 1;
            temp.push(nums[i]);
            backTrack(i);
            temp.pop();
            visited[i] = 0;
        }
    };

    let res = [],
        temp = [];
    let visited = new Array(nums.length).fill(0);
    nums.sort((a, b) => a - b);
    backTrack();
    return res;
};
```
