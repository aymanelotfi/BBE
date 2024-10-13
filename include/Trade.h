#pragma once
#include<iostream>
#include<sstream>
#include<vector>


class Trade{
    int timestamp;
    // best ask price.
    int best_ap;
    // volume of the ask.
    int best_av;
    // best bid price.
    int best_bp;
    // volume of the bid.
    int best_bv;

public:
    Trade() = default;

    
    Trade(int timestamp, int best_ap, int best_av, int best_bp, int best_bv): timestamp(timestamp),
     best_ap(best_ap), best_av(best_av), best_bp(best_bp), best_bv(best_bv){}
    
    Trade(const std::string& line) {
        std::stringstream ss(line);
        std::string token;
        std::vector<int> values;

        while (std::getline(ss, token, ',')) {
            values.push_back(std::stoi(token)); // Convert token to int
        }

        if (values.size() == 5) {
            timestamp = values[0];
            best_ap = values[1];
            best_av = values[2];
            best_bp = values[3];
            best_bv = values[4];
        } else {
            std::cerr << "Error: Invalid CSV format." << std::endl;
        }
    }

    void print() const {
        std::cout << "Timestamp: " << timestamp << std::endl;
        std::cout << "Best Ask Price: " << best_ap << std::endl;
        std::cout << "Ask Volume: " << best_av << std::endl;
        std::cout << "Best Bid Price: " << best_bp << std::endl;
        std::cout << "Bid Volume: " << best_av << std::endl;
    }


};


