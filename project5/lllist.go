/*
  CS333 Project 5
  Part II: Selected Language - Go
  Implement a LinkedList

  Yixuan Qiu
  Mar 28 2020
*/

package main

// generic type interface
type Elem interface{}

type Node struct {
	data Elem  // data stored at the current node
	next *Node // next pointer
	prev *Node // prev pointer
}

type LinkedList struct {
	size int   // size of LinkedList
	head *Node // head pointer
	tail *Node // tail pointer
}

// creates a new LinkedList, initializes it, and returns it
func create() *LinkedList {
	return &LinkedList{}
}

// adds a node to the front of the list, storing the given data in the node
func (l *LinkedList) push(val Elem) {

	// create a new node
	n := Node{val, nil, nil}

	if l.size == 0 { // if list is empty
		l.tail = &n
	} else { // if not empty
		n.next = l.head
		l.head.prev = &n
	}

	l.head = &n
	l.size += 1
}

// removes the node at the front of the list and returns the associated data
func (l *LinkedList) pop() Elem {
	if l.size == 0 {
		return nil
	}

	val := l.head.data
	curr := l.head.next
	l.head = nil
	l.head = curr
	l.size -= 1

	return val
}

// adds a node to the end of the list, storing the given data in the node
func (l *LinkedList) append(val Elem) {
	// initialize new node
	n := Node{val, nil, l.tail}

	// if list is empty
	if l.size == 0 {
		l.head = &n
	} else {
		l.tail.next = &n
	}

	l.tail = &n
	l.size += 1
}

// removes the first node in the list whose data matches target given the comparison function
func (l *LinkedList) remove(target Elem) Elem {
	var nodeToRemove *Node

	// empty list
	if l.size == 0 {
		return nil
	}

	// search target
	for n := l.head; n != nil; n = n.next {
		if n.data == target {
			nodeToRemove = n
		}
	}

	if nodeToRemove != nil {
		// target is first node
		if nodeToRemove.prev == nil {
			nodeToRemove.next.prev = nil
			l.head = nodeToRemove.next
			l.size--
			return target
		}

		// target is last node
		if nodeToRemove.next == nil {
			nodeToRemove.prev.next = nil
			l.tail = nodeToRemove.prev
			l.size--
			return target
		}

		// target is in middle
		nodeToRemove.next.prev = nodeToRemove.prev
		nodeToRemove.prev.next = nodeToRemove.next
		l.size--
		return target
	}

	// if target not in the list ( nodeToRemove == nil )
	return nil
}

// returns the size of the list
func (l *LinkedList) getSize() int {
	return l.size
}

// removes all of the nodes from the list
func (l *LinkedList) removeAll() {
	for n := l.head; n != nil; n = n.next {
		// remove node
		n.data = nil
	}
	l.head = nil
	l.tail = nil
	l.size = 0
}

// traverses the list and applies the given function to the data at each node
func (l *LinkedList) ll_map(mapfunc func(interface{}) interface{}) {
	for n := l.head; n != nil; n = n.next {
		n.data = mapfunc(n.data)
	}
}
