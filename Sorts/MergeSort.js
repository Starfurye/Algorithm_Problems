const sort = (arr) => {
    const mergeSort = (left, right) => {
        // 终止条件
        if (left >= right) return;
        // 分解
        const mid = Math.floor((right - left) / 2 + left);
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        // 合并
        for (let i = left; i <= right; i++) {
            // 保留原数组
            tempArr[i] = arr[i];
        }
        let [i, j] = [left, mid + 1]; // 左右数组的指针
        for (let k = left; k <= right; k++) {
            if (i === mid + 1) {
                // 左边数组归并完毕，归并右边数组剩余部分
                arr[k] = tempArr[j++];
            } else if (j === right + 1 || tempArr[i] <= tempArr[j]) {
                // 右边数组归并完毕或左指针所指的数小于右指针所指的数
                arr[k] = tempArr[i++];
            } else {
                // 左指针所指的数大于右指针所指的数
                arr[k] = tempArr[j++];
            }
        }
    };

    const tempArr = new Array(arr.length); // 临时空间
    mergeSort(0, arr.length - 1);
};

console.log(sort([]));
