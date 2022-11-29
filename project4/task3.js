/**
 * CS333 Project 4
 * task3.js
 * Implement a general sort algorithm that can be used for 
 * any type and can be used to obtain any desired order
 * 
 * Di Luo
 * 03/11/2020
 */

function insertSort(array, comparator){
    var l = array.length;
    if (l<=1){
        return array;
    }
    for (var i=0; i<l; i++){
        insert(i, array, comparator);
    }
    return array;
}

function insert(index, array, comparator){
    let temp = array[index];
    while (index>0 && comparator(array[index-1], temp)>0){
        array[index] = array[index-1];
        index--;
    }
    array[index] = temp;
}

function ascending_comparator(a, b){
    return a-b;
}

function descending_comparator(a, b){
    return b-a;
}

a = [4,5,7,5,34,2,45,6,8,6,4];
console.log(insertSort(a, ascending_comparator));
console.log(insertSort(a, descending_comparator));
