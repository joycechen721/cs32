//
//  maze.cpp
//  Homework3
//
//  Created by Joyce Chen on 2/11/23.
//

//#include <iostream>
//#include <string>
//using namespace std;

class Coord
{
    public:
      Coord(int r, int c) : m_row(r), m_col(c) {}
      int r() const { return m_row; }
      int c() const { return m_col; }
    private:
      int m_row;
      int m_col;
};

//If the start location is equal to the ending location, then we've
//        solved the maze, so return true.
//    Mark the start location as visted.
//    For each of the four directions,
//        If the location one step in that direction (from the start
//            location) is unvisited,
//                then call pathExists starting from that location (and
//                            ending at the same ending location as in the
//                            current call).
//                     If that returned true,
//                         then return true.
//    Return false.
bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    if(sr == er && sc == ec) return true;
    maze[sr][sc] = '#';
    //east
    if(sc+1 < nCols && maze[sr][sc+1] == '.')
        if(pathExists(maze, nRows, nCols, sr, sc+1, er, ec)) return true;
    //north
    if(sr-1 >= 0 && maze[sr-1][sc] == '.')
        if(pathExists(maze, nRows, nCols, sr-1, sc, er, ec)) return true;
    //west
    if(sc-1 >= 0 && maze[sr][sc-1] == '.')
        if(pathExists(maze, nRows, nCols, sr, sc-1, er, ec)) return true;
    //south
    if(sr+1 < nRows && maze[sr+1][sc] == '.')
        if(pathExists(maze, nRows, nCols, sr+1, sc, er, ec)) return true;
    return false;
}

//int main()
//{
//   string maze[10] = {
//       "XXXXXXXXXX",
//       "X..X...X.X",
//       "X.XXXX.X.X",
//       "X.X.X..X.X",
//       "X...X.XX.X",
//       "XXX......X",
//       "X.X.XXXX.X",
//       "X.XXX....X",
//       "X...X..X.X",
//       "XXXXXXXXXX"
//   };
//
//    if (pathExists(maze, 10,10, 5,3, 8,8))
//       cout << "Solvable!" << endl;
//   else
//       cout << "Out of luck!" << endl;
//}
