const print_subs = (str, ans) => {

    if (str.length === 0) {
        console.log(ans);
        return;
    }

    print_subs(str.substring(1), ans + "-");
    print_subs(str.substring(1), ans + str[0]);
};

print_subs("ABC", "");