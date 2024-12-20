#ifndef TRADE_H
#define TRADE_H

#include<iostream>
#include<sstream>
#include<vector>


struct Trade{
    int timestamp;
    // best ask price.
    int best_ap;
    // volume of the ask.
    int best_av;
    // best bid price.
    int best_bp;
    // volume of the bid.
    int best_bv;

    Trade() = default;
    
    Trade(int timestamp, int best_ap, int best_av, int best_bp, int best_bv): timestamp(timestamp),
     best_ap(best_ap), best_av(best_av), best_bp(best_bp), best_bv(best_bv){}

    void print() const {
        std::cout << "Timestamp: " << timestamp << std::endl;
        std::cout << "Best Ask Price: " << best_ap << std::endl;
        std::cout << "Ask Volume: " << best_av << std::endl;
        std::cout << "Best Bid Price: " << best_bp << std::endl;
        std::cout << "Bid Volume: " << best_av << std::endl;
    }
};

#endif