// var target_sum = (arr, target, i = 0, ans = '') => {

//     if (i >= arr.length) {
//         if (target === 0) console.log(ans);
//         return;
//     }

//     target_sum(arr, target - arr[i], i + 1, ans + arr[i] + " ");
//     target_sum(arr, target, i + 1, ans);
// };

// target_sum([10, 20, 30, 40, 50], 70);

/////////////////////////////////////////////////

// make 20 with number between 1 and 20, numbers should not repeat
var target_sum = (target = 20, i = 1, ans = []) => {

    if (target < 0 || i > 20) {
        return;
    }

    if (target === 0 && ans.length === 4) {
        console.log(ans);
        return;
    }

    ans.push(i);
    target_sum(target - i, i + 2, ans);
    ans.pop();
    target_sum(target, i + 2, ans);
};

target_sum();