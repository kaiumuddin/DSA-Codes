const print_staires = (n, ans = "") => {
    if (n < 0) return;
    if (n === 0) {
        console.log(ans);
        return;
    };

    print_staires(n - 1, ans + '1');
    print_staires(n - 2, ans + '2');
    print_staires(n - 3, ans + '3');
};

const n = 3;
print_staires(n);