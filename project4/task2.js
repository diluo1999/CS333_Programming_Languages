/**
 * CS333 Project 4
 * task2.js
 * Program that shows how functions are treated in JS
 * 
 * Di Luo
 * 03/11/2020
 */

function func(){
    console.log("func executes");
}

console.log(func instanceof Object);

var f = func();
f;

function func2(){
    console.log("Testing func in func.");
    func();
}

func2();

// function (){
//     console.log("Function without name");
// }

var f2 = function(){
    console.log("Function expression");
}
f2();