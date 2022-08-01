# New

语法：

```javascript
new constructor[[arguments]]();
```

```javascript
function _new(constructor, ...args) {
    // 1. 创建对象
    const obj = {};
    // 2. 为新对象添加属性__proto__，将该属性链接至构造函数的原型对象
    obj.__proto__ = constructor.prototype;
    // 3. 执行构造函数，this被绑定在新对象上
    const res = constructor.apply(obj, args);
    // 4. 确保返回一个对象
    return res instanceof Object ? res : obj;
}

function Human(age, sex, bloodType) {
    this.age = age;
    this.sex = sex;
    this.bloodType = bloodType;
}
let man = _new(Human, 20, "male", "A");
console.log(man);
```
