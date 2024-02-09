// Javascript Object 

const a = {};

a[0] = 5;
a[4] = 6;
a.kaium = 8;
a["kaium"] = 9;
console.log(a);
console.log( 0 in a);

delete a[0];
console.log(a);







// Javascipt Array
const b = [];
b[0] = 4;
b[3] = 4;
console.log(b);
console.log(3 in b);

delete b[3];
console.log(b);










// Fibonacci

// Brute Force
// const fib = (n) => {
//     if(n <=2 ) return 1;
//     return fib(n-1) + fib(n-2);
// }

// Memoization
const fib = (n, memo = {}) => {
    if (n in memo) return memo[n];
    if (n <=2 ) return 1;
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

console.log(fib(5));
console.log(fib(7));
console.log(fib(8));
console.log(fib(50));

// 0 ,1, 2, 3, 4, 5
// 0, 1, 1, 2, 3, 5








// grid Travelar

console.clear();

//Brute Force
// const gridTravelar = (m, n) => {
//     if(m===1 && n===1) return 1;
//     if(m===0 || n===0) return 0;
//     return gridTravelar(m-1, n) + gridTravelar(m, n-1);
// }


// Memoization
// const gridTravelar = (m, n, memo={}) => {
//     const key = m + ',' + n;

//     if(key in memo) return memo[key];
//     if(m===1 && n===1) return 1;
//     if(m===0 || n===0) return 0;
//     memo[key] = gridTravelar(m-1, n, memo) + gridTravelar(m, n-1, memo);
//     return memo[key];
// }
memo = {};
const gridTravelar = (m, n) => {
    const key = m + ',' + n;

    if(key in memo) return memo[key];
    if(m===1 && n===1) return 1;
    if(m===0 || n===0) return 0;
    memo[key] = gridTravelar(m-1, n) + gridTravelar(m, n-1);
    return memo[key];
}

console.log(gridTravelar(1, 1));
console.log(gridTravelar(2, 3));
console.log(gridTravelar(3, 2));
console.log(gridTravelar(3, 3));
console.log(gridTravelar(18, 18));
console.log(memo);
// const key = 1 + ',' + 1;
// const obj = {};
// obj[1+','+1] = 1;
// obj[key] = 1;
// console.log(obj);
// console.log(key in obj);







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

const canSum = (targetSum, numbers, memo = []) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return true;
    if (targetSum < 0) return false;

    for(let num of numbers){
        const remainder = targetSum - num;
        if (canSum(remainder, numbers, memo) === true){
            memo[targetSum] = true;
            return true;
        }
    }

    memo[targetSum] = false;
    return false;
};

console.log(canSum(7, [2,3]));
console.log(canSum(7, [5,3,4,7]));
console.log(canSum(7, [2,4]));
console.log(canSum(8, [2,3,5]));
console.log(canSum(300, [7,14]));
