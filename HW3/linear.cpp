//
//  linear.cpp
//  Homework3
//
//  Created by Joyce Chen on 2/10/23.
//

//#include <iostream>
//using namespace std;

//bool somePredicate(double x){
//    return x - 5 == 4;
//}

// Return true if the somePredicate function returns true for at
//     least one of the array elements; return false otherwise.
  bool anyTrue(const double a[], int n)
  {
      if(n == 0) return false;
      if(somePredicate(*a)) return true;
      return anyTrue(a+1, n-1);
  }

    // Return the number of elements in the array for which the
    // somePredicate function returns true.
  int countTrue(const double a[], int n)
  {
      if(n == 0) return 0;
      return somePredicate(*a) + countTrue(a+1, n-1);
  }

    // Return the subscript of the first element in the array for which
    // the somePredicate function returns true.  If there is no such
    // element, return -1.
  int firstTrue(const double a[], int n)
  {
      if(n == 0) return -1;
      if(somePredicate(*a)) return 0;
      return firstTrue(a+1, n-1) == -1 ? -1 : firstTrue(a+1, n-1) + 1;
  }

    // Return the subscript of the smallest element in the array (i.e.,
    // return the smallest subscript m such that a[m] <= a[k] for all
    // k from 0 to n-1).  If the function is told that no doubles are to
    // be considered in the array, return -1.
  int indexOfMinimum(const double a[], int n)
  {
      if(n == 0) return -1;
      if(n == 1) return 0;
      int num1 = indexOfMinimum(a, n/2);
      int num2 = n/2 + indexOfMinimum(a+n/2, n-n/2);
      return a[num1] <= a[num2] ? num1 : num2;
  }

    // If all n1 elements of a1 appear in the n2 element array a2, in
    // the same order (though not necessarily consecutively), then
    // return true; otherwise (i.e., if the array a1 is not a
    // not-necessarily-contiguous subsequence of a2), return false.
    // (Of course, if a1 is empty (i.e., n1 is 0), return true.)
    // For example, if a2 is the 7 element array
    //    10 50 40 20 50 40 30
    // then the function should return true if a1 is
    //    50 20 30
    // or
    //    50 40 40
    // and it should return false if a1 is
    //    50 30 20
    // or
    //    10 20 20
  bool isIn(const double a1[], int n1, const double a2[], int n2)
  {
      if(n1 == 0) return true;
      if(n2 == 0) return false;
      if(*a1 != *a2){
          return isIn(a1, n1, a2+1, n2-1);
      }
      return isIn(a1+1, n1-1, a2+1, n2-1);
  }

//int main(){
//    double a[] = {9};
//    double a2[] = {1,1,2,1,5,5,1,1};
//    cout << countTrue(a, 1) << endl;
//    cout << anyTrue(a, 7) << endl;
//    cout << firstTrue(a, 1) << endl;
//    cout << firstTrue(a2, 8) << endl;
//    cout << indexOfMinimum(a,7) << endl;
//
//    double a1[] = {4,5,2};
//    double a2[] = {1,2,4,5,5,9,1};
//    cout << isIn(a1, 3, a2, 7) << endl;
//}
