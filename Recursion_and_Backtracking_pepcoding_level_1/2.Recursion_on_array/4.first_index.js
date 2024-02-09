var first_index = (arr, target, i = 0) => {
    if (i === arr.length) return -1;
    let curr = target === arr[i] ? i : -1;
    if (curr != -1) return curr;
    curr = first_index(arr, target, i + 1);
    return curr;
};

console.log(first_index([-5, 34, 342, 34, 32], 5));

////////////////////////////

var first_index = (arr, target, i = 0) => {
    if (i === arr.length) return -1;

    let faith = first_index(arr, target, i + 1);
    return arr[i] == target ? i : faith;
};

console.log(first_index([-5, 34, 342, 34, 32], 342));

// E
// first of( 0 to n)

// F
// first of( 1 to n)

// F + E
// first of (0 , 1 to n)