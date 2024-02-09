var ncr = (n, r, curri = 1, rtaken = 0, ansf = "") => {
    if (rtaken === r) {
        console.log(ansf);
        return;
    }

    for (let i = curri;i <= n;i++) {
        ncr(n, r, i + 1, rtaken + 1, ansf + i);
    }
};

ncr(3, 3);


///////////////////////////////////////////////////////

var ncr = (n, r, curri = 0, ansf = "") => {
    if (r < 0) return;
    if (r === 0) {
        console.log(ansf);
        return;
    }

    for (let i = curri;i < n.length;i++) {
        ncr(n, r - n[i], i + 1, ansf + n[i] + ',');
    }
};

ncr([1, 2, 3, 4], 6);


var ncr = (n, r, curri = 0, ansf = "") => {
    if (r < 0 || curri > n.length) return;
    if (r === 0) {
        console.log(ansf);
        return;
    }

    ncr(n, r - n[curri], curri + 1, ansf + n[curri] + ',');
    ncr(n, r, curri + 1, ansf);
};

ncr([1, 2, 3, 4], 6)


