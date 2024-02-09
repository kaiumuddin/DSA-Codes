const max_in_arr = (arr, i = 0) => {
    if (i === arr.length - 1) return arr[i];

    const child = max_in_arr(arr, i + 1);
    return Math.max(arr[i], child);
};

console.log(max_in_arr([-5, 34, 342, 34234, 32]));

// E
// max of( 0 to n)

// F
// max of( 1 to n)

// F + E
// max of (0 , 1 to n)