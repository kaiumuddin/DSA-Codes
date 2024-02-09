const print_increasing = (n) => {
    if (n === 0) return;
    print_increasing(n - 1); // Faith
    console.log(n); // expectation
};

print_increasing(5);

// Expectation;
// p(5) => 5 4 3 2 1 print krbe;

// Faith;
// p(4) => 4 3 2 1 print krbe;

// Faith + Expectation;
// p(5) => p(4) print krbe
//     => sathe 5 o print krbe;