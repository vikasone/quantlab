#ifndef TRADEFILEREADER_H
#define TRADEFILEREADER_H

#include "Trade.h"
#include<string>
#include <fstream>
using namespace std;

class TradeFileReader {

  public:
    TradeFileReader(const string& tradefile);
    ~TradeFileReader();

    TradeFileReader(const TradeFileReader&) = delete;
    TradeFileReader& operator=(const TradeFileReader&) = delete;

    TradeFileReader(const TradeFileReader&&) = delete;
    TradeFileReader& operator=(const TradeFileReader&&) = delete;

    bool hasNextTrade();
    Trade nextTrade();

  private:
    ifstream m_tradefile;

};

#endif
