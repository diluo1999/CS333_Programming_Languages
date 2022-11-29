/**
 * CS333 Project 3
 * extension3.js
 * JavaScript: include other example programs that show unique features of the 
 * syntax, naming, or scoping & Develop explicit comparison code in Python, 
 * Java, or C and compare and contrast it with JS
 * 
 * Di Luo & Yixuan Qiu
 * 03/04/2020
 */

// scope & data type declaration
// JavaScript has no block scope unless keyword let is used, and 
function Var(){
    var v = 1;
    {
        var v = 0;
        console.log(v); // 0
    }
    console.log(v); // 0 since it's the same v
}

function Let(){
    let v = 1;
    {
        let v = 0;
        console.log(v) // 0
    }
    console.log(v); // 1 since it's in different scope
}
console.log("var: ")
Var();
console.log("let: ")
Let();
