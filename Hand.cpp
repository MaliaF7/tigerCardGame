#include "Hand.h"

Hand::Hand (){};

// fill your hand
Hand::Hand (Deck &deck, int N){
    for (int i=1; i<=N; i++){
        hand.push_back(deck.drawCard());
    }
    
}

// print hand in the correct format
std::string Hand::printHand(){
    std::string printedHand = "";
    int size = hand.size();
    for (int i=0; i<size; i++){
        printedHand += "["+std::to_string(i+1)+"] "+hand[i].printCard() +" ";
    }
    return printedHand;
}

// deal card 
// erase the card once dealt
Card Hand::dealCard(int num){
    Card card = hand[num-1];
    hand.erase(hand.begin() + (num-1));
    return card;
}

int Hand::getHandSize(){
    return hand.size();
}
