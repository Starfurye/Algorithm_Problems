# 剑指 Offer 40. 最小的k个数

输入整数数组 `arr` ，找出其中最小的 `k` 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

**示例 1：**

```
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
```

**示例 2：**

```
输入：arr = [0,1,2,1], k = 1
输出：[0]
```

**限制：**

- `0 <= k <= arr.length <= 10000`
- `0 <= arr[i] <= 10000`

## Solution

### 快速搜索（基于快排划分算法）

```js
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    const quickSearch = (l, r) => {
        let i = l, j = r;
        while (i < j) {
            // pivot = arr[l]
            while (i < j && arr[j] >= arr[l]) j--;
            while (i < j && arr[i] <= arr[l]) i++;
            [arr[i], arr[j]] = [arr[j], arr[i]];
        }
        // 注意交换写法要带上中括号
        [arr[l], arr[i]] = [arr[i], arr[l]];
        // pivot位置大于k，对pivot左边子数组递归
        if (k < i) return quickSearch(l, i - 1);
        // pivot位置小于k，对pivot右边子数组递归
        else if (k > i) return quickSearch(i + 1, r);
        // pivot等于k，前k个数排序结束，返回
        else return arr.slice(0, k);
    };

    if (k > arr.length) return arr;
    else if (k == 0) return [];

    return quickSearch(0, arr.length - 1);
};
```



### API

```js
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    return arr.sort((a, b) => a - b).slice(0, k);
};
```

