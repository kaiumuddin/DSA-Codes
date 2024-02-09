const print_decreasing = (n) => {
    if (n === 0) return;
    console.log(n);
    print_decreasing(n - 1);
};

print_decreasing(5);

// Expectation;
// p(5) => 5 4 3 2 1 print krbe;

// Faith;
// p(4) => 4 3 2 1 print krbe;

// Faith + Expectation;
// p(5) => p(4) print krbe
//     => sathe 5 o print krbe;