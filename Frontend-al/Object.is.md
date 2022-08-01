# Object.is

`Object.is()` 方法判断两个值是否为同一个值。

满足以下任意条件则两个值相等：

-   都是 undefined, null, true 或 false
-   都是相同长度、相同字符、按相同顺序排列的字符串
-   都是相同对象（意味着都是同一个对象的值引用）
-   都是数字且
    -   都是 +0
    -   都是 -0
    -   都是 NaN
    -   都是同一个值，非零且都不是 NaN

```js
if (!Object.is) {
    Object.defineProperty(Object, "is", {
        value: function (x, y) {
            // SameValue algorithm
            if (x === y) {
                // return true if x and y are not 0, OR
                // if x and y are both 0 of the same sign.
                // This checks for cases 1 and 2 above.
                return x !== 0 || 1 / x === 1 / y;
            } else {
                // return true if both x AND y evaluate to NaN.
                // The only possibility for a variable to not be strictly equal to itself
                // is when that variable evaluates to NaN (example: Number.NaN, 0/0, NaN).
                // This checks for case 3.
                return x !== x && y !== y;
            }
        },
    });
}
```
