#include "newSet.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Set s;
    assert(s.insert("roti"));
    assert(s.insert("pita"));
    assert(s.size() == 2);
    assert(s.contains("pita"));
    ItemType x = "laobing";
    assert(s.get(0, x)  &&  x == "pita");
    assert(s.get(1, x)  &&  x == "roti");

    Set ss;
    ss.insert("lavash");
    ss.insert("roti");
    ss.insert("chapati");
    ss.insert("injera");
    ss.insert("roti");
    ss.insert("matzo");
    ss.insert("injera");
    assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
    string str;
    ss.get(0, str);
    assert(str == "chapati");  // "chapati" is greater than exactly 0 items in ss
    ss.get(4, str);
    assert(str == "roti");  // "roti" is greater than exactly 4 items in ss
    ss.get(2, str);
    assert(str == "lavash");  // "lavash" is greater than exactly 2 items in ss
    Set ss1;
    ss1.insert("laobing");
    Set ss2;
    ss2.insert("matzo");
    ss2.insert("pita");
    ss1.swap(ss2);
    assert(ss1.size() == 2  &&  ss1.contains("matzo")  &&  ss1.contains("pita")  &&
    ss2.size() == 1  &&  ss2.contains("laobing"));
    assert(ss.erase("roti") && !ss.contains("roti"));
    assert(ss.erase("injera") && !ss.contains("injera"));
    assert(ss.size() == 3);

    Set sss;
    sss.insert("dosa");
    assert(!sss.contains(""));
    sss.insert("tortilla");
    sss.insert("");
    sss.insert("focaccia");
    assert(sss.contains(""));
    sss.erase("dosa");
    assert(sss.size() == 3  &&  sss.contains("focaccia")  &&  sss.contains("tortilla")  && sss.contains("") && !sss.contains("dosa"));
    string v;
    assert(sss.get(1, v)  &&  v == "focaccia");
    assert(sss.get(2, v) && v == "tortilla");
    assert(sss.get(0, v)  &&  v == "");

    sss.swap(s);
    assert(sss.size() == 2 && s.size() == 3);
    assert(sss.contains("pita") && s.contains("tortilla"));
    assert(s.erase("tortilla") && !s.erase("tortilla"));
    sss.swap(s);
    assert(!sss.contains("tortilla"));

    Set a = s;
    assert(a.size() == 2);
    assert(a.contains("pita"));
    ItemType t = "laobing";
    assert(s.get(0, t)  &&  t == "pita");
    assert(s.get(1, t)  &&  t == "roti");

    a = ss;
    a.insert("injera");
    a.insert("roti");
    assert(a.size() == 5);  // duplicate "roti" and "injera" were not added
    string q;
    a.get(0, q);
    assert(q == "chapati");  // "chapati" is greater than exactly 0 items in ss
    a.get(4, q);
    assert(q == "roti");  // "roti" is greater than exactly 4 items in ss
    a.get(2, q);
    assert(q == "lavash");
}

int main()
{
    test();
//    cout << "Passed all tests" << endl;
}
