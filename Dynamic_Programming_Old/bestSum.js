// const bestSum = (targetSum, numbers) => {
//     if(targetSum === 0) return [];
//     if(targetSum < 0) return null;

//     let shortestCombination = null;

//     for(let num of numbers){
//         const remainder = targetSum - num;
//         const remainderCombination = bestSum(remainder, numbers);
//         if(remainderCombination !== null){
//             const combination = [...remainderCombination, num];
//             if(shortestCombination === null || combination.length < shortestCombination.length){
//                 shortestCombination = combination;
//             }
//         }
//     }
//     return shortestCombination;
// }

// // m = taargetSum
// // n = numbers.length

// // Brute Force
// // time: O(n^m * m)
// // space: O(m^2)



// console.clear();
// console.log(bestSum(7, [5, 3, 4, 7]));
// console.log(bestSum(8, [2, 3, 5]));
// console.log(bestSum(8, [1, 4, 5]));
// console.log(bestSum(4, [2, 4]));
// //console.log(bestSum(100, [1, 2, 5, 25]));


// Memoiozation
const bestSum = (targetSum, numbers, memo={}) => {
    if(targetSum in memo) return memo[targetSum];
    if(targetSum === 0) return [];
    if(targetSum < 0) return null;

    let shortestCombination = null;

    for(let num of numbers){
        const remainder = targetSum - num;
        const remainderCombination = bestSum(remainder, numbers, memo);
        if(remainderCombination !== null){
            const combination = [...remainderCombination, num];
            if(shortestCombination === null || combination.length < shortestCombination.length){
                shortestCombination = combination;
            }
        }
    }
    memo[targetSum] = shortestCombination; 
    return shortestCombination;
}

// m = taargetSum
// n = numbers.length

// Memoize
// time: O(m * n * m)
// space: O(m^2)



console.clear();
console.log(bestSum(7, [5, 3, 4, 7]));
console.log(bestSum(8, [2, 3, 5]));
console.log(bestSum(8, [1, 4, 5]));
console.log(bestSum(4, [2, 4]));
console.log(bestSum(100, [1, 2, 5, 25]));