# 剑指 Offer 25. 合并两个排序的链表

输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

**示例 1：**

```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

**限制：**

```
0 <= 链表长度 <= 1000
```

注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/

## Solution

### 双指针

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function (l1, l2) {
    let head = new ListNode(0),
        cur = head;
    let p1 = l1,
        p2 = l2;
    while (p1 && p2) {
        if (p1.val <= p2.val) {
            cur.next = p1;
            cur = cur.next;
            p1 = p1.next;
        } else {
            cur.next = p2;
            cur = cur.next;
            p2 = p2.next;
        }
    }
    cur.next = p1 == null ? p2 : p1;
    return head.next;
};
```
