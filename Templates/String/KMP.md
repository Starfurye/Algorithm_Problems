# KMP

## javascript

```javascript
function buildNext() {
    next.push(0);
    let i = 1,
        now = 0;
    while (i < p.length) {
        if (p[now] == p[i]) {
            now++;
            i++;
            next.push(now);
        } else if (now > 0) {
            now = next[now - 1];
        } else {
            next.push(0);
            i++;
        }
    }
}
function match() {
    let pS = 0,
        pP = 0;
    while (pS < s.length) {
        if (s[pS] == p[pP]) {
            pS++;
            pP++;
        } else if (pP > 0) {
            // 不匹配，若不在第一个位置则需要根据next数组移动
            pP = next[pP - 1];
        } else pS++; // 在第一个位置不匹配

        if (pP == p.length) {
            console.log(pS - pP);
            pP = next[pP - 1];
        }
    }
}

let s = "AlgoAtrithm";
let p = "Atri";
let next = [];

buildNext();
match();
```

## python

```python
s = input().strip()
p = input().strip() # 模式串
next = []

def buildNext():
    next.append(0)

    i = 1
    now = 0
    while i < len(p):
        if p[now] == p[i]:
            now += 1
            i += 1
            next.append(now)
        elif now > 0:
            now = next[now - 1]
        else:
            next.append(0)
            i += 1

def match():
    pS = 0
    pP = 0
    while pS < len(s):
        if s[pS] == p[pP]:
            pS += 1
            pP += 1
        elif pP > 0:        # 不匹配，若不在第一个位置则需要根据next数组移动
            pP = next[pP - 1]
        else:
            pS += 1         # 在第一个位置不匹配

        if pP == len(p):
            print(pS - pP + 1)
            pP = next[pP - 1]

buildNext()
match()
```
