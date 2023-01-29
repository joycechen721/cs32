//
//  newSet.cpp
//  Proj2
//
//  Created by Joyce Chen on 1/18/23.
//

#include "newSet.h"
#include <iostream>
#include <string>
using namespace std;

// Create an empty set (i.e., one whose size() is 0).
Set::Set(){
    max_items = DEFAULT_MAX_ITEMS;
    m_array = new ItemType[max_items];
    m_items = 0;
}

Set::Set(int size){
    max_items = size;
    m_array = new ItemType[max_items];
    m_items = 0;
}

Set::~Set(){
    delete [] m_array;
}

//copy constructor
Set::Set(const Set& oldSet){
    m_items = oldSet.m_items;
    max_items = oldSet.max_items;
    m_array = new ItemType[max_items];
    for(int i = 0; i < m_items; i++){
        m_array[i] = oldSet.m_array[i];
    }
}

//assignment operator
Set& Set::operator= (const Set& oldSet){
    if(&oldSet == this){ //could you do oldSet == *this? NO.
        return *this;
    }
    m_items = oldSet.m_items;
    max_items = oldSet.max_items;
    //delete original memory if not assigning the object to itself
    delete [] m_array;
    m_array = new ItemType[max_items];
    for(int i = 0; i < m_items; i++){
        m_array[i] = oldSet.m_array[i];
    }
    return *this;
}

// Return true if the set is empty, otherwise false.
bool Set::empty() const{
    return m_items == 0;
}

// Return the number of items in the set.
int Set::size() const{
    return m_items;
}

// Insert value into the set if it is not already present.  Return
// true if the value is actually inserted.  Leave the set unchanged
// and return false if value is not inserted (perhaps because it
// was already in the set or because the set has a fixed capacity and
// is full).
bool Set::insert(const ItemType& value){
    if(m_items + 1 > max_items || this->contains(value))
        return false;
    int index = 0;
    if(m_items != 0){
        index = m_items;
        while(index > 0 && m_array[index - 1] > value)
            index--;
        for(int i = m_items; i > index; i--){
            m_array[i] = m_array[i - 1];
        }
    }
    m_array[index] = value;
    m_items++;
    return true;
}
  
// Remove the value from the set if it is present.  Return true if the
// value was removed; otherwise, leave the set unchanged and
// return false.
bool Set::erase(const ItemType& value){
    for(int i = 0; i < m_items; i++){
        if(m_array[i] == value){
            for(int j = i; j < m_items; j++){
                m_array[j] = m_array[j + 1];
            }
            m_items--;
            return true;
        }
    }
    return false;
}
 
// Return true if the value is in the set, otherwise false.
bool Set::contains(const ItemType& value) const{
    for(int i = 0; i < m_items; i++){
        if(m_array[i] == value)
            return true;
    }
    return false;
}

// If 0 <= i < size(), copy into value the item in the set that is
// strictly greater than exactly i items in the set and return true.
// Otherwise, leave value unchanged and return false.
bool Set::get(int i, ItemType& value) const{
    if(i >= 0 && i < m_items){
        value = m_array[i];
        return true;
    }
    return false;
}

// Exchange the contents of this set with the other one.
void Set::swap(Set& other){
    Set tempSet = other;
    other = *this;
    *this = tempSet;
}
