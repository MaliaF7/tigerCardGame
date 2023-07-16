#include "Card.h"

Card::Card(int rank, Color color) : rank(rank), color(color) {
    // checks color
    if (color == purple){ 
        // checks rank for purple, sets value
        value = rank;
    }
    else if (color == orange) {
        // makes orange double 
        value = rank *2;
    }
    else {
        value = 20;
    }
};

std::string Card::printCard () {
    std::string cardString;
    // make our card colors printable
    if (color == purple){
        cardString = "purple";
    }
    else if (color == orange){
        cardString = "orange";
    }
    else {
        cardString = "tiger";
    }
    // prints card in the format we want
    return cardString + ":" + std::to_string(rank);
};

int Card::getRank() const {
    return rank;
};

Card::Color Card::getColor() const{
    return color;
};

int Card::getValue() const {
    return value;
};