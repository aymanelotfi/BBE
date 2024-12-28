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

class Parser{
public:
    explicit Parser(const std::string& MD_filename, SharedQueue<Trade>& queue);

    void stream();

    ~Parser();

private:
    std::optional<Side> parse_side(const std::string& str);
    
    Trade parse_line(const std::string& line);

    SharedQueue<Trade>& queue;
    std::ifstream inFile;
};

#endif