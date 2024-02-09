const print_permutation = (str, ans = "") => {
    if (str.length === 0) console.log(ans);

    for (let i = 0;i < str.length;i++) {
        print_permutation(str.substr(0, i) + str.substr(i + 1), ans + str[i]);
    }
};

print_permutation("abc");