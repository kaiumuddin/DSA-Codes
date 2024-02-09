var arr = []
var target;
var index = 0;

function combRepeat(arr, target, index = 0) {
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;

    for (let i = index; i < arr.length; i++) {
        if (combRepeat(arr, target - arr[i], i + 1) == 1) {
            console.log(arr[i]);
            return 1;
        }
    }
    return 0;
}

console.log(combRepeat([2, 3], 5));