# 剑指 Offer II 056. 二叉搜索树中两个节点之和

给定一个二叉搜索树的 **根节点** `root` 和一个整数 `k` , 请判断该二叉搜索树中是否存在两个节点它们的值之和等于 `k` 。假设二叉搜索树中节点的值均唯一。

示例 1：

```
输入: root = [8,6,10,5,7,9,11], k = 12
输出: true
解释: 节点 5 和节点 7 之和等于 12
```

示例 2：

```
输入: root = [8,6,10,5,7,9,11], k = 22
输出: false
解释: 不存在两个节点值之和为 22 的节点
```

提示：

-   二叉树的节点个数的范围是 `[1, 10^4]`.
-   `-10^4 <= Node.val <= 10^4`
-   `root` 为二叉搜索树
-   `-10^5 <= k <= 10^5`

注意：本题与主站 653 题相同： https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/

## Solution

### BST 性质+双指针

```js
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
