# 剑指 Offer II 027. 回文链表

给定一个链表的 **头节点** `head`，请判断其是否为回文链表。

如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。

示例 1：

![](https://pic.leetcode-cn.com/1626421737-LjXceN-image.png)

```
输入: head = [1,2,3,3,2,1]
输出: true
```

![](https://pic.leetcode-cn.com/1626422231-wgvnWh-image.png)

示例 2：

```
输入: head = [1,2]
输出: false
```

提示：

-   链表 L 的长度范围为 `[1, 10^5]`
-   `0 <= node.val <= 9`

**进阶：** 能否用  O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

注意：本题与主站 234 题相同：https://leetcode-cn.com/problems/palindrome-linked-list/

## Solution

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function (head) {
    let arr = [];
    let p = head;
    while (p) {
        arr.push(p.val);
        p = p.next;
    }
    if (arr.length == 1) return true;
    for (let i = 0; i < Math.floor(arr.length / 2); i++) {
        if (arr[i] != arr[arr.length - 1 - i]) return false;
    }
    return true;
};
```
