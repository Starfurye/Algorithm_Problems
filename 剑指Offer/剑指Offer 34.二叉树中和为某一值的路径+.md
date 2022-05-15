# 剑指 Offer 34. 二叉树中和为某一值的路径

给你二叉树的根节点 `root` 和一个整数目标和 `targetSum` ，找出所有 **从根节点到叶子节点** 路径总和等于给定目标和的路径。

**叶子节点** 是指没有子节点的节点。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg)

```
输入：root = [1,2,3], targetSum = 5
输出：[]
```

**示例 3：**

```
输入：root = [1,2], targetSum = 0
输出：[]
```

**提示：**

-   树中节点总数在范围 `[0, 5000]` 内
-   `-1000 <= Node.val <= 1000`
-   `-1000 <= targetSum <= 1000`

注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/

## Solution

### 回溯

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
 * @param {number} target
 * @return {number[][]}
 */
var pathSum = function (root, target) {
    const res = [];

    const backTrack = (sum, node, path) => {
        // 必须是叶子节点
        if (sum === target && node.left == null && node.right == null) {
            res.push([...path]);
            return;
        }

        if (node.left) {
            path.push(node.left.val);
            backTrack(sum + node.left.val, node.left, path);
            path.pop();
        }
        if (node.right) {
            path.push(node.right.val);
            backTrack(sum + node.right.val, node.right, path);
            path.pop();
        }
    };

    if (!root) return res;
    // 后面不会再push根节点，因此根节点一定要先在里面
    backTrack(root.val, root, [root.val]);

    return res;
};
```
