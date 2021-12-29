#include <iostream>
using namespace std;

// Global constants to represent rock,
// paper, or scissors.
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int QUIT = 4;

// Function Prototypes
int getUserChoice();
int getComputerChoice();
void determineWinner(int, int);
void displayChoice(int, int); // possible pass by reference

int main()
{
    srand(time(0));

    int userChoice; // To hold the user's choice
    int computerChoice; // To hold the computer's choice

    cout << "game menu\n"
        << "----------\n"
        << "1.) rock\n"
        << "2.) paper\n"
        << "3.) scissors\n"
        << "4.) quit\n";
    cout << endl;    

    // Get the computer's choice.
    computerChoice = getComputerChoice();

    // Get the user's choice.
    userChoice = getUserChoice();
    displayChoice(userChoice, computerChoice);
    determineWinner(userChoice, computerChoice);


    while (userChoice != 4)
    {
        // Determine the winner.
        determineWinner(userChoice, computerChoice);

        // Get the computer's choice.
        computerChoice = getComputerChoice();

        // Get the user's choice.
        userChoice = getUserChoice();

    } //end while

    cout << "Thanks for playing!\n\n";

    system("pause");
    return 0;
} //end main

int getComputerChoice()
{
    int random;

    random = rand() % 3 + 1; // random number generator

    return random;
}

int getUserChoice()
{
    int g_userChoice;

    cout << "Enter your choice: ";
    cin >> g_userChoice;

    return g_userChoice;
}

void determineWinner(int userChoice, int computerChoice)
{
    if (userChoice == ROCK && computerChoice == SCISSORS)
    {
        cout << "You win! Rock smashes scissors.";
    }
    else if (userChoice == PAPER && computerChoice == ROCK)
    {
        cout << "You win! Paper covers rock.";
    }
    else if (userChoice == SCISSORS && computerChoice == PAPER)
    {
        cout << "You win! Scissors cut paper.";
    }
    else
    {
        cout << "Tie. No winner.";
    }
}

void displayChoice(int userChoice, int computerChoice)
{
    switch (userChoice)
    {
        case 1:
            cout << "You selected rock.\n";
            break;
        case 2:
            cout << "You selected paper.\n";
            break;
        case 3:
            cout << "You selected scissors.\n";
            break;
        default:
            cout << "You decided to quit, pansy.\n";
    }

    switch (computerChoice)
    {
        case 1:
            cout << "The computer selected rock.\n";
            break;
        case 2:
            cout << "The computer selected paper.\n";
            break;
        case 3:
            cout << "The computer selected scissors.\n";
            break;
    }
}