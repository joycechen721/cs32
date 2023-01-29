//
//  History.h
//  Proj1
//
//  Created by Joyce Chen on 1/11/23.
//

#ifndef History_h
#define History_h
#include "globals.h"

class History
{
    public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;
    private:
        char m_grid[MAXROWS][MAXCOLS];
        int rows;
        int cols;
};

#endif /* History_h */
