//
//  tree.cpp
//  Homework3
//
//  Created by Joyce Chen on 2/11/23.
//

//#include <iostream>
//using namespace std;

// Return the number of ways that all n1 elements of a1 appear in
// the n2 element array a2 in the same order (though not necessarily
// consecutively).  We decree that the empty sequence (i.e. one where
// n1 is 0) appears in a sequence of length n2 in 1 way, even if n2
// is 0.  For example, if a2 is the 7 element array
//    10 10 10 10 10 10 10
// then for this value of a1     the function must return
//    10                              1
//    10 40 30                        2
//    20 10 40                        0
//    50 40 30                        3
int countIsIn(const double a1[], int n1, const double a2[], int n2)
{
    if(n1 == 0) return 1;
    if(n2 == 0) return 0;
    int count = 0;
    if(*a1 == *a2){
      count = countIsIn(a1+1, n1-1, a2+1, n2-1);
    }
    count += countIsIn(a1, n1, a2+1, n2-1);
    return count;
}

// Exchange two doubles
void exchange(double& x, double& y)
{
    double t = x;
    x = y;
    y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is > divider come before all the other elements,
// and all the elements whose value is < divider come after all
// the other elements.  Upon return, firstNotGreater is set to the
// index of the first element in the rearranged array that is
// <= divider, or n if there is no such element, and firstLess is
// set to the index of the first element that is < divider, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotGreater, a[i] > divider
//   * for firstNotGreater <= i < firstLess, a[i] == divider
//   * for firstLess <= i < n, a[i] < divider
// All the elements > divider end up in no particular order.
// All the elements < divider end up in no particular order.
void divide(double a[], int n, double divider, int& firstNotGreater, int& firstLess)
{
   if (n < 0)
   n = 0;

//      It will always be the case that just before evaluating the loop
    //      condition:
    //       firstNotGreater <= firstUnknown and firstUnknown <= firstLess
    //       Every element earlier than position firstNotGreater is > divider
    //       Every element from position firstNotGreater to firstUnknown-1 is
    //         == divider
    //       Every element from firstUnknown to firstLess-1 is not known yet
    //       Every element at position firstLess or later is < divider

   firstNotGreater = 0;
   firstLess = n;
   int firstUnknown = 0;
   while (firstUnknown < firstLess)
   {
       if (a[firstUnknown] < divider)
       {
           firstLess--;
           exchange(a[firstUnknown], a[firstLess]);
       }
       else
       {
           if (a[firstUnknown] > divider)
           {
               exchange(a[firstNotGreater], a[firstUnknown]);
               firstNotGreater++;
           }
           firstUnknown++;
       }
   }
}

 // Rearrange the elements of the array so that
 // a[0] >= a[1] >= a[2] >= ... >= a[n-2] >= a[n-1]
 // If n <= 1, do nothing.
void order(double a[], int n)
{
    if(n <= 1) return;
    int firstNotGreater;
    int firstLess;
    int divider = a[n/2];
    divide(a, n, divider, firstNotGreater, firstLess);
    order(a, firstNotGreater+1);
    order(a+firstLess, n-firstLess);
}

//int main(){
////    double a1[] = {20, 50, 30, 40};
//    double a2[] = {10, 50, 40, 20, 50, 40, 30};
//    order(a2, 7);
//    for(int i = 0; i < 7; i++)
//        cout << a2[i] << endl;
//}
