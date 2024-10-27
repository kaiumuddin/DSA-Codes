def first_index arr, target, i = 0
    return -1 if i == arr.size

    ans = first_index(arr, target, i + 1)

    return arr[i] == target ? i : ans
end

# puts first_index [-5, 341, 34, 34, 32], 32

# /////////////////////////////////
def first_index2 arr, target, i = 0
    return -1 if i == arr.size

    return i if arr[i] == target

    first_index2(arr, target, i + 1)
end

# puts first_index2 [-5, 341, 34, 34, 32], 32

# /////////////////////////////////
def first_index3 arr, target, i = 0
    return -1 if i == arr.size

    return arr[i] == target ? i : first_index3(arr, target, i + 1)
end

puts first_index3 [-5, 341, 34, 34, 32], 341
# // E
# // first of( 0 to n)

# // F
# // first of( 1 to n)

# // F + E
# // first of (0 , 1 to n)
