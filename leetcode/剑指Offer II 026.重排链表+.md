# 剑指 Offer II 026. 重排链表

给定一个单链表 `L` 的头节点 `head` ，单链表 `L` 表示为：

```
 L0 → L1 → … → Ln-1 → Ln
```

请将其重新排列后变为：

```
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
```

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

![](https://pic.leetcode-cn.com/1626420311-PkUiGI-image.png)

```
输入: head = [1,2,3,4]
输出: [1,4,2,3]
```

示例 2:

![](https://pic.leetcode-cn.com/1626420320-YUiulT-image.png)

```
输入: head = [1,2,3,4,5]
输出: [1,5,2,4,3]
```

提示：

-   链表的长度范围为 `[1, 5 * 10^4]`
-   `1 <= node.val <= 1000`

注意：本题与主站 143 题相同：https://leetcode-cn.com/problems/reorder-list/

## Solution

交换等同于将链表[后半段](https://leetcode-cn.com/problems/middle-of-the-linked-list/)[反转](https://leetcode-cn.com/problems/reverse-linked-list/)，然后和前半段做合并。

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function (head) {
    let bp = reverseList(findMid(head));
    let fp = head;
    while (bp) {
        let next = bp.next;
        bp.next = fp.next;
        fp.next = bp;
        bp = next;
        fp = fp.next.next;
    }
    return head;
};

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const findMid = (head) => {
    // 返回中间结点，若总结点数为偶数（有两个中间结点），返回后一个
    let slow = (fast = head);
    while (fast && fast.next) {
        fast = fast.next.next;
        slow = slow.next;
    }
    let p = slow.next;
    slow.next = null; // 切断中间结点的next
    return p;
};

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const reverseList = (head) => {
    let pre = null,
        cur = head;
    while (cur) {
        let next = cur.next;
        cur.next = pre;
        [pre, cur] = [cur, next];
    }
    return pre;
};
```
