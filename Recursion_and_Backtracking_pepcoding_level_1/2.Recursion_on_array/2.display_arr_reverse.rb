def display_arr arr, i=0
    return if i == arr.size

    display_arr arr, i+1
    puts arr[i]
end

display_arr [10,20,30,40,50]

# // E
# // n to 0

# // F
# // n to 1

# // F + E
# // n to 1, 0
