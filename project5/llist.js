/**
 * CS333 Project 5
 * llist.js
 * Functions of single-linked list in JavaScript
 * 
 * Di Luo
 * 04/13/2020
 */

class Node {
    // Node class that stores the data and the address to the next node
    constructor (data){
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    // LinkedList class that stores the address to the first node and the size
    constructor (){
        this.head = null;
        this.size = 0;
    }

    ll_push(data){
        // adds a node to the front of the list, storing the given data in the node
        let new_node = new Node(data);
        new_node.next = this.head;
        this.head = new_node;
        this.size++;
    }

    ll_pop(){
        // removes the node at the front of the list and returns the associated data
        if (this.head == null) {
            console.log('List is empty.')
            return null;
        }
        var data = this.head.data;
        this.head = this.head.next;
        this.size--;
        return data;
    }

    ll_append(data){
        // adds a node to the end of the list, storing the given data in the node
        let new_node = new Node(data);
        if (this.head == null){
            // original list is empty, then push the node
            this.head = new_node;
        }
        else{
            // traverse the list to add new node to the end
            let trav = this.head;
            while(trav.next != null){
                trav = trav.next;
            }
            trav.next = new_node;
        }
        this.size++;
    }

    ll_remove(target, compfunc){
        // removes the first node in the list whose data matches target given 
        // the comparison function. The function returns the data.
        let current, previous;
        current = this.head;
        previous = null;

        while (current != null){
            if (compfunc(target, current.data) == true){
                if (previous == null){
                    this.head = current.next;
                }
                else{
                    previous.next = current.next;
                }
                this.size--;
                return current.data;
            }
            previous = current;
            current = current.next;
        }
        return null;
    }

    ll_size(){
        // return the size of linked list
        return this.size;
    }

    ll_clear(){
        // removes all of the nodes from the list
        this.head = null;
        this.size = 0;
    }

    ll_map(mapfunc){
        // traverses the list and applies the given function to the data at each node
        let ptr = this.head;
        while (ptr != null){
            ptr.data = mapfunc(ptr.data);
            ptr = ptr.next;
        }
    }

    // Extension: Delete function
    ll_delete(idx){
        let current, previous;
        current = this.head;
        previous = null;

        // deletes the node indicated by the index and return the data
        if (idx > this.size-1){
            console.log("Index out of range");
            return null
        }

        if (idx == 0){
            return this.ll_pop();
        }

        for (let i=0; i<idx; i++){
            previous = current
            current = current.next;
        }
        previous.next = current.next;
        this.size--;
        return current.data;
    }
}

module.exports = {
    LinkedList: LinkedList,
    Node: Node
}