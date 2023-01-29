//
//  testCardSet.cpp
//  Proj2
//
//  Created by Joyce Chen on 1/18/23.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <cassert>
#include "CardSet.h"
using namespace std;

void test(){
    CardSet cs;
    assert(cs.add(100) && cs.add(200) && cs.add(150) && !cs.add(100));
    assert(cs.size() == 3);
    CardSet c = cs;
    assert(c.size() == 3);
    c.print();
    CardSet cards;
    c = cards;
    assert(c.size() == 0 && c.add(300) && !c.add(300) && c.add(400) && c.size() == 2);
    assert(cards.add(500) && cards.add(600) && cards.add(880));
    c = cards;
    assert(c.size() == 3);
    c.print();
}

int main(){
    test();
//    cout << "Passed all TESTS!" << endl;
}
