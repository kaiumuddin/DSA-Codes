// to solve recursively
// 3. terminate condition
// 1. build ans for current node
// 4. update ans for child node;
// 2. return ans

const can_construct = (target, strings) => {

};

console.log(can_construct("abcdef", ['ab', 'abc', 'cd', 'def', 'abcd']));


// time : nums^target * target
// space : target*target


////////////////////////////////////////////////////////////////////////////

// to solve memo
// 6. if ans for current node already in memo, return it
// 3. terminate condition
// 1. build ans for current node
// 4. update ans for child node;
// 5. store ans in memo
// 2. return ans



// time : n * m * m
// space : m^2