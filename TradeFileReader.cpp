#include "TradeFileReader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

TradeFileReader::TradeFileReader(const string& tradefile) {
  m_tradefile.open(tradefile, ifstream::in);
}

TradeFileReader::~TradeFileReader() {
  if (m_tradefile.is_open())
    m_tradefile.close();
}

bool TradeFileReader::hasNextTrade() {
  return (m_tradefile.peek() != EOF);  
}

Trade TradeFileReader::nextTrade() {
  vector<string> tdata;
  string line;
  getline(m_tradefile, line);

  stringstream lineStream(line);
  string item;

  while(getline(lineStream, item, ',')) {
    tdata.push_back(item);
  }

  return Trade(stoul(tdata[0]), tdata[1], stoul(tdata[2]), stoul(tdata[3]));
}

