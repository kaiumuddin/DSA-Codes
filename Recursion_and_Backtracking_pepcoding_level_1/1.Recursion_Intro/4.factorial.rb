# def factorial n
#   return 1 if n == 1

#   return n * factorial(n-1)
# end

def factorial(n) n == 1 ? 1 : n * factorial(n - 1) end


puts factorial 5

# // Expectation
# // factorial(3) = 3 * 2 * 1;

# // Faith
# // factorial(2) = 2 * 1;

# // F + E
# // factorial(3) = 3 * factorial(2)
