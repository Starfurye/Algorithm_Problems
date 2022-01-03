# 剑指 Offer 59 - II. 队列的最大值

请定义一个队列并实现函数 `max_value` 得到队列里的最大值，要求函数`max_value`、`push_back` 和 `pop_front` 的**均摊**时间复杂度都是 O(1)。

若队列为空，`pop_front` 和 `max_value` 需要返回 -1

示例 1：

```
输入:
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
```

示例 2：

```
输入:
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
```

限制：

-   1 <= push_back,pop_front,max_value 的总操作数  <= 10000
-   1 <= value <= 10^5

## Solution

### 双端队列

使用一个双端队列 `deque`，在每次入队时，如果 `deque` 队尾元素小于即将入队的元素 `value`，则将小于 `value` 的元素全部出队后，再将 `value` 入队；否则直接入队。

```js
var MaxQueue = function () {
    this.q = [];
    this.maxq = [];
};

/**
 * @return {number}
 */
MaxQueue.prototype.max_value = function () {
    return this.maxq.length == 0 ? -1 : this.maxq[0];
};

/**
 * @param {number} value
 * @return {void}
 */
MaxQueue.prototype.push_back = function (value) {
    this.q.push(value);
    while (this.maxq.length && this.maxq[this.maxq.length - 1] < value) {
        this.maxq.pop();
    }
    this.maxq.push(value);
};

/**
 * @return {number}
 */
MaxQueue.prototype.pop_front = function () {
    if (this.q.length == 0) return -1;
    if (this.q[0] == this.maxq[0]) this.maxq.shift();
    return this.q.shift();
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * var obj = new MaxQueue()
 * var param_1 = obj.max_value()
 * obj.push_back(value)
 * var param_3 = obj.pop_front()
 */
```
