// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;
    int dir[8][2] = {{1,2},{2,1},{-1,2},{-1,-2},{1,-2},{-2,1},{2,-1},{-2,-1}};
    char column = knight[0];
    char row = knight[1];
    for (int i=0;i<8;i++) {
        char new_column = column + dir[i][0];
        char new_row = row + dir[i][1];
        if (new_column < 'a' || new_column > 'h' || new_row < '0' || new_row > '8') {
            continue;
        }
        std::string move = "";
        moves.push_back(move+new_column+new_row);
    }

    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}