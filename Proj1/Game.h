//
//  Game.h
//  Proj1
//
//  Created by Joyce Chen on 1/11/23.
//

#ifndef Game_h
#define Game_h
#include <string>

class Arena;
bool recommendMove(const Arena& a, int r, int c, int& bestDir);
int computeDanger(const Arena& a, int r, int c);

class Game
{
  public:
      // Constructor/destructor
    Game(int rows, int cols, int nRabbits);
    ~Game();

      // Mutators
    void play();

  private:
    Arena* m_arena;

      // Helper functions
    std::string takePlayerTurn();
};

#endif /* Game_h */
