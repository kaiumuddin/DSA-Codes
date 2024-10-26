def print_decInc(n)
  return if n == 0

  puts n
  print_decInc n-1
  puts n
end

print_decInc 5

# // Expectation;
# // p(2) => 2 1 1 2 print krbe;

# // Faith;
# // p(1) => 1 1 print krbe;

# // Faith to Expectation;
# // p(3) =>
# // print 3
# // p(2) print krbe
# // print 3


# // High Level Thinking -> Basic code
# // 1. Expection -> 5 pass krle 5 4 3 2 1 print krbe
# // 2. Faith -> chuto valuer jnno kaj krbe, 4 emne emne print hbe, kmne hbe janar drkr nai
# // 3. Faith to Expectation Relationship

# // Low Level Thinking -> Dry RUn, Stack -> Base Case
