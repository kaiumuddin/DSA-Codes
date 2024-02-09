var str = "01234";
console.log(str);

console.log(str.slice());
console.log(str.slice(2));
console.log(str.slice(2,5));
console.log(str);

str = str.slice(2);
console.log(str);

console.log(str.indexOf("3"))


const canConstruct = (target, wordBank) => {
    if(target === ''){
        return  true;
    }

    for(let word of wordBank){
        if(target.indexOf(word) === 0){
            const suffix = target.slice(word.length);
            if(canConstruct(suffix, wordBank) === true ){
                return true;
            }
        }
    }

    return false;
}


console.log(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]));
console.log(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]));

// console.log(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeee", "eeeee", "eeeeee"]));
