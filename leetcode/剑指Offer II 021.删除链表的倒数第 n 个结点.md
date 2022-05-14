# 剑指 Offer II 021. 删除链表的倒数第 n 个结点

给定一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

示例 1：

![](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

```
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

示例 2：

```
输入：head = [1], n = 1
输出：[]
```

示例 3：

```
输入：head = [1,2], n = 1
输出：[1]
```

提示：

-   链表中结点的数目为 `sz`
-   `1 <= sz <= 30`
-   `0 <= Node.val <= 100`
-   `1 <= n <= sz`

进阶：能尝试使用一趟扫描实现吗？

注意：本题与主站 19 题相同：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
    let dummy = new ListNode(0, head);
    let fast = dummy,
        slow = dummy;
    for (let i = 0; i < n; i++) {
        fast = fast.next;
    }
    while (fast.next) {
        slow = slow.next;
        fast = fast.next;
    }
    slow.next = slow.next.next;
    return dummy.next;
};
```
