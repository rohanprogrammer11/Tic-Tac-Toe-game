#include <iostream> 
#include <string>   
using namespace std; 


char board[3][3];          // 3x3 board to store X, O, or number.
string player_1, player_2; // Names of two Players.
char currentPlayer = 'x';  // 'x' goes first.

// Initialize the Board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {     // Loop through rows (0 to 2).
        for (int j = 0; j < 3; j++) { // Loop through columns (0 to 2).
            board[i][j] = '1' + i * 3 + j; // Fill board with numbers 1–9.
        }
    }
}

// Display the Board
void displayBoard() {
    cout << "\n"; 

    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j]; 
            if (j < 2)
                cout << " | "; 
        }
        cout << "\n"; 
        if (i < 2)
            cout << "---+---+---\n"; 
    }
    cout << " \n "; 
}

// Get the Current Player's Name (Ternary Operator)
string getCurrentPlayerName() {
    return (currentPlayer == 'x') ? player_1 : player_2;
}

// Make a Move
bool makemove() {
    int move;
    cout << getCurrentPlayerName() << " (" << currentPlayer << "), enter your move (1-9): ";
    cin >> move; // Get the move from the player.

    if (move < 1 || move > 9) {
        return false; // Invalid move.
    }

    int row = (move - 1) / 3; 
    int col = (move - 1) % 3; 

    if (board[row][col] == 'x' || board[row][col] == 'o') {
        return false; // Cell already occupied.
    }

    board[row][col] = currentPlayer; 
    return true;                     // Move successful.
}

// Check for a Win
bool CheckWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true; // Current player wins.
        }
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true; // Current player wins.
    }

    return false; // No win detected.
}

// Check for a Draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'x' && board[i][j] != 'o') {
                return false; 
            }
        }
    }
    return true; 
}

// Switch Player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'x') ? 'o' : 'x';
}

// Main Function
int main() {
    cout << "Enter name of Player 1 (x): ";
    getline(cin, player_1);

    cout << "Enter name of Player 2 (o): ";
    getline(cin, player_2);

    char playAgain; 

    do {
        initializeBoard(); // Reset board
        currentPlayer = 'x'; // Reset first player
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();
            if (!makemove()) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (CheckWin()) {
                displayBoard();
                cout << getCurrentPlayerName() << " wins! Congratulations!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore(); 
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
