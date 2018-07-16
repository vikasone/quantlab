#include "TradeDataStore.h"
#include "Trade.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

map<string, TradeData>& TradeDataStore::getTradeDataMap() {
  return m_tradeDataMap;
}

TradeData& TradeDataStore::getTradeData(Trade& t) {
  string symbol = t.getSymbol();
  auto it = m_tradeDataMap.find(symbol);
  if (it == m_tradeDataMap.end()) {
    TradeData td;
    td.setLastTimestamp(t.getTimestamp());
    td.setMaxTradePrice(0);
    td.setTotalVolTraded(0);
    td.setTotalWeightedVol(0);
    td.setMaxTimeGap(0);
    m_tradeDataMap[symbol] = td;

    return m_tradeDataMap.find(symbol)->second;
  } else {
    return it->second;
  }
}

void TradeDataStore::setTradeData(string symbol, TradeData tradeData) {
  //m_tradeDataMap.insert(make_pair<string, TradeData>(symbol, tradeData));
  m_tradeDataMap[symbol] = tradeData;
}

void TradeDataStore::createOutputFile(string outfile) {
  ofstream os(outfile, std::ofstream::out);

  for (auto it : m_tradeDataMap) {
    os << it.first << ",";
    os << (it.second).getMaxTimeGap() << ",";
    os << (it.second).getTotalVolTraded() << ",";
    os << (it.second).getWeightedAvgPrice() << ",";
    os << (it.second).getMaxTradePrice() << endl;
  }

  os.flush();
  os.close();
}

