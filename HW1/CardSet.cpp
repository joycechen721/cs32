//
//  CardSet.cpp
//  Proj2
//
//  Created by Joyce Chen on 1/18/23.
//

#include "CardSet.h"
#include <iostream>

// Create an empty card set.
CardSet::CardSet(){
    
}

// Add a card number to the CardSet.  Return true if and only if the
// card number was actually added.
bool CardSet::add(unsigned long cardNumber){
    return m_set.insert(cardNumber);
}

// Return the number of card numbers in the CardSet.
int CardSet::size() const{
    return m_set.size();
}

// Write to cout every card number in the CardSet exactly once, one
// per line.  Write no other text.
void CardSet::print() const{
    unsigned long cardNum;
    for(int i = 0; i < size(); i++){
        m_set.get(i, cardNum);
        std::cout << cardNum << std::endl;
    }
}
