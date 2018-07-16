#include "Trade.h"

Trade::Trade(unsigned long timestamp, const string symbol, unsigned long qty, unsigned long price) :
             m_timestamp(timestamp), m_symbol(symbol), m_qty(qty), m_price(price) {

}
