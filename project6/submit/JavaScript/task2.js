/**
 * CS333 Project 6
 * task1.js
 * File I/O in JS: open, close, read file and binary finle; 
 * Reading from URLs;
 * Interactive: input from user
 * 
 * Di Luo
 * 05/10/2020
 */

function readtext(){
    const fs = require('fs');
    fs.open('wctest.txt','r+',function(err,fd){
        if (err){
            return console.error(err);
        }
        var t = fs.readFileSync('wctest.txt',"utf-8");
        console.log(t);
        fs.closeSync(fd);
    });
}

function write(){
    const fs = require('fs');
    fs.writeFile('file.txt',"Hello World!", function(err){
        if(err){
            return console.error(err);
        }
    });
}

function readbinary(){
    var fs = require('fs');
    var b = fs.readFileSync("wctest.txt", "binary");
}

function interactive(){
    const readline = require('readline').createInterface({
        input: process.stdin,
        output: process.stdout
    });
    readline.question("What's your name?", (name)=> {
        console.log(`Hi ${name}! Welcome!`)
        readline.close
    })
}
// readtext()
// write()
// readbinary()
interactive();