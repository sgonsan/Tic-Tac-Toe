#include <iostream>
#include <vector>

const int SIZE = 3;
std::vector<std::vector<char>> board(SIZE, std::vector<char>(SIZE, ' '));

/**
 * @brief Prints the current state of the Tic-Tac-Toe board to the console.
 *
 * This function iterates through the board array and prints each cell's value.
 * It also formats the board with vertical and horizontal separators to enhance
 * readability.
 *
 * Example output for a 3x3 board:
 * X | O | X
 * ---------
 * O | X | O
 * ---------
 * X | O | X
 */
void printBoard() {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      std::cout << board[i][j];
      if (j < SIZE - 1) std::cout << " | ";
    }
    std::cout << std::endl;
    if (i < SIZE - 1) std::cout << "---------" << std::endl;
  }
}

/**
 * @brief Checks if the specified player has won the game.
 *
 * This function checks all possible winning conditions for the given player
 * on a Tic-Tac-Toe board. It verifies rows, columns, and both diagonals.
 *
 * @param player The character representing the player ('X' or 'O').
 * @return true if the player has won the game, false otherwise.
 */
bool checkWin(char player) {
  for (int i = 0; i < SIZE; ++i) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
      return true;
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
      return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    return true;
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    return true;
  return false;
}

/**
 * @brief Checks if the game board is in a draw state.
 *
 * This function iterates through the entire game board and checks if there are
 * any empty spaces left. If there are no empty spaces, it returns true
 * indicating that the game is a draw. Otherwise, it returns false.
 *
 * @return true if the game board is full and the game is a draw, false
 * otherwise.
 */
bool isDraw() {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if (board[i][j] == ' ') return false;
    }
  }
  return true;
}

void clear() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

int main() {
  char player = 'X';
  int row, col;
  while (true) {
    clear();
    printBoard();
    std::cout << "Player " << player << ", enter row and column (1 1 -> 3 3): ";
    std::cin >> row >> col;
    row--;
    col--;
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
      std::cout << "Invalid row or column. Try again." << std::endl;
      continue;
    }
    if (board[row][col] != ' ') {
      std::cout << "Cell already occupied. Try again." << std::endl;
      continue;
    }
    board[row][col] = player;
    if (checkWin(player)) {
      clear();
      printBoard();
      std::cout << "Player " << player << " wins!" << std::endl;
      break;
    }
    if (isDraw()) {
      clear();
      printBoard();
      std::cout << "It's a draw!" << std::endl;
      break;
    }
    player = (player == 'X') ? 'O' : 'X';
  }
  return 0;
}