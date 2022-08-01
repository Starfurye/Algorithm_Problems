# Array.prototype

## filter

语法：

```javascript
let newArray = arr.filter(callback(element[, index[, array]])[, thisArg])
```

```javascript
Array.prototype._filter = function (cb, thisArg) {
    if (!!!this || this.length === 0 || typeof cb !== "function") {
        throw new TypeError("type error");
    }

    const res = [];
    for (let i = 0; i < this.length; i++) {
        if (cb.call(thisArg, this[i], i, this)) {
            res.push(this[i]);
        }
    }
    return res;
};
let arr = [1, 2, 4, 5, 7, 9, 11, 12, 15, 19];
console.log(arr._filter((item) => item % 2 === 0));
// [ 2, 4, 12 ]
```

## map

语法：

```javascript
let new_array = arr.map(function callback(currentValue[, index[, array]]) {
 // Return element for new_array
}[, thisArg])
```

```javascript
Array.prototype._map = function (cb, thisArg) {
    if (!!!this || this.length === 0 || typeof cb !== "function") {
        throw new TypeError("type error");
    }

    const res = [];
    for (let i = 0; i < this.length; i++) {
        res.push(cb.call(thisArg, this[i], i, this));
    }
    return res;
};

let arr = [1, 2, 4, 5, 7, 9, 11, 12, 15, 19];
console.log(arr._map((item) => item % 2));
// [ 1, 0, 0, 1, 1, 1, 1, 0, 1, 1]
```

## forEach

和 map 的区别是没有返回值，forEach 不会改变原数组的值。

语法：

```javascript
arr.forEach(callback(currentValue [, index [, array]])[, thisArg])
```

```javascript
Array.prototype._forEach = function (cb, thisArg) {
    if (!!!this || this.length === 0 || typeof cb !== "function") {
        throw new TypeError("type error");
    }

    for (let i = 0; i < this.length; i++) {
        cb.call(thisArg, this[i], i, this);
    }
};
let arr = [1, 2, 4, 5, 7, 9, 11, 12, 15, 19];
arr._forEach((item) => {
    item = item - 1;
});
console.log(arr);
// [ 1, 2, 4, 5, 7, 9, 11, 12, 15, 19 ]
```

## reduce

语法：

```javascript
arr.reduce(callback(previousValue, currentValue [, currentIndex [, array]])[, initialValue])
```

```javascript
Array.prototype._reduce = function (cb, initialValue) {
    if (!!!this || this.length === 0 || typeof cb !== "function") {
        throw new TypeError("type error");
    }

    let sum = initialValue === undefined ? this[0] : initialValue;
    for (let i = 1; i < this.length; i++) {
        sum = cb.call(undefined, sum, this[i], i, this);
    }
    return sum;
};

let arr = [1, 2, 4, 5, 7, 9, 11, 12, 15, 19];
console.log(arr._reduce((prev, cur) => prev + cur));
// 85
```
