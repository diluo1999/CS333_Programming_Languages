/**
 * CS333 Project 6
 * task3.js
 * Error handling in JS
 * 
 * Di Luo
 * 05/10/2020
 */

// example of unconditional try-catch block that uses throw statement to create an exception
function unconditional(){
    try {
        throw 'I am the exception message.'
    }
    catch(e) {
        console.log(e)
    }
}

// example of conditional try-catch block that uses if/else to simulate the funcionality of multiple catch statement
function conditional(){
    try {
        eval("console.log('Hello World!)"); // 
    }
    catch (e) {
        if (e instanceof TypeError) {
            console.log('Type error appears')
        } 
        else if (e instanceof RangeError) {
            console.log('Range error appears')
        } 
        else if (e instanceof EvalError) {
            console.log('Eval error appears')
        } 
        else {
            console.log('No idea what kind of error it is. Maybe Syntax?')
        }
    }
}

unconditional()
conditional()