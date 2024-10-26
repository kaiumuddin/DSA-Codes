def first_index arr, target, i = 0
    return -1 if i == arr.size

    ans = first_index(arr, target, i + 1)

    return arr[i] == target ? i : ans
end


puts first_index [-5, 341, 34, 34, 32], 34

# // E
# // first of( 0 to n)

# // F
# // first of( 1 to n)

# // F + E
# // first of (0 , 1 to n)
