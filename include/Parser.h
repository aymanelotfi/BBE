/* Parsed file structure:
*  Single instrument
 *  timestamp | (best_ask_price | best_ask_volume) | (best_bid_price | best_bid_volume)
 *
 *  */

#ifndef BBE_PARSER_H
#define BBE_PARSER_H

#include "Trade.h"
#include "SharedQueue.h"

#include <string>
#include <fstream>

using Path = std::string;

class Parser{
public:
    explicit Parser(const Path& MD_filename, SharedQueue<Trade>& queue);

    void load();

    ~Parser();

private:
    SharedQueue<Trade>& queue;
    std::ifstream inFile;
};

#endif