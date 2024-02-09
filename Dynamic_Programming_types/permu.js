
// function permuRepeat(nums, target) {
//     n++;
//     if (target == 0) return true;
//     if (target < 0) return false;


//     for (i in nums) {
//         if (permuRepeat(nums, target - nums[i]) == true) {
//             return true;
//         }
//     }
//     return false;
// }

function combRepeat(nums, target, index = 0) {
    if (target == 0)
        return true;
    if (target < 0)
        return false;

    for (let i = index; i < nums.length; i++) {
        if (combRepeat(nums, target - nums[i], i + 1) == true) {
            console.log(nums[i]);
            return true;
        }
    }

    return false;
}

console.log(combRepeat([2, 3], 5));