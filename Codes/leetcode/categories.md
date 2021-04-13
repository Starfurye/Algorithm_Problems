# 分类

## DA-单调栈

42-接雨水

## DO-动态规划

1143-最长公共子序列

## ERC-二叉树的遍历

530-二叉搜索树的最小绝对差、783-二叉搜索树节点最小距离

## ERF-二分法

二分法基本框架：

```java
int binarySearch(int[] nums, int target) {
    int left = 0, right = ...;

    while(...) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ...
        } else if (nums[mid] < target) {
            left = ...
        } else if (nums[mid] > target) {
            right = ...
        }
    }
    return ...;
}
```

### 找一个数

```java
int binarySearch(int[] nums, int target) {
    int left = 0; 
    int right = nums.length - 1; // 注意

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid; 
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
    }
    return -1;
}
/*
因为我们初始化 right = nums.length - 1
所以决定了我们的「搜索区间」是 [left, right]
所以决定了 while (left <= right)
同时也决定了 left = mid+1 和 right = mid-1

因为我们只需找到一个 target 的索引即可
所以当 nums[mid] == target 时可以立即返回
*/
```

 ### 找左侧边界

```java
int left_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0;
    int right = nums.length; // 注意
    
    while (left < right) { // 注意
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意
        }
    }
    return left;
}
/*
因为我们初始化 right = nums.length
所以决定了我们的「搜索区间」是 [left, right)
所以决定了 while (left < right)
同时也决定了 left = mid + 1 和 right = mid

因为我们需找到 target 的最左侧索引
所以当 nums[mid] == target 时不要立即返回
而要收紧右侧边界以锁定左侧边界
*/
```

注意`left = mid + 1`和`right = mid`是由于`right = nums.length`，为左闭右开区间，比完mid后要去掉。

### 找右侧边界

```java
int right_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0, right = nums.length;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // 注意
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    return left - 1; // 注意
}
/*
因为我们初始化 right = nums.length
所以决定了我们的「搜索区间」是 [left, right)
所以决定了 while (left < right)
同时也决定了 left = mid + 1 和 right = mid

因为我们需找到 target 的最右侧索引
所以当 nums[mid] == target 时不要立即返回
而要收紧左侧边界以锁定右侧边界

又因为收紧左侧边界时必须 left = mid + 1
所以最后无论返回 left 还是 right，必须减一
*/
```

33-搜索旋转排序数组、34-在排序数组中查找元素的第一个和最后一个位置、35-搜索插入位置、69-x 的平方根、81-搜索旋转排序数组II、153-寻找旋转排序数组中的最小值、275. H 指数 II、633-平方数之和、704-二分查找、852. 山脉数组的峰顶索引、1095-山脉数组中查找目标值

## H-回溯法

```java
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }
    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```

| 类型       | 题目                                                         |
| ---------- | ------------------------------------------------------------ |
| 子集、组合 | 39-组合总和、40-组合总和II、77-组合、78-子集、90-子集II      |
| 全排列     | 46-全排列、47-全排列II、剑指 Offer 38. 字符串的排列、784-字母大小写全排列 |
| **搜索**   | 37-解数独、79-单词搜索、131-分割回文串                       |

## P-偏移量数组

79-单词搜索

## S-双指针

658-找到 K 个最接近的元素

## Z-栈模拟

150-逆波兰表达式求值、224-基本计算器、225-基本计算器II、1006-笨阶乘

