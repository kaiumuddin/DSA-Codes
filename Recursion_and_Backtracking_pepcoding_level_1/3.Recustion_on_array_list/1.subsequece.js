// total substring  = n*(n+1)/2
// total subsequence = 2^n

const subsequence = (str) => {
    if (str.length === 0) return [""];


    const child = subsequence(str.slice(1));

    const ans = [];
    for (c of child) {
        ans.push("-" + c);
        ans.push(str[0] + c);
    }

    return ans;

};

console.log(subsequence("123"));
/////////////////////////////////////////////////
// https://leetcode.com/problems/subsets/description/



var subsets = function(nums) {
    if (nums.length === 0) return [[]];

    const childs = subsets(nums.slice(1));

    const ans = [];
    for (let child of childs) {
        ans.push([...child]);
        ans.push([nums[0], ...child]);
    }

    return ans;
};
console.log(subsets([1, 2, 3]));

// bc -> [--, -c, b-, bc]
// abc -> [---, --c, -b-, -bc, a--, a-c, ab-, abc]

// High Level Thinking
// 1. Expectation -> 5 pass krle 5 4 3 2 1 print krbe
// 2. Faith -> chuto valuer jnno kaj krbe, 4 emne emne print hbe, kmne hbe janar drkr nai
// 3. Expectation + Faith Relationship
