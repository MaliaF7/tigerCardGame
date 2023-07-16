#include "Deck.h"

Deck::Deck() {
    // establish two card colors (makes it simpler here)
    Card::Color purple = Card::purple;
    Card::Color orange = Card::orange;
    Card::Color tiger = Card::tiger;


        // make 10 purple cards
        // add to the deck
        for (int cardNum =1; cardNum <=10; cardNum++){
            Card purpleCard(cardNum, purple);
            deck.push_back(purpleCard);
            
        }

        // make 10 orange cards
        // add to the deck
        for (int cardNum =1; cardNum <=10; cardNum++){
            Card orangeCard(cardNum, orange);
            deck.push_back(orangeCard);
            
        }

        // make the tiger card
        // add it to the deck
        Card tigerCard(10, tiger);
        deck.push_back(tigerCard);
        
}

// randomly shuffle the deck
void Deck::shuffle(){
    std::srand(unsigned(std::time(0)));
    std::random_shuffle(deck.begin(), deck.end());

}

// draw a card from the top of deck
Card Deck::drawCard(){
    Card cardIsDrawn = deck.front();
    deck.erase(deck.begin());
    return cardIsDrawn;

}

int Deck::getDeckSize(){
    return deck.size();
}


