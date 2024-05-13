#ifndef FREQUENCY_DICTIONARY_CMDS_HPP
#define FREQUENCY_DICTIONARY_CMDS_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

namespace sazanov
{
  using FrequencyDictionary = std::unordered_map< std::string, std::size_t >;
  using DictionaryCollection = std::unordered_map< std::string, FrequencyDictionary >;
  using Commands = std::unordered_map< std::string, std::function< void(std::istream&) > >;

  void create(DictionaryCollection& collection, std::istream& in);
  void insert(DictionaryCollection& collection, std::istream& in);
  void getFrequency(DictionaryCollection& collection, std::istream& in, std::ostream& out);
  void erase(DictionaryCollection& collection, std::istream& in);
  void getMostFrequent(DictionaryCollection& collection, std::istream& in, std::ostream& out);
  void size(DictionaryCollection& collection, std::istream& in, std::ostream& out);
  void readText(DictionaryCollection& collection, std::istream& in);
  void save(DictionaryCollection& collection, std::istream& in);
  void print(DictionaryCollection& collection, std::istream& in, std::ostream& out);
  void readDict(DictionaryCollection& collection, std::istream& in);
  void merge(DictionaryCollection& collection, std::istream& in);
  void equal(DictionaryCollection& collection, std::istream& in, std::ostream& out);
  void intersect(DictionaryCollection& collection, std::istream& in);

  bool compareFrequency(const std::pair< std::string, std::size_t >& lhs, const std::pair< std::string, std::size_t >& rhs);
  bool copyOrIncreaseFrequency(FrequencyDictionary& result, const std::pair< std::string, std::size_t >& pair);
  bool isDictContein(FrequencyDictionary& dict, const std::pair< std::string, std::size_t >& pair);
  std::pair< std::string, std::size_t > increaseFrequency(FrequencyDictionary& other,
    const std::pair<std::string, std::size_t>& pair);
}

#endif