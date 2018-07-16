#include "MaxTradePriceCalculator.h"
#include<iostream>
using namespace std;

MaxTradePriceCalculator::MaxTradePriceCalculator(TradeDataStore& tds) : m_tds(tds) {}

void MaxTradePriceCalculator::calculate(Trade& t) {
  string symbol = t.getSymbol();
  unsigned long price = t.getPrice();

  TradeData& td = m_tds.getTradeData(t);
  if ( price > td.getMaxTradePrice() ) {
    td.setMaxTradePrice(price);
  }
}
