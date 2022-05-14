# 653. Two Sum IV - Input is a BST

Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

![](https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg)

```
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
```

Example 2:

![](https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg)

```
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
```

Constraints:

-   The number of nodes in the tree is in the range `[1, 10^4]`.
-   `-10^4 <= Node.val <= 10^4`
-   root is guaranteed to be a **valid** binary search tree.
-   `-10^5 <= k <= 10^5`

## Solution

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {boolean}
 */
var findTarget = function (root, k) {
    let list = [];
    inorder(root, list);
    let l = 0,
        r = list.length - 1;
    while (l < r) {
        let sum = list[l] + list[r];
        if (sum == k) {
            return true;
        }
        if (sum < k) l++;
        else r--;
    }
    return false;
};
function inorder(root, list) {
    if (!root) return;
    inorder(root.left, list);
    list.push(root.val);
    inorder(root.right, list);
}
```
