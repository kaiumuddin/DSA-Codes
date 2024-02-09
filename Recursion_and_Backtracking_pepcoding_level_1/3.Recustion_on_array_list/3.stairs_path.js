// total substring  = n*(n+1)/2
// total subsequence = 2^n

const staires = (n) => {
    if (n === 0) return [""];
    if (n < 0) return [];

    const p1 = staires(n - 1);
    const p2 = staires(n - 2);
    const p3 = staires(n - 3);

    const ans = [];

    for (let p of p1) ans.push(1 + p);
    for (let p of p2) ans.push(2 + p);
    for (let p of p3) ans.push(3 + p);

    return ans;

};

const n = 3;
console.log(staires(n));

////////////////////////////////////////////

const staires2 = (n) => {
    if (n === 0) return [""];
    if (n < 0) return [];

    const curr1 = n - 1 >= 0 ? "1" : "";
    const curr2 = n - 2 >= 0 ? "2" : "";
    const curr3 = n - 3 >= 0 ? "3" : "";

    const child1 = staires2(n - 1);
    const child2 = staires2(n - 2);
    const child3 = staires2(n - 3);

    const ans = [];

    for (let child of child1) ans.push(curr1 + child);
    for (let child of child2) ans.push(curr2 + child);
    for (let child of child3) ans.push(curr3 + child);

    return ans;

};

console.log(staires2(n));

