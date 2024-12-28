#include "Parser.h"
#include <fstream>
#include <iostream>
#include <optional>

Parser::Parser(const std::string& filename, SharedQueue<Trade>& queue): inFile(filename), queue(queue) {
    if(!inFile.is_open()) {
        std::cerr << "Error opening file ! " << std::endl;
    }
}

void Parser::stream() {
    std::string line;
    size_t line_number = 0;
    while(std::getline(inFile, line)) {
        line_number++;
        try{
            Trade trade = parse_line(line);
            queue.push(trade);
        } catch(const std::exception& e){
            std::cerr << "Error while parsing line " << line_number << ": " << e.what() << '\n';
        }
    }
    queue.finish();
}

std::optional<Side> Parser::parse_side(const std::string& str){
    if(str == "BID"){
        return Side::BID;
    }
    else if(str == "SELL"){
        return Side::SELL;
    }
    else return std::nullopt;
}

Trade Parser::parse_line(const std::string& line){
    std::istringstream ss(line);
    std::string tokens[5];
    for(int i = 0; i < 5;i++){
        getline(ss, tokens[i], ',');
    }

    uint64_t ts = std::stoull(tokens[1]);
    float price = std::stof(tokens[2]);
    uint32_t volume = std::stoul(tokens[3]);
    auto side = parse_side(tokens[4]);

    if(!side){
        throw std::runtime_error("[Parser] Invalid Side");
    }

    return Trade{tokens[0], ts, price, volume, *side};
}

Parser::~Parser() {
    inFile.close();
}



