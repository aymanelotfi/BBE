
/* Parsed file structure:
*  Single instrument
 *  timestamp | (best_ask_price | best_ask_volume) | (best_bid_price | best_bid_volume)
 *
 *  */
#pragma once
#include<string>
#include<fstream>
#include <TraderQueue.h>

class Parser{
    public:
    explicit Parser(const std::string& filename);
    void load(TraderQueue& queue);
    Parser() = default;
    ~Parser();
  private:
    std::ifstream inFile;
};
