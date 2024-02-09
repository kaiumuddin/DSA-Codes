console.clear();

// CanSum Problem

// Brute Force

// const canSum = (targetSum, numbers) => {
//     if (targetSum === 0) return true;
//     if (targetSum < 0) return false;

//     for(let num of numbers){
//         const remainder = targetSum - num;
//         if (canSum(remainder, numbers) === true){
//             return true;
//         }
//     }

//     return false;
// };


// Memoization

// const canSum = (targetSum, numbers, memo = []) => {
//     if (targetSum in memo) return memo[targetSum];
//     if (targetSum === 0) return true;
//     if (targetSum < 0) return false;

//     for(let num of numbers){
//         const remainder = targetSum - num;
//         if (canSum(remainder, numbers, memo) === true){
//             memo[targetSum] = true;
//             return true;
//         }
//     }

//     memo[targetSum] = false;
//     return false;
// };


// console.log(canSum(7, [2,3]));
// console.log(canSum(7, [5,3,4,7]));
// console.log(canSum(7, [2,4]));
// console.log(canSum(8, [2,3,5]));
// console.log(canSum(300, [7,14]));

memo = {}
const canSum = (targetSum, numbers) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return true;
    if (targetSum < 0) return false;

    for(let num of numbers){
        const remainder = targetSum - num;
        if (canSum(remainder, numbers) === true){
            memo[targetSum] = true;
            return true;
        }
    }

    memo[targetSum] = false;
    return false;
};

console.log(canSum(7, [2,3]));
console.log(memo);