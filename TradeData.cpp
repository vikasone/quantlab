#include "TradeData.h"
#include <string>
#include <map>
using namespace std;

unsigned long TradeData::getLastTimestamp() {
  return m_lastTimestamp;
}

void TradeData::setLastTimestamp(unsigned long timestamp) {
  m_lastTimestamp = timestamp;
}

unsigned long TradeData::getMaxTimeGap() {
  return m_maxTimeGap;
}

void TradeData::setMaxTimeGap(unsigned long maxTimeGap) {
  m_maxTimeGap = maxTimeGap;
}

unsigned long TradeData::getMaxTradePrice() {
  return m_maxTradePrice;
}

void TradeData::setMaxTradePrice(unsigned long maxTradePrice) {
  m_maxTradePrice = maxTradePrice;
}

unsigned long TradeData::getTotalVolTraded() {
  return m_totalVolTraded;
}

void TradeData::setTotalVolTraded(unsigned long totalVolTraded) {
  m_totalVolTraded = totalVolTraded;
}

unsigned long TradeData::getTotalWeightedVol() {
  return m_totalWeightedVol;
}

void TradeData::setTotalWeightedVol(unsigned long totalWeightedVol) {
  m_totalWeightedVol = totalWeightedVol;
}

unsigned long TradeData::getWeightedAvgPrice() {
  return m_totalWeightedVol / m_totalVolTraded;
}


