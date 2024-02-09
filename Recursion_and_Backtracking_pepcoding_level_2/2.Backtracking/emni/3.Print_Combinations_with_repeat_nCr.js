const ncr = (n, r, curri = 1, rtaken = 0, ansf = "") => {
    if (rtaken === r) {
        console.log(ansf);
        return;
    }

    for (let i = curri;i <= n;i++) {
        ncr(n, r, i, rtaken + 1, ansf + i);
    }
};

ncr(3, 3);