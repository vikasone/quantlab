#include "MaxTimeGapCalculator.h"
#include<iostream>
using namespace std;

MaxTimeGapCalculator::MaxTimeGapCalculator(TradeDataStore& tds) : m_tds(tds) {}

void MaxTimeGapCalculator::calculate(Trade& t) {
  string symbol = t.getSymbol();
  TradeData& td = m_tds.getTradeData(t);
  unsigned long gap = t.getTimestamp() - td.getLastTimestamp(); 
  if ( gap > td.getMaxTimeGap() ) {
    td.setMaxTimeGap(gap);
  }
  td.setLastTimestamp(t.getTimestamp());
}
