//
//  Set.cpp
//  Proj2
//
//  Created by Joyce Chen on 1/18/23.
//

#include "Set.h"
#include <iostream>
#include <string>
using namespace std;

// create an empty set
Set::Set(){
    m_items = 0;
    //circularly linked
    head = new Node;
    head->next = head;
    head->prev = head;
}

//copy constructor
Set::Set(const Set& oldSet){
    m_items = oldSet.m_items;
    
    //initialize the head node
    head = new Node;
    head->next = head;
    head->prev = head;
    
    //create traversal nodes for both the new and source set
    Node* pOld = oldSet.head->next;
    Node* pNew = head;
    
    //traverse through old set
    while(pOld != oldSet.head){
        //create new node to insert into new set
        Node* newNode = new Node;
        newNode->value = pOld->value;
        
        //link up the new node
        Node* temp = pNew->next;
        pNew->next = newNode;
        newNode->next = temp;
        newNode->prev = pNew;
        
        //increment the traversal nodes
        pNew = newNode;
        pOld = pOld->next;
    }
}

//assignment operator
Set& Set::operator= (const Set& oldSet){
    //create temporary Set that has all of oldSet's info
    Set temp = oldSet;
    //swap this Set with the temp Set
    this->swap(temp);
    return *this;
}

//destructor
Set::~Set(){
    //traverse through Set starting @ first element
    Node* p = head->next;
    //delete node pointed to by head first
    delete head;
    while(p != head){
        Node* nextNode = p->next;
        delete p;
        p = nextNode;
    }
}

// check if set is empty
bool Set::empty() const{
    return m_items == 0;
}

// return the # of items in the set
int Set::size() const{
    return m_items;
}

// insert value into the set if it is not already present
bool Set::insert(const ItemType& value){
    if(this->contains(value))
        return false;
    
    //create node for the new value
    Node* insert = new Node;
    insert->value = value;
    Node* p = head;
    
    //stops at the first node smaller than value
    while(p->next != head && value > p->next->value){
        p = p->next;
    }
    
    Node *nextNode = p->next;
    insert->next = nextNode;
    nextNode->prev = insert;
    
    p->next = insert;
    insert->prev = p;
    
    m_items++;
    return true;
}
    
// remove the value from the set if it is present.  return true if the
// value was removed; otherwise, leave the set unchanged and
// return false.
bool Set::erase(const ItemType& value){
    Node *p = head;
    //traverse through the set
    while(p->next != head){
        if(p->next->value == value){
            //pointer to node that will be deleted
            Node* killMe = p->next;
            //link the traversal node to the node after killMe
            p->next = killMe->next;
            killMe->next->prev = p;
            delete killMe;
            m_items--;
            return true;
        }
        p = p->next;
    }
    return false;
}
 
// return true if the value is in the set, otherwise false
bool Set::contains(const ItemType& value) const{
    Node* p = head;
    //traverse through the set until it loops back to the head node
    while(p->next != head){
        p = p->next;
        if(p->value == value){
            return true;
        }
    }
    return false;
}

// copy into value the item in the set that is strictly greater than
// exactly i items in the set and return true.
// Otherwise, leave value unchanged and return false.
bool Set::get(int i, ItemType& value) const{
    //check if i is valid
    if(i >= 0 && i < m_items){
        //traverse through set starting at first element
        Node* p = head->next;
        //stops when p = the correct item
        for(int count = 0; count < i; count++){
            p = p->next;
        }
        value = p->value;
        return true;
    }
    return false;
}

// exchange contents of this set with the other one
void Set::swap(Set& other){
    int temp = this->m_items;
    this->m_items = other.m_items;
    other.m_items = temp;
    
    //swap head pointers
    Node* tempHead = this->head;
    this->head = other.head;
    other.head = tempHead;
}

//non-member functions
void unite(const Set& s1, const Set& s2, Set& result){
    //create a temporary set and set it to s1 (calls assignment operator)
    Set tempResult = s1;
    ItemType value;
    //traverse through s2
    int count = 0;
    while(count < s2.size()){
        //insert value in s2 to result
        s2.get(count, value);
        tempResult.insert(value);
        count++;
    }
    result = tempResult;
}

//values that appear in s1, but not s2
void butNot(const Set& s1, const Set& s2, Set& result){
    //create a temporary set and set it to s1 (calls assignment operator)
    Set tempResult = s1;
    ItemType value;
    //traverse through s2
    int count = 0;
    while(count < s2.size()){
        //erase value from temp if s2 contains the same value
        s2.get(count, value);
        if(tempResult.contains(value)){
            tempResult.erase(value);
        }
        count++;
    }
    //set the resulting set to temp
    result = tempResult;
}
