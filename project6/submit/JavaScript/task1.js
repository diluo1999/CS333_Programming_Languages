/**
 * CS333 Project 6
 * task1.js
 * Word counter that can count the number of occurrences of every word in a text file
 * 
 * Di Luo
 * 05/10/2020
 */

var map = new Map();

function analyze(filename){
    const fs = require('fs');
    var contents = fs.readFileSync(filename, 'utf8');
    contents = contents.toString();
    var list = contents.split(" ");
    var found = 0;
    for (var i = 0; i < list.length; i++){
        list[i] = list[i].replace(/\b[-.,()&$#!\[\]{}"']+\B|\B[-.,()&$#!\[\]{}"']+\b/g, "");
        list[i] = list[i].toLowerCase();
        if (map.has(list[i]) == true){
            map.set(list[i],map.get(list[i])+1);
            found = 1;
        }
        if (found == 0){
            map.set(list[i],1);
        }
        found = 0;
    }
}

function main(){
    analyze('wctest.txt');
    map[Symbol.iterator] = function*(){
        yield* [...this.entries()].sort((a,b)=> b[1]-a[1]);
    }
    let keys = [];
    for (let key of map){
        keys.push(key);
    }
    for (var i=0; i<20; i++){
        let x = keys[i][0]
        let y = keys[i][1]
        console.log(x + ' ' + y);
    }
}

main()