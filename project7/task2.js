/**
 * CS333 Project 7
 * task2.js
 * Investigation on automatic memory management / garbage collection in JS
 * 
 * Di Luo
 * 05/15/2020
 */

function allocateAndFree(){
    for (var i=0; i<1000; i++){
        var array = [];
        for (var i=0; i<1000; i++){
            array.push(i);
        }
        array = 'free';
    }
}

function detection(func){
    var record = [];
    for (var i=0; i<10; i++){
        var t1 = new Date();
        func();
        var t2 = new Date();
        var oldtime = time;
        var time = t2 - t1;
        console.log(func.name + ' spent time: ' + time + 'ms');
        if (time > oldtime*10){
            record.push(i+1);
        }
    }
    console.log('Garbage collection happens in the ' + record + 'th function call.');
}

detection(allocateAndFree);
