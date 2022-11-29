/**
 * CS333 Project 4
 * task1.js
 * Program that uses all the control flow statement in JS and compare
 * them with those in C
 * 
 * Di Luo
 * 03/11/2020
 */

// for loop and if...else... statements
function forloopAndIf(i){
    for (var j=0; j<i; j++){
        console.log("for loop and if/else test:");
        if (i<3){
            console.log("if is executed.");
        }
        else{
            console.log("esle is executed.");
        }
    }
}

forloopAndIf(3);

// while loop
function whileloop(i){
    console.log("while loop test:");
    while(i<5){
        console.log("i value is" + i);
        i++;
    }
}

whileloop(3);


// for-in loop
function forInLoop(){
    let phone = ["iPhone", "Sumsang", "Huawei"];
    for (let j in phone){
        console.log(phone[j] + " is a brand of smartphone.");
    }
}

forInLoop();


// switch statement
function switch_statement(i){
    console.log("switch statement test:");
    switch (i){
        case "iPhone":
            console.log("iPhone: $799");
        break;
        case "Huawei":
            console.log("Huawei: $599");
        break;
        case "Sumsang":
            console.log("Sumsang: $699");
        break;
        default:
            console.log("This smartphone brand cannot be recognized.");
    }
}

switch_statement("iPhone");
switch_statement("Mi");