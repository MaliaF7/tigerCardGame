/*  Malia Fairbanks
    CPSC 1020 | 9am section
    Dan Wooster
    April 6, 2023
    TIGER GAME !!!
*/

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
using namespace std;


int main() {
  cout << "************************************" <<endl;
  cout << "      WELCOME TO TIGER GAME!" << endl;
  cout << "************************************" <<endl;
  cout << "" <<endl;
  // random variables 
  char playAgain = 'y';
  int roundCounter=0;
  int computerWinCounter =0;
  int humanWinCounter=0;
  int humanTotal =0;
  int computerTotal=0;
  vector <int> humanRoundScores;
  vector<int> computerRoundScores; 

  while (playAgain =='y'){
    int tigerPlayed =0;
    int input;
    int roundNum =0;
    int computerScore = 0;
    int humanScore = 0;
    // Create a deck of cards and shuffle it.
    Deck deckOfCards;
    deckOfCards.shuffle();

    // Ask the player to set the number of cards/rounds
    cout << "How many cards should each player pick up? ";
    cin >> roundNum;
    cout << "The deck was shuffled and each player has drawn "<< roundNum << " cards.\n";

    // Create two players, each with user input number of cards
    Player computer(deckOfCards, roundNum);
    Player human(deckOfCards, roundNum);
    int size = human.hand.getHandSize();
    if (tigerPlayed ==0){
    // loops through the rounds
      for (int round=1; round<=roundNum; round++){  

          cout << "\nRound " << round <<endl;
          cout << "------------" <<endl;

          // computer plays a card
          Card computerCard = computer.hand.dealCard(1);
          cout << "The computer plays: " << computerCard.printCard() <<endl;
        
          // tiger card rules for computer
          if (computerCard.printCard()=="tiger:10"){
            tigerPlayed =1;
            cout << "TIGER CARD!!" <<endl;
            computerWinCounter++;
            computerScore += computerCard.getValue();
            humanRoundScores.push_back(0);
            computerRoundScores.push_back(computerScore);
            break;
          }

        
          // human checks hand
          cout << "Your hand: "<<  human.hand.printHand() << endl;

          // ask human to play
          cout << "Which card do you want to play? ";
          cin >> input;

          // check that you can actually pick that card
          while (input > size || input < 1) {
            cout << "Sorry, that is an invalid input, please try again!";
            cin >> input;
          
          }

          // human plays a card
          Card humanCard = human.hand.dealCard(input);
          cout << "You played: "<< humanCard.printCard() <<endl;

          // tiger card rules for human
          if (humanCard.printCard()=="tiger:10"){
            tigerPlayed =1;
            cout << "TIGER CARD!!" <<endl;
            humanWinCounter++;
            humanScore += humanCard.getValue();
            humanRoundScores.push_back(humanScore);
            computerRoundScores.push_back(0);
            break;
          }

          // compare cards
          // determine who wins the round based on scores
          if (computerCard.getValue() > humanCard.getValue()) {
              computerScore += computerCard.getValue() + humanCard.getValue();
              cout << "Computer wins the round!" << endl;
          } 
          else if (humanCard.getValue() > computerCard.getValue()) {
              humanScore += computerCard.getValue() + humanCard.getValue();
              cout << "You win the round!" << endl;
          } 
          else {
              cout << "Tie round! No one wins." << endl;
          }

          // print the current scores after the round
          // rolling total, continues to add on itself
          cout << "\nCurrent scores:" <<endl;
          cout << "Human: " << humanScore <<endl;
          cout << "Computer: " <<computerScore <<endl;
          humanRoundScores.push_back(humanScore);
          computerRoundScores.push_back(computerScore);

          
      }  
    }
        // print final score
        // determine winner
        cout << "FINAL SCORE:"<<endl;
        cout << "Human: " << humanScore << endl;
        cout << "Computer: " << computerScore << endl;
        if (computerScore > humanScore) {
            cout << "\nThe computer has won!" << endl;
            computerWinCounter++;
        } 
        else if (humanScore > computerScore) {
            cout << "\nYou have won!" << endl;
            humanWinCounter++;
        } 
        else {
            cout << "\nIt's a tie!" << endl;
        }
      cout << "Do you want to play again? (y/n)";
      cin >> playAgain;
      humanTotal += humanScore;
      computerTotal += computerScore;
      roundCounter++; 
  }
    // print the final summary of all the rounds and games
    cout << "\n************************************" <<endl;
    cout << "             SUMMARY" <<endl;
    cout << "************************************" <<endl;
    cout << "Rounds Played: "<<roundCounter <<endl;
    cout << "Number of Rounds Computer Won: "<<computerWinCounter<<endl;
    cout << "Number of Rounds Human Won: "<<humanWinCounter <<endl;
    cout << "Total Computer points scored: " << computerTotal << endl;
    cout << "Total Human points scored: "<< humanTotal << endl;
    cout << "\nRound Recap"<<endl;
    cout << "-----------"<<endl;
    for (int i =1; i<=roundCounter; i++){
      cout << "Round " << i << ": "<<endl;
      cout << "Human: "<<humanRoundScores[i] <<endl;
      cout << "Computer: "<<computerRoundScores[i]<<endl;
      cout <<endl;

  }
  return 0;
}
