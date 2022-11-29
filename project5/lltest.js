/**
 * CS333 Project 5
 * lltest.js
 * Testing single-linked list in JavaScript using different data types
 * 
 * Di Luo
 * 04/16/2020
 */

// import { Node, LinkedList } from 'llist.js';
var list = require('./llist.js');

function printInt(i){
	console.log(i.toString());
	return i;
}

function squareInt(j){
	return j * j;
}

function compInt(a, b){
	return (a==b);
}

function printStr(i){
	console.log(i);
	return i;
}

function compStr(a, b){
	return (a==b);
}

function testInteger() {
	let l = new list.LinkedList();
	let a, target, i;

	// push data on the list
	for(i=0;i<20;i+=2) {
		l.ll_push(i);
	}

	// printing the list and testing map
	console.log("Part 1: Integer\n");
	console.log("After initialization\n");
	l.ll_map(printInt);

	l.ll_map(squareInt);

	console.log("\nAfter squaring\n");
	l.ll_map(printInt);

	// testing removing data
	target = 16;
	a = l.ll_remove(target, compInt);
	if(a != null)
		console.log("\nremoved: " + a);
	else
		console.log("\nNo instance of " + target);

	target = 11;
	a = l.ll_remove(target, compInt);
	if(a != null)
		console.log("\nremoved: " + a);
	else
		console.log("\nNo instance of " + target);

	console.log("\nAfter removals\n");
	l.ll_map(printInt);

	// testing appending data
	l.ll_append(target);

	console.log("\nAfter append\n");
	l.ll_map(printInt);

	// test clearing
	l.ll_clear();

	console.log("\nAfter clear\n");
	l.ll_map(printInt);

	// rebuild and test append and pop
	for(i=0;i<5;i++) {
		l.ll_append(i);
	}

	console.log("\nAfter appending\n");
	l.ll_map(printInt);

	a = l.ll_pop();
	console.log("\npopped: "+a);

	a = l.ll_pop();
	console.log("popped: "+a);

	console.log("\nAfter popping\n");
	l.ll_map(printInt);

	console.log("\nList size: " + l.ll_size());

	console.log("\nReset the list to the rebuilded version.\n");
	l.ll_clear();
	for(i=0;i<5;i++) {
		l.ll_append(i);
	}
	l.ll_map(printInt);
	a = l.ll_delete(2);
	console.log("\ndeleted: "+a);
	console.log("\nAfter deleting node with index 2\n");
	l.ll_map(printInt);
}

function testString() {
	let l = new list.LinkedList();
	let a, target;

	// push data on the list
	l.ll_push('a');
	l.ll_push('b');
	l.ll_push('c');
	l.ll_push('d');
	l.ll_push('e');

	// printing the list and testing map
	console.log("\n\nPart 2: String\n");
	console.log("After initialization\n");
	l.ll_map(printStr);

	// testing removing data
	target = 'c';
	a = l.ll_remove(target, compStr);
	if(a != null)
		console.log("\nremoved: " + a);
	else
		console.log("\nNo instance of " + target);

	target = 'f';
	a = l.ll_remove(target, compStr);
	if(a != null)
		console.log("\nremoved: " + a);
	else
		console.log("\nNo instance of " + target);

	console.log("\nAfter removals\n");
	l.ll_map(printStr);

	// testing appending data
	l.ll_append(target);

	console.log("\nAfter append\n");
	l.ll_map(printStr);

	// test clearing
	l.ll_clear();

	console.log("\nAfter clear\n");
	l.ll_map(printStr);

	// rebuild and test append and pop
	l.ll_append('one');
	l.ll_append('two');
	l.ll_append('three');
	l.ll_append('four')

	console.log("\nAfter appending\n");
	l.ll_map(printStr);

	a = l.ll_pop();
	console.log("\npopped: "+a);

	a = l.ll_pop();
	console.log("popped: "+a);

	console.log("\nAfter popping\n");
	l.ll_map(printStr);

	console.log("\nList size: " + l.ll_size());

	console.log("\nReset the list to the rebuilded version.\n");
	l.ll_clear();
	l.ll_append('one');
	l.ll_append('two');
	l.ll_append('three');
	l.ll_append('four')
	l.ll_map(printStr);

	a = l.ll_delete(2);
	console.log("\ndeleted: "+a);
	console.log("\nAfter deleting node with index 2\n");
	l.ll_map(printInt);
}

testInteger();
testString();