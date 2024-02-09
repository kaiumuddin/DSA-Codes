const toh = (n, src, des, hlp) => {
    if (n === 0) return;

    toh(n - 1, src, hlp, des); // move n-1 from src to hlp
    console.log(n + " [" + src + " -> " + des + "]");
    toh(n - 1, hlp, des, src); // bring back n-1 from hlp to des
};

toh(3, "A", "B", "C"); 
