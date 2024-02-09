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



// console.log(gridTravelar(1, 1));
// console.log(gridTravelar(2, 3));
// console.log(gridTravelar(3, 2));
console.log(gridTravelar(2, 1));
// console.log(gridTravelar(18, 18));
console.log(memo);