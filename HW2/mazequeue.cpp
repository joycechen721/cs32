#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec);

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

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    queue<Coord> coordQueue;
    Coord a(sr, sc);
    if(maze[sr][sc] == '.'){
        coordQueue.push(a);
        maze[sr][sc] = '#';
    }
    while(!coordQueue.empty()){
        Coord curr = coordQueue.front();
        coordQueue.pop();
        int r = curr.r();
        int c = curr.c();
        if(r == er && c == ec){
            return true;
        }
        //check east
        if(c+1 < nCols && maze[r][c+1] == '.'){
            Coord next(r, c+1);
            coordQueue.push(next);
            maze[r][c+1] = '#';
        }
        //check north
        if(r-1 >= 0 && maze[r-1][c] == '.'){
            Coord next(r-1, c);
            coordQueue.push(next);
            maze[r-1][c] = '#';
        }
        //check west
        if(c-1 >= 0 && maze[r][c-1] == '.'){
            Coord next(r, c-1);
            coordQueue.push(next);
            maze[r][c-1] = '#';
        }
        //check south
        if(r+1 < nRows && maze[r+1][c] == '.'){
            Coord next(r+1, c);
            coordQueue.push(next);
            maze[r+1][c] = '#';
        }
//        Coord top = coordQueue.front();
//        cout << "(" << top.r() << ", " << top.c() << ")" << endl;
    }
    return false;
}
