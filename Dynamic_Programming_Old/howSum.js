// arr = [1,2,3];
// console.log(arr);
// arr = [...arr, 5];
// console.log(arr);

// arr.push(9);
// console.log(arr);




// console.clear();
// m = 2;
// n = 16;
// r = ()=> 2;
// arr = Array(m).fill(Array(n).fill(4));

// console.log(arr);


// for(i of arr){
//     console.log(JSON.stringify(i));
// }

const howSum = (targetSum, numbers, memo = {}) => {
    if(targetSum in memo) return memo[targetSum];
    if(targetSum === 0) return [];
    if(targetSum <0) return null;

    for(let num of numbers) {
        const remainder  = targetSum - num;
        const remainderResult = howSum(remainder, numbers, memo);

        if(remainderResult != null) {
            memo[targetSum] = [...remainderResult, num];
            return memo[targetSum];
        }
    }

    memo[targetSum] = null;
    return null;
}

console.clear();
console.log(howSum(7, [2, 3]));
console.log(howSum(7, [5,3,4,7]));
console.log(howSum(7, [2,4]));
console.log(howSum(8, [2,3,5]));
console.log(howSum(300, [7,14]));