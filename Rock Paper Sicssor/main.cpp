#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

// returns either 'r', 'p', or 's' for rock, paper or scissors
char get_computers_choice() {

    // generate random number based on time
    srand(time(NULL));
  
    int random_number = (rand() % 3) + 1;
    char computers_choice;

    switch(random_number) {

        case 1:
            computers_choice = 'r';
            break;

        case 2:
            computers_choice = 'p';
            break;

        case 3:
            computers_choice = 's';
            break;
    }

    return computers_choice;
}

// take user input and return it
// function to get user input
char get_user_input() {

    char user_input;

    cout << "Enter Your Choice (r for rock, p for paper, s for scissors): ";
    cin >> user_input;
  
    user_input = tolower(user_input);

    return user_input;
}

// return either 'w', 'l' or 'd' for win, loss and draw
char get_result(char user_pick, char computer_pick) {

    // condition for user to draw
    if (computer_pick == user_pick) {
        return 'd';
    }

    // condition for user to win
    else if (user_pick == 'p' && computer_pick == 'r') {
        return 'w';
    }
    else if (user_pick == 'r' && computer_pick == 's') {
        return 'w';
    }
    else if (user_pick == 's' && computer_pick == 'p') {
        return 'w';
    }

    // all other conditions result in user losing
    else {
        return 'l';
    }
}

int main() {

    // get computer choice
    char computer_pick = get_computers_choice();

    // get input until user enters 'r', 'p' or 's'
    char user_pick;
    while (1) {
        user_pick = get_user_input();
        if (user_pick == 'r' || user_pick == 'p' || user_pick == 's') {
            break;
        }
    }

    char result = get_result(user_pick, computer_pick);

    // print computer_pick and user_pick
    cout << "Computer's pick: " << computer_pick << endl;
    cout << "Your pick: " << user_pick << endl;

    // print the result
    switch(result) {

        case 'w':            
            cout << "You won" << endl;
            break;

        case 'l':
            cout << "You lost" << endl;
            break;

        case 'd':
            cout << "Draw" << endl;
            break;
    }

    return 0;
}