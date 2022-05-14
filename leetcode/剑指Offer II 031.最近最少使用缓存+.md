# 剑指 Offer II 031. 最近最少使用缓存

运用所掌握的数据结构，设计和实现一个 [LRU (Least Recently Used，最近最少使用)](https://baike.baidu.com/item/LRU) 缓存机制 。

实现 LRUCache 类：

-   `LRUCache(int capacity)` 以正整数作为容量 `capacity` 初始化 LRU 缓存
-   `int get(int key)` 如果关键字 `key` 存在于缓存中，则返回关键字的值，否则返回 `-1` 。
-   `void put(int key, int value)` 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

示例：

```
输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
```

**提示：**

-   `1 <= capacity <= 3000`
-   `0 <= key <= 10000`
-   `0 <= value <= 10^5`
-   最多调用 `2 * 10^5` 次 `get` 和 `put`

**进阶：** 是否可以在 `O(1)` 时间复杂度内完成这两种操作？

注意：本题与主站 146 题相同：https://leetcode-cn.com/problems/lru-cache/

## Solution

```javascript
/**
 * @param {number} key
 * @param {number} value
 */
var DBNode = function (key = -1, value = 0) {
    this.key = key;
    this.value = value;
    this.prev = null;
    this.next = null;
};

/**
 * @param {number} capacity
 */
var LRUCache = function (capacity) {
    this.map = new Map();
    this.head = new DBNode();
    this.tail = new DBNode();
    this.head.next = this.tail;
    this.tail.prev = this.head;
    this.capacity = capacity;
    this.size = 0;
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function (key) {
    if (!this.map.has(key)) return -1;
    let node = this.map.get(key);
    this.moveToHead(node);
    return node.value;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function (key, value) {
    if (!this.map.has(key)) {
        let node = new DBNode(key, value);
        this.addAtFirst(node);
        this.map.set(key, node);
        this.size++;
        if (this.size > this.capacity) {
            let temp = this.removeAtEnd();
            this.map.delete(temp.key);
            this.size--;
        }
    } else {
        let node = this.map.get(key);
        node.value = value;
        this.moveToHead(node);
    }
};

/**
 * @param {DBNode} node
 * @return {void}
 */
LRUCache.prototype.addAtFirst = function (node) {
    node.next = this.head.next;
    node.prev = this.head;
    this.head.next.prev = node;
    this.head.next = node;
};

/**
 * @return {Node}
 */
LRUCache.prototype.removeAtEnd = function () {
    let node = this.tail.prev;
    node.prev.next = this.tail;
    this.tail.prev = node.prev;
    return node;
};

/**
 * @param {DBNode} node
 * @return {void}
 */
LRUCache.prototype.moveToHead = function (node) {
    node.next.prev = node.prev;
    node.prev.next = node.next;
    this.addAtFirst(node);
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```
