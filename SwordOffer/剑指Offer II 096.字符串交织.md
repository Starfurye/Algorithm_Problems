# 剑指 Offer II 096. 字符串交织

给定三个字符串  `s1`、`s2`、`s3`，请判断  `s3`  能不能由  `s1`  和  `s2` **交织（交错）**  组成。

两个字符串 `s` 和 `t` **交织**  的定义与过程如下，其中每个字符串都会被分割成若干 **非空** 子字符串：

-   `s = s1 + s2 + ... + sn`
-   `t = t1 + t2 + ... + tm`
-   `|n - m| <= 1`
-   **交织** 是 `s1 + t1 + s2 + t2 + s3 + t3 + ...` 或者 `t1 + s1 + t2 + s2 + t3 + s3 + ...`

**提示：** `a + b` 意味着字符串 `a` 和 `b` 连接。

示例 1：

```
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true
```

示例 2：

```
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false
```

示例 3：

```
输入：s1 = "", s2 = "", s3 = ""
输出：true
```

提示：

-   `0 <= s1.length, s2.length <= 100`
-   `0 <= s3.length <= 200`
-   `s1`、`s2`、和 `s3` 都由小写英文字母组成

注意：本题与主站 97  题相同： https://leetcode-cn.com/problems/interleaving-string/

## Solution

### 动态规划

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} s3
 * @return {boolean}
 */
var isInterleave = function (s1, s2, s3) {
    if (s1.length + s2.length != s3.length) return false;

    // dp[i][j] 表示 s1 的前 i 个字母和 s2 的前 j 个字母与 s3 的前 i + j 个字母 是否交错(0 or 1)
    const dp = new Array(s1.length + 1)
        .fill(0)
        .map(() => new Array(s2.length + 1).fill(0));
    dp[0][0] = 1;

    for (let i = 1; i <= s1.length; i++)
        dp[i][0] = dp[i - 1][0] && s1.charAt(i - 1) == s3.charAt(i - 1);
    for (let j = 1; j <= s2.length; j++)
        dp[0][j] = dp[0][j - 1] && s2.charAt(j - 1) == s3.charAt(j - 1);

    for (let i = 1; i <= s1.length; i++) {
        for (let j = 1; j <= s2.length; j++) {
            dp[i][j] =
                (dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1)) ||
                (dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1));
        }
    }

    return dp[s1.length][s2.length];
};
```
