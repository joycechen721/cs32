//
//  History.cpp
//  Proj1
//
//  Created by Joyce Chen on 1/11/23.
//

#include <stdio.h>
#include "History.h"
#include <iostream>
#include <string>
using namespace std;

History::History(int nRows, int nCols){
    rows = nRows;
    cols = nCols;
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            m_grid[i][j] = 'A';
        }
    }
}

bool History::record(int r, int c){
    if(r > rows || c > cols || r < 1 || c < 1){
        return false;
    }
    if(m_grid[r-1][c-1] - 1 != 'Z'){
        m_grid[r-1][c-1]++;
    }
    return true;
}

void History::display() const{
    char displayGrid[MAXROWS][MAXCOLS];
    int r, c;
    
      // Fill displayGrid with dots (empty) and letters (# of poisoned carrots)
    for (r = 1; r <= rows; r++){
        for (c = 1; c <= cols; c++){
            displayGrid[r-1][c-1] = (m_grid[r-1][c-1] == 'A' ? '.' : m_grid[r-1][c-1] - 1);
        }
    }
    
    // Draw the grid
    for (r = 1; r <= rows; r++)
    {
      for (c = 1; c <= cols; c++)
          cout << displayGrid[r-1][c-1];
      cout << endl;
    }
    cout << endl;
}
