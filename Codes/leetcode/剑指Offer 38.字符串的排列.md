# 剑指 Offer 38. 字符串的排列

输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

**示例:**

```text
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
```


**限制：**
```text
1 <= s 的长度 <= 8
```

## Solution

同lc47-全排列II。

```java
class Solution {
    int[] visited;
    StringBuilder temp = new StringBuilder();
    ArrayList<String> res = new ArrayList<>();
    public String[] permutation(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        int strlen = chars.length;
        visited = new int[strlen];
        backtrack(chars, 0);
        return res.toArray(new String[res.size()]);
    }
    public void backtrack(char[] chars, int index) {
        if(index == chars.length){
            res.add(temp.toString());
            return;
        }
        for(int i = 0; i < chars.length; ++i){
            if (i > 0 && chars[i] == chars[i-1] && visited[i - 1] == 0)  continue;
            if (visited[i] == 1) continue;
            visited[i] = 1;
            temp.append(chars[i]);
            backtrack(chars, index + 1);
            visited[i] = 0;
            temp.deleteCharAt(index);          
        }
    }
}
```

