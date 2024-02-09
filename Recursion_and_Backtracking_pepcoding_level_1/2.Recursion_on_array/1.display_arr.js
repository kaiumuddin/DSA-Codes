const display_arr = (arr, i = 0) => {
    if (i === arr.length) return;

    console.log(arr[i]);
    display_arr(arr, i + 1);
};

console.log(display_arr([-5, 34, 342, 34234, 32]));

// E
// 0 to  n

// F
// 1 to n

// F + E
// 0 + 1 to n