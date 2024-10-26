def power_linear x, n
  return 1 if n == 0

  return x * power_linear(x, n-1)
end

puts power_linear 3, 5



def power_logarithmic x, n
    return 1 if n == 0

    xn2 = power_logarithmic x, n/2

    return xn2 * xn2 if n.even?
    return x * xn2 * xn2 if n.odd?
end

puts power_logarithmic 3, 5
