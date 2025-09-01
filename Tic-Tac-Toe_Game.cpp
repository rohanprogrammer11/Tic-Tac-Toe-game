#include<iostream> // Used to handle input and output.
#include<string> // Used to handle String data types.

using namespace std; // Avoid writing std:: before every standard library function or object.

// Declare Golbal Variables

char board[3][3]; // 3x3 board to store X,O or number.

string player_1 , player_2; //Name of two Players.
char currentPlayer = 'x'; // 'x' goes frist.

// Initialize the Board

void initializeBoard(){
    for(int i = 0; i < 3; i++){ // Loop through rows (0 to 2).
        for(int j = 0; j < 3; j++){ // Loop through columns (0 to 2).
            board[i][j] = '1' + i * 3 + j; // fill board with number 1-9.
        }
    }
}

// Display the Board

void displayBoard(){

    cout << "\n"; // Print a new line for better readability.
    
    for(int i = 0; i < 3; i++){
        cout << " ";
        for(int j = 0; j < 3; j++){
            cout << board[i][j]; // Print each cell in the row.
            if(j < 2)
                cout << " | "; // Print column separator.
        }
        cout << "\n"; // Move to the next line after each row.
        if(i < 2)
            cout << "---+---+---\n"; // Print row separator.
    }
    cout << " \n "; // Print a new line for better readability.
}

// Get the Current Player's Name (Ternary Oprators)

string getCurrentPlayerName(){
    return (currentPlayer == 'x') ? player_1 : player_2; // If currentPlayer is 'x', return player_1's name, else return player_2's name.
}

// Make a Move

bool makemove(){
    int move;
    cout << getCurrentPlayerName() << " << Current player >> , Enter your move (1-9):  ";
    cin >> move; // Get the move from the player.

    if (move < 1 || move > 9){
        return false; // Invalid move.
    }

    int row = (move - 1) / 3; // Calculate the row index.
    int col = (move - 1) % 3; // Calculate the column index.

    if(board[row][col] == 'x' || board[row][col] == 'o'){
        return false; // Cell already occupied.
    }

    board[row][col] = currentPlayer; // Place the current player's mark on the board.
        return true; // Move successful.
    
}

// Check for a Win

bool CheckWin(){
    // Check rows and columns
    for(int i = 0; i < 3; i++){
        if((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) || 
           (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)){
            return true; // Current player wins.
        }
    }

    // Check diagonals
    if((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) || 
       (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)){
        return true; // Current player wins.
    }

    return false; // No win detected.
}

// check for a draw 

bool checkDraw(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 'x' && board[i][j] != 'o'){
                return false; // Found an empty cell, not a draw.
            }
        }
    }
    return true; // No empty cells, it's a draw.
}

// Switch Player

void switchPlayer(){
    currentPlayer = (currentPlayer == 'x') ? 'o' : 'x'; // Switch between 'x' and 'o'.
}

// Main Function

int main(){
    cout << "Enter name of Player 1 (x): ";
    getline(cin, player_1); // Get first player name.

    cout << "Enter name of Player 2 (o): ";
    getline(cin, player_2); // Get Second player name.

    initializeBoard(); // Initialize the game board.
    bool gameOver = false; // Game over flag.

    while(!gameOver){
        displayBoard(); // Display the current board.
        if(!makemove()){
            cout << "Invalid move! Try again.\n"; // Prompt for invalid move.
            continue; // Skip to the next iteration of the loop.
        }

        if(CheckWin()){
            displayBoard(); // Display the final board.
            cout << getCurrentPlayerName() << " wins! Congratulations!\n"; // Announce the winner.
            gameOver = true; // Set game over flag.
        } else if(checkDraw()){
            displayBoard(); // Display the final board.
            cout << "It's a draw!\n"; // Announce a draw.
            gameOver = true; // Set game over flag.
        } else {
            switchPlayer(); // Switch to the other player.
        }
    }
    return 0;
}