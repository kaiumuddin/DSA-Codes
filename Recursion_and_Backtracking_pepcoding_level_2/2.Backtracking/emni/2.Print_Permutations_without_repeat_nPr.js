const taken = new Set();

const npr = (n, r, rtaken = 0, ansf = "") => {
    if (rtaken === r) {
        console.log(ansf);
        return;
    }

    for (let i = 1;i <= n;i++) {
        if (!taken.has(i)) {
            taken.add(i);
            npr(n, r, rtaken + 1, ansf + i);
            taken.delete(i);
        }
    }
};

npr(3, 3);