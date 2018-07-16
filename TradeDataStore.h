#ifndef TRADEDATASTORE_H
#define TRADEDATASTORE_H

#include "TradeData.h"
#include "Trade.h"
#include <string>
#include <map>
using namespace std;

// TradeDataStore - A data structure to store trade related data, with symbol as a key

class TradeDataStore
{
  public:
    map<string, TradeData>& getTradeDataMap();
    TradeData& getTradeData(Trade& t);
    void setTradeData(string symbol, TradeData tradeData);
    void createOutputFile(string outfile);


  private:
    map<string, TradeData> m_tradeDataMap; 

    // due to lack of time I could not implement a better data structure suited for these operations
    // for future design to process large amount of trades, I'll use following data structure
    // a map of <First symbol character, Trade data map as above>
    // map<char, map<char, TradeData>> m_tradeDataStore;
    // this will cut down latency in symbol searches, when the number of symbols can grow higher

};

#endif
