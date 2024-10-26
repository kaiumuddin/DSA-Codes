def toh n, src, des, hlp
  return if n == 0

  toh(n-1, src, hlp, des);
  puts "#{n} [#{src} -> #{des}]"
  toh(n-1, hlp, des, src)
end

toh 3, "A", "B", "C"
