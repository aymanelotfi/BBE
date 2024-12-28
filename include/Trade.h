#ifndef TRADE_H
#define TRADE_H

#include<iostream>
#include<sstream>
#include<vector>

enum class Side{
    BID,
    SELL
};

std::ostream& operator<< (std::ostream& os, Side side){
    os << (side == Side::BID ? "BID" : "SELL");
    return os;
}

struct Trade{
    std::string ric;
    uint64_t ts;
    float price;
    uint32_t volume;
    Side side;

    void print() const {
        std::cout << "Instrument: " << ric << std::endl;
        std::cout << "Time: " << ts << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Volume: " << volume << std::endl;
        std::cout << "Side: " << side << std::endl;
    }
};

#endif