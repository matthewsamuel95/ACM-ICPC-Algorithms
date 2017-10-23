#include <iostream>
#define N 8
using namespace std;

// defines a structure for chess moves
typedef struct chess_moves {
   // 'x' and 'y' coordinates on chess board
   int x,y;
}chess_moves;

// displays the knight tour solution
void printTour(int tour[N][N]) {
   int i,j;
   for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
          cout<<tour[i][j]<<"\t";
      }
      cout<<endl;
   }
}

// check if the next move (as per knight's constraints) is possible
bool isMovePossible(chess_moves next_move, int tour[N][N]) {
   int i = next_move.x;
   int j = next_move.y;
   if ((i >= 0 && i < N) && (j >= 0 && j < N) && (tour[i][j] == 0))
      return true;
   return false;
}


// recursive function to find a knight tour
bool findTour(int tour[N][N], chess_moves move_KT[],
               chess_moves curr_move, int move_count) {
   int i;
   chess_moves next_move;
   if (move_count == N*N-1) {
      // Knight tour is completed i.e all cells on the
      // chess board has been visited by knight once 
      return true;
   }

   // try out the possible moves starting from the current coordinate
   for (i = 0; i < N; i++) {
      // get the next move
      next_move.x = curr_move.x + move_KT[i].x;
      next_move.y = curr_move.y + move_KT[i].y;

      if (isMovePossible(next_move, tour)) {
         // if the move is possible
         // increment the move count and store it in tour matrix
         tour[next_move.x][next_move.y] = move_count+1;
         if (findTour(tour, move_KT, next_move, move_count+1) == true) {
            return true;
         }
         else {
            // this move was invalid, try out other possiblities 
            tour[next_move.x][next_move.y] = 0;
         }
      }
   }
   return false;
}

// wrapper function
void knightTour() {
   int tour[N][N];
   int i,j;

   // initialize tour matrix
   for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
         tour[i][j] = 0;
      }
   }

   // all possible moves that knight can take
   chess_moves move_KT[8] = { {2,1},{1,2},{-1,2},{-2,1},
                              {-2,-1},{-1,-2},{1,-2},{2,-1} };

   // knight tour starts from coordinate (0,0)
   chess_moves curr_move = {0,0};

   // find a possible knight tour using a recursive function
   // starting from current move 
   if(findTour(tour, move_KT, curr_move, 0) == false) {
      cout<<"Knight tour does not exist for the 8 x 8 board\n";
   }
   else {
      cout<<"Tour exists for the 8 x 8 board\n";
      printTour(tour);
   }
}

// main
int main() {
   knightTour();
   cout<<endl;
   return 0;
}
