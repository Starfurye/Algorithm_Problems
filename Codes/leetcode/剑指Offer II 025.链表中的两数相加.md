# 剑指 Offer II 025. 链表中的两数相加

给定两个 **非空链表** `l1` 和 `l2` 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例 1：

![](https://pic.leetcode-cn.com/1626420025-fZfzMX-image.png)

```
输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]
```

示例 2：

```
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[8,0,7]
```

示例 3：

```
输入：l1 = [0], l2 = [0]
输出：[0]
```

提示：

-   链表的长度范围为 `[1, 100]`
-   `0 <= node.val <= 9`
-   输入数据保证链表代表的数字无前导 0

**进阶：** 如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。

注意：本题与主站 445 题相同：https://leetcode-cn.com/problems/add-two-numbers-ii/

## Solution

### 栈

利用栈来进行末尾对齐。

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
    let p1 = l1,
        p2 = l2;
    let st1 = [],
        st2 = [];
    while (p1 && p2) {
        st1.push(p1.val);
        st2.push(p2.val);
        p1 = p1.next;
        p2 = p2.next;
    }
    while (p1) {
        st1.push(p1.val);
        st2.unshift(0);
        p1 = p1.next;
    }
    while (p2) {
        st2.push(p2.val);
        st1.unshift(0);
        p2 = p2.next;
    }

    let head = new ListNode(0, null);
    let carry = 0;
    for (let i = st1.length - 1; i >= 0; i--) {
        let sum = (st1[i] + st2[i] + carry) % 10; //处理进位
        carry = st1[i] + st2[i] + carry >= 10 ? 1 : 0;
        let temp = new ListNode(sum, null);
        if (head.next) {
            temp.next = head.next;
        }
        head.next = temp;
    }
    if (carry) {
        let temp = new ListNode(1, null); //处理进位
        temp.next = head.next;
        head.next = temp;
    }
    return head.next;
};
```
