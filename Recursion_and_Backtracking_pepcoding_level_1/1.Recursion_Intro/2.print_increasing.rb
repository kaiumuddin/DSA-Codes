def print_increasing(n)
    return if n == 0
    print_increasing n-1
    puts n
end

print_increasing 5

# // Expectation;
# // p(5) => 5 4 3 2 1 print krbe;

# // Faith;
# // p(4) => 4 3 2 1 print krbe;

# // Faith + Expectation;
# // p(5) => p(4) print krbe
# //     => sathe 5 o print krbe;
