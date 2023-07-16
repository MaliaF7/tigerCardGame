#ifndef CARD_H_
#define CARD_H_

#include <string>

// The Card class 
class Card {
    public:
        Card() = default;
        enum Color {purple, orange, tiger};
        Card(int rank, Color color);
        std::string printCard();
        int getRank() const;
        Color getColor() const;
        int getValue() const;
    private:
        int rank {0};
        Color color {purple};
        int value {0};
        
    


};
  

#endif // CARD_H_
