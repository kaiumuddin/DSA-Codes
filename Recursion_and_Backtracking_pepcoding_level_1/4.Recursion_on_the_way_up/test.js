const str = "123";

const num = parseInt(str[0]);
console.log(num + 1);

const letter = String.fromCharCode(96 + parseInt(str[0] + str[1]));
console.log(letter);