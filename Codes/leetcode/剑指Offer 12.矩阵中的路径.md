# 剑指 Offer 12. 矩阵中的路径



## Solution

### 回溯

```js
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const dir = [[1, 0], [0, -1], [-1, 0], [0, 1]];
    const backTrack = (x, y, i) => {
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length || board[x][y] != word[i]) return false;
        if (i == word.length - 1) return true;

        // 回溯
        board[x][y] = ''; // 该位置已来过，置空
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
var exist = function(board, word) {
    const dfs = (x, y, i) => {      // 当前位置(x, y)，word的第i位
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length || board[x][y] != word[i]) return false;
        if (i == word.length - 1) return true;  // 找到word

        board[x][y] = ''; // 该位置已来过，置空
        let res = dfs(x + 1, y, i + 1) || dfs(x, y - 1, i + 1) || dfs(x - 1, y, i + 1) || dfs(x, y + 1, i + 1); // 下左上右
        board[x][y] = word[i];      // 回溯

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