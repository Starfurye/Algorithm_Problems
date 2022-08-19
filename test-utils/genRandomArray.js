const genRandom = require("./genRandom");

/**
 * @param {number} arrayLength
 * @return {number[]}
 */
function genRandomArray(arrayLength) {
    const resArray = [];
    for (let i = 0; i < arrayLength; i++) {
        resArray.push(genRandom("ingeger", { min: -128, max: 128 }));
    }
    return resArray;
}

console.log(genRandomArray(12));
