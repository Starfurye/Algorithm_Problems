# instanceof

语法：

```javascript
object instanceof constructor;
```

```javascript
function _instanceof(object, constructor) {
    let prototype = object.__proto__;
    while (true) {
        if (prototype === null) return false;
        else if (prototype === constructor.prototype) return true;
        prototype = prototype.__proto__;
    }
}

class Human {
    constructor(age, sex, bloodType) {
        this.age = age;
        this.sex = sex;
        this.bloodType = bloodType;
    }
}
class Man extends Human {
    constructor(age, sex, bloodType, name) {
        super(age, sex, bloodType);
        this.name = name;
    }
}
class Boy extends Man {
    constructor(age, sex, bloodType, name, toy) {
        super(age, sex, bloodType, name);
        this.toy = toy;
    }
}
let human = new Human(20, "male", "A");
let man = new Man(21, "male", "B", "Jack");
let boy = new Boy(18, "male", "O", "Bob", "sword");
console.log(human);
// Human { age: 20, sex: 'male', bloodType: 'A' }
console.log(man);
// Man { age: 21, sex: 'male', bloodType: 'B', name: 'Jack' }
console.log(boy);
// Boy { age: 18, sex: 'male', bloodType: 'O', name: 'Bob', toy: 'sword' }
console.log("boy instanceof Boy: " + _instanceof(boy, Boy));
// boy instanceof Boy: true
console.log("boy instanceof Man: " + _instanceof(boy, Man));
// boy instanceof Man: true
console.log("boy instanceof Human: " + _instanceof(boy, Human));
// boy instanceof Human: true
console.log("man instanceof Boy: " + _instanceof(man, Boy));
// man instanceof Boy: false
console.log("human instanceof Object: " + _instanceof(human, Object));
// human instanceof Object: true
console.log("boy instanceof Object: " + _instanceof(boy, Object));
// boy instanceof Object: true
```
