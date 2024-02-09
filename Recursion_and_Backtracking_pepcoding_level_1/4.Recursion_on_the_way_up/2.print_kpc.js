
const codes = [
    ".;",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tu",
    "vwx",
    "yz"
];

///////////////////////////////////////////

// const kpc = (str = "", ans = "") => {

//     if (str.length === 0) {
//         console.log(ans);
//         return;
//     }

//     const ch = parseInt(str[0]);
//     const roq = str.slice(1);


//     const codeforch = codes[ch];
//     for (let i = 0;i < codeforch.length;i++) {
//         const cho = codeforch[i];
//         kpc(roq, ans + cho);
//     }

// };

// kpc("123");


const kpc = (str = "", ans = "") => {

    if (str.length === 0) {
        console.log(ans);
        return;
    }

    for (let i = 0;i < codes[str[0]].length;i++) {
        kpc(str.slice(1), ans + codes[str[0]][i]);
    }

};

kpc("12");

