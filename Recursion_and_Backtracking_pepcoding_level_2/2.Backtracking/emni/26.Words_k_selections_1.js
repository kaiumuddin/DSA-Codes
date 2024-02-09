const ncr = (str, r, start = 0, rtaken = 0, ans = "") => {
    if (rtaken === r) {
        console.log(ans);
        return;
    }

    for (let i = start;i < str.length;i++) {
        if (i > 0 && str[i - 1] === str[i]) {
            continue;
        };
        ncr(str, r, i + 1, rtaken + 1, ans + str[i]);
    }
};


ncr('aabbbccdde', 3);


// aabbbccdde;
// 3;
// abc;
// abd;
// abe;
// acd;
// ace;
// ade;
// bcd;
// bce;
// bde;
// cde;