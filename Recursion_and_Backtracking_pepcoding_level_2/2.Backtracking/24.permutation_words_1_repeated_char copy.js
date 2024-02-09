const permutation = (str) => {
    const fmap = {};
    for (let ch of str) {
        if (ch in fmap) {
            fmap[ch]++;
        } else {
            fmap[ch] = 1;
        }
    }


    const _permutation = (rtaken = 0, r, asf = "") => {
        if (rtaken === r) {
            console.log(asf);
            return;
        }

        for (let key in fmap) {
            if (fmap[key] > 0) {
                fmap[key]--;
                _permutation(rtaken + 1, r, asf + key);
                fmap[key]++;
            }
        }


    };

    _permutation(0, str.length, "");


};

permutation("aabb");
console.log("");
permutation("abc");