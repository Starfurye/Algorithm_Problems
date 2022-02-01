# 剑指 Offer II 075. 数组相对排序

给定两个数组，`arr1` 和 `arr2`，

-   `arr2` 中的元素各不相同
-   `arr2` 中的每个元素都出现在 `arr1` 中

对 `arr1` 中的元素进行排序，使 `arr1` 中项的相对顺序和 `arr2` 中的相对顺序相同。未在 `arr2` 中出现过的元素需要按照升序放在 `arr1` 的末尾。

示例：

```
输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
```

提示：

-   `1 <= arr1.length, arr2.length <= 1000`
-   `0 <= arr1[i], arr2[i] <= 1000`
-   `arr2` 中的元素 `arr2[i]` 各不相同
-   `arr2` 中的每个元素 `arr2[i]` 都出现在 `arr1` 中

注意：本题与主站 1122 题相同：https://leetcode-cn.com/problems/relative-sort-array/

## Solution

### 排序

根据题目要求写好排序规则：

-   出现在 `arr2` 中的按 `arr2` 中的顺序排序；
-   没有在 `arr2` 出现的按大小排序；
-   出现在 `arr2` 中的元素要排在没出现在 `arr2` 中的元素之前（可以认为前者比后者小）。

```js
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function (arr1, arr2) {
    arr1.sort((item1, item2) => {
        let ord1 = arr2.indexOf(item1);
        let ord2 = arr2.indexOf(item2);
        if (ord1 >= 0 && ord2 >= 0) {
            return ord1 - ord2;
        } else if (ord1 < 0 && ord2 >= 0) {
            return 1;
        } else if (ord2 < 0 && ord1 >= 0) {
            return -1;
        } else return item1 - item2;
    });
    return arr1;
};
```
