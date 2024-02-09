const ncr = (str, r, start = 0, rtaken = 0, ans = "") => {
    if (rtaken === r) {
        console.log(ans);
        return;
    }

    for (let i = start;i < str.length;i++) {

        ncr(str, r, i + 1, rtaken + 1, ans + str[i]);
    }
};


// ncr(unique('abcabc'), 2);
ncr(('abb'), 2);
// ncr(('aabbbccdde'), 3);
// ncr(('aabbac'), 3);

// aabbbccdde;
// 3;
// aab;
// aac;
// aad;
// aae;
// abb;
// abc;
// abd;
// abe;
// acc;
// acd;
// ace;
// add;
// ade;
// bbb;
// bbc;
// bbd;
// bbe;
// bcc;
// bcd;
// bce;
// bdd;
// bde;
// ccd;
// cce;
// cdd;
// cde;
// dde;
