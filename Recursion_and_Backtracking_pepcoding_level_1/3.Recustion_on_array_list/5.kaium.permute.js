// var permute = function(nums) {
//     if (nums.length === 0) return [[]];

//     const ans = [];
//     for (let i = 0;i < nums.length;i++) {
//         const faith = permute([...nums.slice(0, i), ...nums.slice(i + 1)]);

//         for (f of faith) {
//             ans.push([nums[i], ...f]);
//         }
//     }

//     return ans;

// };

// backtrack;
var permute = function(nums) {
    const ans = [];
    const set = new Set();

    const backtrack = (perm) => {
        if (perm.length == nums.length) {
            ans.push([...perm]);
            return;
        }

        for (let i = 0;i < nums.length;i++) {
            if (!set.has(nums[i])) {
                set.add(nums[i]);
                perm.push(nums[i]);
                backtrack(perm);
                perm.pop();
                set.delete(nums[i]);
            }
        }
    };

    backtrack([]);
    return ans;
};

console.log(permute([1, 2, 3]));