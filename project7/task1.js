/**
 * CS333 Project 7
 * task1.js
 * Research on memory management algorithms in JavaScript
 * 
 * Di Luo
 * 05/15/2020
 */

var str = 'Hello World!'; // allocate memory for string

var int = 1; // allocate memory for integer

var obj = { name: 'David', age: 21 } // allocate memory for object

function welcome(){ // allocate memory for function
    console.log('Hello World!');
}

// Examples of multiple reference
var anotherobj = obj; // another referenceing of { name: 'David', age: 21 }
obj = null; // reassign obj, anotherobj keeps reference
console.log(anotherobj.name);
anotherobj = null; // reassign anotherobj, object becomes inaccessible

// example of interlinked object and keyword 'delete'
function link(one, two){
    // connect the two object with each other
    one.friend = two;
    two.friend = one;
    return{
        one: one,
        two: two
    }
}

// create object all to hold the two of link
var all = link({id: 'first'}, {id: 'second'});

delete all.one; // Delete reference between all and {id: 'first'}

console.log(all.two.friend.id); // {id: 'first'} is still accessible through its link with {id: 'second'}

delete all.two.friend; // delete the last reference to {id: 'first'}, make it inaccessible

all = null; // delete interlinked object created by link()

