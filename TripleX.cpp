#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Game welcome message
    std::cout << "\nYou're an agent of AVALANCHE trying to break into Midgar's Mako reactor 5..." << std::endl;
    std::cout << "You encounter a level " << Difficulty << " strength blast door" << std::endl;
    std::cout << "You need to enter the correct codes to gain entry..." << std::endl;
}

// Function for game loop
bool PlayGame(int Difficulty)
{
    //Calling introduction function
    PrintIntroduction(Difficulty);

    // Declares 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    // Declares sum and product of 3 numbers
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Outputs hints for guessing code
    std::cout << "\nHINTS" << std::endl;
    std::cout << "There are 3 numbers in the code" << std::endl;
    std::cout << "The sum of the 3 numbers is " << CodeSum << std::endl;
    std::cout << "The product of the 3 numbers is " << CodeProduct << std::endl;
    
    // Declares variables to store player input
    int PlayerGuessNumA;
    int PlayerGuessNumB;
    int PlayerGuessNumC;

    // Capturing player input
    std::cout << "\nPlease enter the first number of the code: ";
    std::cin >> PlayerGuessNumA;
    std::cout << "Please enter the second number of the code: ";
    std::cin >> PlayerGuessNumB;
    std::cout << "Please enter the second number of the code: ";
    std::cin >> PlayerGuessNumC;
    std::cout << "\nYou entered: " << PlayerGuessNumA << " " << PlayerGuessNumB << " " << PlayerGuessNumC << std::endl;

    // Declares variables to validate player input
    int PlayerGuessSum = PlayerGuessNumA + PlayerGuessNumB + PlayerGuessNumC;
    int PlayerGuessProduct = PlayerGuessNumA * PlayerGuessNumB * PlayerGuessNumC;

    // Checking win condition
    if ((PlayerGuessSum == CodeSum) && (PlayerGuessProduct == CodeProduct))
    {
        // Level completed message
        std::cout << "\nCode accepted! You're in, proceed to the next blast door" << std::endl;
        return true;
    }
    else
    {
        // Game over message
        std::cout << "\nInvalid code, try again!" << std::endl;
        std::cout << "But be careful, too many wrong guesses will activate the automated defense system." << std::endl;
        return false;
    }
}

int main()
{
    srand(time(NULL)); // This creates new random numbers every playthrough using computers time
    int LevelDifficulty = 1; //Starting level
    const int MaxDifficulty = 5; //Max level

    while (LevelDifficulty <= MaxDifficulty)// Loops until max difficulty is reached
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    // Victory message 
    std::cout << "\nYou've reached the reactor core" << std::endl;
    std::cout << "Hurry and plant the explosives then get out of there!" << std::endl;
    std::cout << "Congratulations, you have successfully infiltrated Mako reactor 5!" << std::endl;
    
    return 0;
}