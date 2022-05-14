# 剑指 Offer II 050. 向下的路径节点之和

给定一个二叉树的根节点 `root` ，和一个整数 `targetSum` ，求该二叉树里节点值之和等于 `targetSum` 的 **路径** 的数目。

**路径** 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

示例 1：

![](https://assets.leetcode.com/uploads/2021/04/09/pathsum3-1-tree.jpg)

```
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
```

示例 2：

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
```

提示:

-   二叉树的节点个数的范围是 `[0,1000]`
-   `-10^9 <= Node.val <= 10^9`
-   `-1000 <= targetSum <= 1000`

注意：本题与主站 437 题相同：https://leetcode-cn.com/problems/path-sum-iii/

## Solution

### 前缀和 + 回溯

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
 * @param {number} targetSum
 * @return {number}
 */
var pathSum = function (root, targetSum) {
    // key是前缀和, value是大小为key的前缀和出现的次数
    const prefix = new Map();
    // 前缀和为0的一条路径
    prefix.set(0, 1);
    return dfs(root, prefix, 0, targetSum);
};
const dfs = (node, prefix, cur, targetSum) => {
    if (!node) return 0;

    let ret = 0;
    cur += node.val;

    // 看看root到当前节点这条路上是否存在节点前缀和加target为currSum的路径
    ret = prefix.get(cur - targetSum) || 0;
    // 更新路径上当前节点前缀和的个数
    prefix.set(cur, (prefix.get(cur) || 0) + 1);

    ret += dfs(node.left, prefix, cur, targetSum);
    ret += dfs(node.right, prefix, cur, targetSum);

    // 回溯
    prefix.set(cur, (prefix.get(cur) || 0) - 1);
    return ret;
};
```
