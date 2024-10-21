/* Parsed file structure:
*  Single instrument
 *  timestamp | (best_ask_price | best_ask_volume) | (best_bid_price | best_bid_volume)
 *
 *  */

#ifndef BBE_PARSER_H
#define BBE_PARSER_H

#include <string>
#include <fstream>

#include "TraderQueue.h"

using Path = std::string;

class Exchange;

class Parser{
public:
    explicit Parser(const Path& MD_filename, TraderQueue& queue);

    void load();

    ~Parser();

private:
    TraderQueue& queue;
    std::ifstream inFile;
};

#endif