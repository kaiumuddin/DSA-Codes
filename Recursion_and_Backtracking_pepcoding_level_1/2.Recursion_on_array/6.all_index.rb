def all_index arr, target, i = 0
  return [] if i == arr.size

  fsf = all_index arr, target, i + 1

  return fsf << i if arr[i] == target

  return fsf
end

puts all_index([-5, 34, -5, 34, 32], -5)
