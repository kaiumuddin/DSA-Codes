var a = ["Luke", "Leia", "Han", "Chewie"];
console.log(a);
console.log(a.length);

a.push('Anakin');
a.push('Obiwan');
console.log(a);

a.pop();
console.log(a);

a.unshift('C3PO');
a.unshift('R2D2');
console.log(a);

a.shift();
console.log(a);

var s = a.shift();
console.log(s);

console.log(a);
a.splice(0, 0, "Rey");
console.log(a);

a.reverse()
console.log(a);

a.sort();
console.log(a);

a = ["Rey", "Leia", "Han", "Chewiw", "Rey"];
console.log(a);

console.log(a.indexOf("Rey"));
console.log(a.lastIndexOf("Rey"));

a = ["Earth", "Jupiter", "Mars", "Venus", "Uranus", "Neptune", "Saturn", "Mercury"];
for(var i=0; i<a.length; i++){
  console.log(a[i]);
}

// arrays has number list
// objects has labels

// object
var objectA = {"name":"Woody", "type":"dog"};
var objectB = {"name":"bob", "type":"cat"};
console.log(objectA);

// array can hold object
var array = [objectA, objectB];
console.log(array);

var array = [{"name":"Woody", "type":"dog"}, objectB];
console.log(array);

array.push({"name":"Roxy", "type":"dog"});
console.log(array);
console.log(array[2]);

// adding new property to object

// object and object literals
objectA.age = 2;
console.log(objectA);

objectB["age"] = 14;
console.log(objectB);

console.log(array);

// adding new property to object targeting array
array[0].age = 4;
array[1].age = 5;
array[2].age = 7;
console.log(array);

array[2]["age"] = 9;
console.log(array);

var cats = {"name":"Woody", "type":"dog"};
var array = [cats];
console.log(array);
console.log(cats);

cats.age = 45;
console.log(cats);

array[0].hungary = true;
console.log(array);
console.log(cats);


var cats = {"name":"Woody", "type":"dog"};
console.log(cats);

for(let prop in cats){
  console.log(prop);
  console.log(cats[prop]);
}

for(let prop in cats){
  console.log(prop, ":", cats[prop]);
}

array = ["Earth", "Jupiter", "Mars", "Venus", "Uranus", "Neptune", "Saturn", "Mercury"];
for(let p in array){
  console.log(p);
  console.log(array[p]);
}

for(let p in array){
  console.log(p , array[p]);
}


// foreach
array = ["Earth", "Jupiter", "Mars", "Venus", "Uranus", "Neptune", "Saturn", "Mercury"];
array.forEach(output);

function output(item, index, array){
  console.log(index, item);
}

array.forEach(function(item, index, array){
  if(item === 'Venus'){
    item = item.toUpperCase();
  }
  console.log(item);
});

array.forEach((item, index, array)=>{
  if(item === 'Venus'){
    item = item.toUpperCase();
  }
  console.log(item);
});


// two Dimentional array
let twoD =  [
              [1,2,3],
              [4,5,6],
              [7,8,9]
            ];

let twoC = [ [1,2,3], [4,5,6], [7,8,9] ];
//console.log(twoC);

let rows = twoD.length;
for(let i=0; i<rows; i++){
  let items = twoD[i].length;
  for(let j=0; j<items; j++){
    console.log(twoD[i][j]);
  }
}

for(let r=0; r<twoC.length; r++){
  console.log(twoC[r]);
}

for(let r=0; r<twoC.length; r++){
  for(let c=0; c<twoC[r].length; c++){
    console.log( twoC[r][c]);
  }
}


let bigHero =
{
  charecters: [
    {name:'Hero', voice:'Ryan Potter'},
    {name:'Baymax', voice:'Scott Adsit'},
    {name:'GoGo Tamgo', voice:'Jamie Chung'},
    {name:'Fred', voice:'T.J. Miller'}
  ]
}

console.log(bigHero);

for(let obj=0; obj < bigHero['charecters'].length; obj++){
  console.log(  bigHero['charecters'][obj]  );
}

for(let obj=0; obj < bigHero['charecters'].length; obj++){
    for(let prop in bigHero['charecters'][obj]){
      console.log(  prop, ":", bigHero['charecters'][obj][prop]  );
    }
}

console.log('192');

let x = [2, 4, 6, 8];
let y = [1, 3, 5];

let z = x.concat(y);
console.log(z);
let p = [].concat(x, y).sort();
console.log(p);

for(let i in x){
  console.log(i);
}

for(let i in x){
  console.log(x[i]);
}

for(let i of x){
  console.log(i);
}



// String split and Array join methods
// Converting String to Arrays to Strings
// String to Array  str.split();
// Array to String  arr.join();

let sentence = "Hello my name is Kaium Uddin";

let words = sentence.split(" ");
console.log(words);

// let words = sentence.split(" ").sort();
// console.log(words);

let chars = sentence.split(" name ");
console.log(chars);

let hyphenated = words.join("-");
console.log(hyphenated);

let oneWord = words.join("");
console.log(oneWord);

let final = sentence.split(" ").sort().join(" ");
console.log(final);




// Array every method

let numbers = [40, 16, 67, 345, 22, 23, 142, 63, 59, 283];
console.log(numbers);

let greaterThan20 = numbers.every(function(num){
    console.log(num);
    return num >20;
});

console.log(greaterThan20);

let greaterThan10 = numbers.every(function(num){
    console.log(num);
    return num >10;
});

console.log(greaterThan10);




const isLess30 = (element) => element<30;

const array1 = [1, 30, 39, 29, 10, 13];
console.log(array1.every(isLess30));
console.log(array1.every((element)=> element<30));


// Array includes
const array2 = [1, 2, 3];
console.log(array2.includes(2));

// Array some 
const array3 = [1, 3, 5, 7];
console.log(array3.some((element)=> element%2 === 0));