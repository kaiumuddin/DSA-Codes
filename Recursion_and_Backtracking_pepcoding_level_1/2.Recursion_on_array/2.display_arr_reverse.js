const display_arr = (arr, i = 0) => {
    if (i === arr.length) return;

    display_arr(arr, i + 1);
    console.log(arr[i]);
};

console.log(display_arr([-5, 34, 342, 34234, 32]));

// E
// n to 0

// F
// n to 1

// F + E
// n to 1, 0