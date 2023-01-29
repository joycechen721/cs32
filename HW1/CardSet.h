//
//  CardSet.h
//  Proj2
//
//  Created by Joyce Chen on 1/18/23.
//

#ifndef CardSet_h
#define CardSet_h

#include <stdio.h>
#include "Set.h"

class CardSet
{
    public:
        CardSet();          // Create an empty card set.

        bool add(unsigned long cardNumber);
         // Add a card number to the CardSet.  Return true if and only if the
         // card number was actually added.

        int size() const;  // Return the number of card numbers in the CardSet.

        void print() const;
         // Write to cout every card number in the CardSet exactly once, one
         // per line.  Write no other text.

    private:
        Set m_set;
};

#endif /* CardSet_h */
