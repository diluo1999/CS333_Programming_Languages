/**
 * CS333 Project 3
 * task1.js
 * JavaScript: demonstrates the rules for identifier naming, variable declarations and identifier scoping
 * 
 * Di Luo & Yixuan Qiu
 * 03/04/2020
 */

/**
 * Identifier naming
 */ 

// case-sensitive
var Student = "A";
var student = "B";
console.log("Content in Student:" + Student);
console.log("Content in student:" + student);

// The first character
var a, _a, $a;


/**
 * Variable declarations
 */ 

var a = 1; //scope being its execution context
let b = 2; //constrained to the scope it's declared in
const c = 3; //value cannot be modified; constrained to the scope it's declared in


/**
 * Identifier scoping
 */

//global scope
var name = "Di";
console.log("name in global scope: " + name);
function call(){
    //function scope
    var name = "iD";
    console.log("name in function scope: " + name);
}
call();
console.log("check name value, should be unmodified: " + name);