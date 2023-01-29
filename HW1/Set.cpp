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

// Create an empty set (i.e., one whose size() is 0).
Set::Set(){
    m_items = 0;
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
    if(m_items + 1 > DEFAULT_MAX_ITEMS || this->contains(value))
        return false;
    int index = 0;
    if(m_items != 0){
        index = m_items;
        while(m_array[index - 1] > value && index >= 0)
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
    int temp = this->m_items;
    this->m_items = other.m_items;
    other.m_items = temp;
    int length = (other.m_items > this->m_items) ? other.m_items : this->m_items;
    for(int i = 0; i < length; i++){
        ItemType temp = this->m_array[i];
        this->m_array[i] = other.m_array[i];
        other.m_array[i] = temp;
    }
}
