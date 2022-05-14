# 剑指 Offer 12. 矩阵中的路径

给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

![example](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

示例 1：

```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
```

示例 2：

```
输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
```

**提示：**

-   `1 <= board.length <= 200`
-   `1 <= board[i].length <= 200`
-   `board` 和 `word` 仅由大小写英文字母组成

-   注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/

## Solution

### 回溯

```js
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function (board, word) {
    const dir = [
        [1, 0],
        [0, -1],
        [-1, 0],
        [0, 1],
    ];
    const backTrack = (x, y, i) => {
        if (
            x < 0 ||
            x >= board.length ||
            y < 0 ||
            y >= board[0].length ||
            board[x][y] != word[i]
        )
            return false;
        if (i == word.length - 1) return true;

        // 回溯
        board[x][y] = ""; // 该位置已来过，置空
        let res = false;
        for (let d of dir) {
            res = res || backTrack(x + d[0], y + d[1], i + 1);
        }
        board[x][y] = word[i];
        return res;
    };

    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (backTrack(i, j, 0)) return true;
        }
    }

    return false;
};
```

### DFS

```js
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function (board, word) {
    const dfs = (x, y, index) => {
        // 当前位置(x, y)，word的第index位
        if (
            x < 0 ||
            x >= board.length ||
            y < 0 ||
            y >= board[0].length ||
            board[x][y] != word[index]
        )
            return false;
        if (index == word.length - 1) return true;

        board[x][y] = ""; // 该位置已来过，置空
        let res =
            dfs(x + 1, y, index + 1) ||
            dfs(x, y - 1, index + 1) ||
            dfs(x - 1, y, index + 1) ||
            dfs(x, y + 1, index + 1);
        board[x][y] = word[index]; // 回溯

        return res;
    };

    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (dfs(i, j, 0)) return true;
        }
    }

    return false;
};
```
