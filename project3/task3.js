/**
 * CS333 Project 3
 * task3.js
 * JavaScript: demonstrates all of the basic built-in types and how to construct aggregate types
 * 
 * Di Luo & Yixuan Qiu
 * 03/04/2020
 */

// Built-in types
var a = 1;
var b = "a";
var c = undefined;
var d = null;
var e = true;
console.log("Type of 1: ", typeof a);
console.log("Type of \"a\": ", typeof b);
console.log("Type of undefined: ", typeof c);
console.log("Type of null(object): ", typeof d);
console.log("Type of true: ", typeof e);

// struct
let phone = {
    iphone: "expensive",
    priceofiphone: 799,
    mi: "cheap",
    priceofmi: 299
};

console.log("iphone is ", phone.iphone);
console.log("iphone price is ", phone.priceofiphone);
console.log("mi is ", phone.mi);
console.log("mi price is ", phone.priceofmi);

// class
class Food{
    constructor(name){
        this.name = name
    }
    call(){
        console.log("My name is " + this.name)
    }
}

//Addition between types
console.log("0.1 + 1 = ", 0.1+1); // 1.1
console.log("true + true = ", true+true); // 2
console.log("undefined + 1 = ", undefined+1); // Nan
console.log("string + string = ", "string"+"string"); // stringstring
console.log("null + string = ", null + "string"); // nullstring
console.log("null + 1 = ", null + 1); // 1
console.log("string + 1 = ", "string" + 1); // string1
console.log("\n");

//Subtraction between types
console.log("0.1 - 1 = ", 0.1-1); // -0.9
console.log("true - true = ", true- true); // 0
console.log("undefined - 1 = ", undefined-1); // NaN
console.log("string - string = ", "string"-"string"); // NaN
console.log("null - string = ", null - "string"); // NaN
console.log("null - 1 = ", null - 1); // -1
console.log("string - 1 = ", "string" - 1); // NaN
console.log("\n");

//Multiplication between types
console.log("0.1 * 1 = ", 0.1*1); // 0.1
console.log("true * true = ", true*true); // 1
console.log("undefined * 1 = ", undefined*1); // NaN
console.log("string * string = ", "string"*"string"); // NaN
console.log("null * string = ", null * "string"); // NaN
console.log("null * 1 = ", null * 1); // 0
console.log("string * 1 = ", "string" * 1); // NaN
console.log("\n");

//Division between types
console.log("0.1 / 1 = ", 0.1/1); // 0.1
console.log("true / true = ", true/true); // 1
console.log("undefined / 1 = ", undefined/1); // NaN
console.log("string / string = ", "string"/"string"); // NaN
console.log("null / string = ", null / "string"); // NaN
console.log("null / 1 = ", null / 1); // 0
console.log("string / 1 = ", "string" / 1); // NaN
console.log("\n");

//Modulo
console.log("0.1 % 1 = ", 0.1%1); // 0.1
console.log("true % true = ", true%true); // 0
console.log("undefined % 1 = ", undefined%1); // NaN
console.log("string % string = ", "string"%"string"); // NaN
console.log("null % string = ", null % "string"); // NaN
console.log("null % 1 = ", null % 1); // 0
console.log("string % 1 = ", "string" % 1); // NaN