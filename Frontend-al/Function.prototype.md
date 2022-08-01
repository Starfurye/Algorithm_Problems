# Function.prototype

## apply

语法：

```javascript
func.apply(thisArg, [argsArray]);
```

### 浏览器版

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Document</title>
    </head>
    <body>
        <script>
            Function.prototype._apply = function (thisArg, argsArray) {
                if (typeof this !== "function") {
                    throw new TypeError(
                        "Function.protype.apply was called on which is not a function"
                    );
                }

                thisArg = !!!thisArg ? window : Object(thisArg);

                const func = Symbol("func");
                thisArg[func] = this;

                let result;
                if (argsArray.length) {
                    result = thisArg[func](...Array.from(argsArray));
                } else {
                    result = thisArg[func]();
                }
                delete thisArg[func];

                return result;
            };

            let arr = [1, 2, 4, 5, 7, 9, 11, 12, 15, 19];
            console.log(Math.max._apply(null, arr));
            // 19
        </script>
    </body>
</html>
```

### Node 版

Node 没有 `window` 变量，但有一个等价的 `global` 变量。

```javascript
Function.prototype._apply = function (thisArg, argsArray) {
    if (typeof this !== "function") {
        throw new TypeError(
            "Function.protype.apply was called on which is not a function"
        );
    }

    thisArg = !!!thisArg ? global : Object(thisArg);

    const func = Symbol("func");
    thisArg[func] = this;

    let result;
    if (argsArray.length) {
        result = thisArg[func](...Array.from(argsArray));
    } else {
        result = thisArg[func]();
    }
    delete thisArg[func];

    return result;
};

let arr = [1, 2, 4, 5, 7, 9, 11, 12, 15, 19];
console.log(Math.max._apply(null, arr));
// 19
```

## call

语法：

```javascript
function.call(thisArg, arg1, arg2, ...)
```

```javascript
Function.prototype._call = function (thisArg, ...argsArray) {
    // 注意参数
    if (typeof this !== "function") {
        throw new TypeError(
            "Function.protype.call was called on which is not a function"
        );
    }

    // thisArg = !!!thisArg ? window : Object(thisArg); => for browser
    thisArg = !!!thisArg ? global : Object(thisArg);

    const func = Symbol("func");
    thisArg[func] = this;

    let result;
    if (argsArray.length) {
        result = thisArg[func](...Array.from(argsArray));
    } else {
        result = thisArg[func]();
    }
    delete thisArg[func];

    return result;
};
let arr = [1, 2, 4, 5, 7, 9, 11, 12, 15, 19];
console.log(Math.max._call(null, ...arr));
```

## bind

语法：

```javascript
function.bind(thisArg[, arg1[, arg2[, ...]]]);
```

```javascript
Function.prototype._bind = function (thisArg, ...argsArray) {
    if (typeof this !== "function") {
        throw new TypeError(
            "Function.protype.bind was called on which is not a function"
        );
    }

    // thisArg = !!!thisArg ? window : Object(thisArg)
    thisArg = !!!thisArg ? global : Object(thisArg);
    const func = this;
    const bound = function (...boundArgsArray) {
        let isNew = false;
        try {
            isNew = this instanceof func;
        } catch (err) {}
        return func.apply(
            isNew ? this : thisArg,
            argsArray.concat(boundArgsArray)
        );
    };
    const F = function () {};
    F.prototype = this.prototype;
    bound.prototype = new F();
    return bound;
};
console.log._bind(console, 41)(43, 44, 45);
```
