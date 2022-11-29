/**
 * CS333 Project 3
 * extension2.js
 * JavaScript: Demonstrate whether functions are a basic data type 
 * & Can a variable hold an arbitrary function?
 * 
 * Di Luo & Yixuan Qiu
 * 03/04/2020
 */

// Functions in JS can be assgined to variables
var greeting = new function(){
    this.number = 1;
    this.readme = function(){
        console.log("The function greeting is for printing out \"Hello!\".");
    }
}
console.log(greeting.number);
greeting.readme();
console.log("The type of the function greeting is ", typeof greeting);