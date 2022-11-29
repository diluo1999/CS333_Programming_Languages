/**
 * CS333 Project 3
 * task2.js
 * JavaScript: executes a binary search on a list or array of numbers
 * 
 * Di Luo & Yixuan Qiu
 * 03/04/2020
 */

function binarySearch(array, i){
    array.sort(function(a, b){return a - b});
    let left = 0;
    let right = array.length-1;
    while (left <= right){
        let mid = Math.floor((left+right)/2);
        if (i == array[mid]){
            console.log(i+" is found.");
            return mid;
        }
        else if (i < array[mid]){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    console.log(i+" is NOT found.")
}

let a = [1, 3, 5, 7, 9];
console.log("The array is [1,3,5,7,9]")
console.log("Check if 5 can be found.")
binarySearch(a, 5)
console.log("Check if 2 can be found.")
binarySearch(a, 2)