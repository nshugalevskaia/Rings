#include <iostream>
#include <sstream>
#include <set>
#include <deque>
#include "Rings.h"

InputException::InputException(std::string error) :m_error(error) {};

const char* InputException::what() const noexcept
{
    return m_error.c_str();
}

int build_chain(std::string string_input)
{
std::multiset<int> chains_set;
std::deque<int> chains;
std::istringstream  string_to_parse;
string_to_parse.str(string_input);
std::string string_num;
int broken_rings_count = 0;

while (!string_to_parse.eof())
{
    int chain_len;
    try
    {
     std::getline(string_to_parse, string_num, ',');
     chain_len  = std::stoi(string_num);
    }
    catch (const std::exception&)
    {
        throw InputException("wrong input: it must be integer numbers separated by comma");
    } 
    
    chains_set.insert(chain_len);
}

for (auto i = chains_set.begin(); i != chains_set.end(); ++i)
{
    chains.push_back(*i);
}
chains_set.clear();

while (chains.size() > 1)
{
    int free_rings_count = chains.front();
    chains.pop_front();
    while (free_rings_count > 0)
    {
        if (chains.size() == 1) break;
        int last_chain_len = chains.back();
        chains.pop_back();
        auto it = chains.rbegin();
        (*it) += last_chain_len + 1;
        free_rings_count--;
        ++broken_rings_count;
    }
    if (free_rings_count > 0) ++broken_rings_count;  //если остались кольца в "оторванной" цепочке - надо их присоединить к основной цепи
}
return broken_rings_count;
}


