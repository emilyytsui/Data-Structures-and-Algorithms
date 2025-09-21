//Lesson4a.cpp            Author: Emily Tsui
//An enumerated type for pieces on a chessboard, 2-D array for the board, fills the board

#include <iostream>
using namespace std;

enum ChessPieces
{
  Rook, //0
  Knight, //1
  Bishop, //2
  Queen, //3
  King, //4
  Pawn, //5
  Empty //6
};

int main() {
  ChessPieces chessboard[8][8]; 
  
 //Fill in top row
  chessboard [0][0] = Rook;
  chessboard [0][1] = Knight;
  chessboard [0][2] = Bishop;
  chessboard [0][3] = Queen;
  chessboard [0][4] = King;
  chessboard [0][5] = Bishop;
  chessboard [0][6] = Knight;
  chessboard [0][7] = Rook;
  
  //Fill in bottom row
  chessboard [7][0] = Rook;
  chessboard [7][1] = Knight;
  chessboard [7][2] = Bishop;
  chessboard [7][3] = Queen;
  chessboard [7][4] = King;
  chessboard [7][5] = Bishop;
  chessboard [7][6] = Knight;
  chessboard [7][7] = Rook;

  //Fill in pawns
  for(int j = 0; j < 8; j++){
    chessboard[1][j] = Pawn;
  }

  for(int j = 0; j < 8; j++){
    chessboard[6][j] = Pawn;
  }

  //Fill in empty spaces
  for(int i = 2; i <= 5; i++){
    for(int j = 0; j < 8; j++){
      chessboard[i][j] = Empty;
    }
  }
  
  //Print out chessboard
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      cout << chessboard[i][j];
    }
    cout << endl;
  }

  return 0;
}