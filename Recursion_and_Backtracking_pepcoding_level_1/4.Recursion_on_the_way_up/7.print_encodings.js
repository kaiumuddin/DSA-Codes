const print_encodings = (str, ans = "") => {
    if (str.length === 0) {
        console.log(ans);
        return;
    } else if (str.length === 1) {
        const ch = str[0];

        if (ch === '0') {
            return;
        } else {
            const letter = String.fromCharCode(96 + parseInt(str[0]));
            console.log(ans + letter);
            return;
        }
    } else {
        const ch = str[0];

        if (ch === '0') {
            return;
        } else {
            const letter = String.fromCharCode(96 + parseInt(str[0]));
            print_encodings(str.slice(1), ans + letter);
        }

        const ch12 = str.slice(0, 2);
        if (parseInt(ch12) <= 26) {
            const letter = String.fromCharCode(96 + parseInt(ch12));
            print_encodings(str.slice(2), ans + letter);
        }
    }



};

print_encodings("132");