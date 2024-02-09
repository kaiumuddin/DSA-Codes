const taken = new Set();
const ans = new Set();

var npr = (n, r, rtaken = 0, ansf = "") => {
    if (rtaken === r) {
        // console.log(ansf);
        ans.add(ansf);
        return;
    }

    for (let i = 0;i < n.length;i++) {
        if (!taken.has(i)) {
            taken.add(i);
            npr(n, r, rtaken + 1, ansf + n[i]);
            taken.delete(i);
        }
    }
};

// npr("aabb", 4);
npr("0011", 4);
console.log(ans);


/////////////////////////////////////////////////////////////




var npr = (str, r) => {

    const fmap = {};
    for (c of str) {
        if (c in fmap) fmap[c]++;
        else fmap[c] = 1;
    };

    const _npr = (curr_spot = 0, total_spot, asf = "") => {
        if (curr_spot >= total_spot) {
            console.log(asf);
            return;
        }

        for (let c in fmap) {
            if (fmap[c] > 0) {
                fmap[c]--;
                _npr(curr_spot + 1, total_spot, asf + c);
                fmap[c]++;
            }
        }

    };

    _npr(0, r, "");

};

// npr("aabb", 4);
// npr("abab", 4);
npr("abc", 3);

