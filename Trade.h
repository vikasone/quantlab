#ifndef TRADE_H
#define TRADE_H

#include <string>
using namespace std;

// Trade - An object represent a trade

class Trade {
  public:
    Trade(unsigned long timestamp, const string symbol, unsigned long qty, unsigned long price);
    ~Trade() = default;
    Trade (const Trade&) = default;
    Trade (Trade&&) = default;
    Trade& operator=(const Trade&) = default;
    Trade& operator=(Trade&&) = default;

    unsigned long getTimestamp() {
      return m_timestamp;
    }

    string getSymbol() {
      return m_symbol;
    }

    unsigned long getQty() {
      return m_qty;
    }

    double getPrice() {
      return m_price;
    }

  private:
    unsigned long m_timestamp;
    const string m_symbol;
    unsigned long m_qty;
    double m_price;
};

#endif
