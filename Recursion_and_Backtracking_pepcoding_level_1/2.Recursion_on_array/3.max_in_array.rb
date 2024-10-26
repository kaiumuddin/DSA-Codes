def max_in_arr arr, i=0
  return -Float::INFINITY if i == arr.size

  maxi = max_in_arr arr, i+1
  return [arr[i], maxi].max
end

puts max_in_arr [-5, 34, 342, 34234, 32]
puts max_in_arr [34234, 32,-5, 34, 342]
