def display_arr arr, i=0
  return if i == arr.size

  puts arr[i]
  display_arr arr, i+1
end

display_arr [10,20,30,40,50]

# // E
# // 0 to  n

# // F
# // 1 to n

# // F + E
# // 0 + 1 to n
