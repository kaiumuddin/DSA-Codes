// total substring  = n*(n+1)/2
// total subsequence = 2^n


const get_paths = (sr, sc, dr, dc) => {

    if (sr === dr && sc === dc) return [''];

    if (sr > dr || sc > dc) return [];

    const hpaths = get_paths(sr, sc + 1, dr, dc);
    const vpaths = get_paths(sr + 1, sc, dr, dc);

    // const hpaths = sc < dc ? get_paths(sr, sc + 1, dr, dc) : [];
    // const vpaths = sr < dr ? get_paths(sr + 1, sc, dr, dc) : [];

    const ans = [];

    for (let hpath of hpaths) {
        ans.push("h" + hpath);
    }

    for (let vpath of vpaths) {
        ans.push("v" + vpath);
    }

    return ans;

};

console.log(get_paths(1, 1, 3, 3));

////////////////////////////////////////////


