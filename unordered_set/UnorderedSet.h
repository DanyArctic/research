#pragma once
#include <string>
#include <vector>

class UnorderedSet
{
public:
    UnorderedSet();

    ~UnorderedSet() = default;

    void insert(const std::string &word);

    bool find(const std::string &word) const;

    int hash(const std::string &word) const;

private:
    std::vector<std::string> words_;

};