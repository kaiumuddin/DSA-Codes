
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

// curr 
const kpce = (str) => {
    if (str.length === 0) return [""];

    const curr = parseInt(str[0]);

    const ans = [];
    for (let code of codes[curr]) {
        ans.push(code);
    }

    return ans;
};

console.log(kpce("2"));

///////////////////////////////////////////
// curr + child
const kpc = (str) => {
    if (str.length === 0) return [""];

    const curr = parseInt(str[0]);

    const childs = kpc(str.slice(1));

    const ans = [];
    for (let code of codes[curr]) {
        for (let child of childs) {
            ans.push(code + child);
        }
    }

    return ans;
};

console.log(kpc(""));

