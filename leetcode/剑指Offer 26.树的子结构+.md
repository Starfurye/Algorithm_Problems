# 剑指 Offer 26. 树的子结构

输入两棵二叉树 A 和 B，判断 B 是不是 A 的子结构。(约定空树不是任意一个树的子结构)

B 是 A 的子结构， 即 A 中有出现和 B 相同的结构和节点值。

例如:
给定的树 A:

```
		3
		/ \
		4  5
		/ \
		1  2
```

给定的树 B：

```
4
/
1
```

返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

**示例 1：**

```
输入：A = [1,2,3], B = [3,1]
输出：false
```

**示例 2：**

```
输入：A = [3,4,5,1,2], B = [4,1]
输出：true
```

**限制：**

`0 <= 节点个数 <= 10000`

## Solution

### 先序遍历+判断

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} A
 * @param {TreeNode} B
 * @return {boolean}
 */
var isSubStructure = function (A, B) {
    // 判断b是否为a的子结构
    const recur = (a, b) => {
        if (b == null) return true;
        else if (a == null || a.val != b.val) return false;
        // 继续判断b的左子树是否为a的左子树的子结构，b的右子树是否为a的右子树的子结构
        return recur(a.left, b.left) && recur(a.right, b.right);
    };

    if (!A || !B) return false;
    // B是A的子结构 || B是A的左子树的子结构 || B是A的右子树的子结构
    return (
        recur(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B)
    );
};
```
