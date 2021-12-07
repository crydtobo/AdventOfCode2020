/*
 * bags.h
 *
 *  Created on: Feb 25, 2021
 *      Author: dawid
 */
#ifndef INCLUDE_BAGS_H_
#define INCLUDE_BAGS_H_

#include <vector>
#include <string>
#include <map>
#include <regex>
#include <cassert>
#include <deque>
#include <unordered_set>
#include <unordered_map>

class Bags{
public:

	using contained_t = std::unordered_map<std::string, std::unordered_set<std::string>>;
	using contains_t = std::unordered_map<std::string, std::unordered_map<std::string, uint32_t>>;

	Bags() = default;
	
	uint32_t count_bags(contains_t &contains, std::string bag_name);
	void parse_input(std::vector<std::string> &in, contained_t &contained, contains_t &contains);

};
//void parse_input(std::vector<std::string> &in, Bags::contained_t &contained, Bags::contains_t &contains);


#endif /* INCLUDE_BAGS_H_ */