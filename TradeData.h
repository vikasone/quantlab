#ifndef TRADEDATA_H
#define TRADEDATA_H

// TradeData - An object storing calculated result data for any symbol

class TradeData
{
  public:
    unsigned long getLastTimestamp();
    void setLastTimestamp(unsigned long timestamp);
    unsigned long getMaxTimeGap();
    void setMaxTimeGap(unsigned long maxTimeGap);
    unsigned long getMaxTradePrice();
    void setMaxTradePrice(unsigned long maxTradePrice);
    unsigned long getTotalVolTraded();
    void setTotalVolTraded(unsigned long totalVolTraded);
    unsigned long getTotalWeightedVol();
    void setTotalWeightedVol(unsigned long totalWeightedVol);
    unsigned long getWeightedAvgPrice();

  private:
    unsigned long m_lastTimestamp;
    unsigned long m_maxTimeGap;
    unsigned long m_totalVolTraded;
    unsigned long m_maxTradePrice;
    unsigned long m_totalWeightedVol;
};

#endif
