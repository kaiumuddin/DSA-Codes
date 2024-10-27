def last_index arr, target, i=0
    return -1 if arr.size == i

    last_index_in_smaller_arr = last_index arr, target, i + 1

    if last_index_in_smaller_arr == -1
        return arr[i] == target ? i : last_index_in_smaller_arr
    end

    return last_index_in_smaller_arr
end


puts last_index([-5, 34, -5, 34, 32], 32)
