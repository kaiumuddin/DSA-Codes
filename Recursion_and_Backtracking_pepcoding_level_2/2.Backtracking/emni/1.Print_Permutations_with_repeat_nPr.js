var npr = (n, r, curri = 1, rtaken = 0, ansf = "") => {
    if (rtaken === r) {
        console.log(ansf);
        return;
    }

    for (let i = 1;i <= n;i++) {
        npr(n, r, i, rtaken + 1, ansf + i);
    }
};

npr(3, 2);


///////////////////////////////////////////////////////

var npr = (n, r, curri = 0, ansf = "") => {
    if (r < 0) return;
    if (r === 0) {
        console.log(ansf);
        return;
    }

    for (let i = 0;i < n.length;i++) {
        npr(n, r - n[i], i + 1, ansf + n[i] + ' ');
    }
};

// npr([1, 2, 3, 4], 4);
