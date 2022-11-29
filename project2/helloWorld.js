/**
 * CS333 Project 2
 * helloWorld.js
 * A hello world program in JavaScript that plays with 
 * variable declaration in JavaScript
 *
 * Di Luo & Yixuan Qiu
 * 03/01/2020 
 */

function helloWorld(){
    var a; 
    var b;
    var c = "Hello World!"; 
    var l = [a, b, c];
    var dict = {0: "a", 1: "b", 2: "c"};

    for (let i = 0; i < 3; i++){
        if (l[i] === undefined){
            console.log('var ' + dict[i] + ' is undefined.\n');
        }
        else{
            console.log('var ' + dict[i] + ' is defined with value ' + l[2] + '.');
        }
    }
}

helloWorld()