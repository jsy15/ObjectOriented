#pragma once
#include <vector>
#include <string>
#include "json.hpp"

struct Post {
    std::string title = "";
    std::string author = "";
    std::string url = "";
    bool stickied = false;
    Post(std::string t, std::string a, std::string u, bool stick);
};

struct Reddit {
    Reddit(json::Value *v);
    std::vector<Post> site;
    std::string removeQuote(std::string);
    void showReddit();
};