#include "reddit.hpp"
#include <iostream>
#include <string>
using std::string;

Post::Post(std::string t, std::string a, std::string u, bool stick){
    title = t;
    author = a;
    url = u;
    stickied = stick; 
};

string Reddit::removeQuote(std::string s){
    s.pop_back();
    s.erase(s.begin());
    return s;
}

Reddit::Reddit(json::Value* val){
    int i = 0;
    
    while(val->goToKey("\"data\"")->goToKey("\"children\"")->index(i) != nullptr){
        //std::cout << val->goToKey("\"data\"")->goToKey("\"children\"")->index(i)->goToKey("\"data\"")->goToKey("\"title\"")->getString() << std::endl;

        //Create strings of the title, author, and url
        std::string title = removeQuote(val->goToKey("\"data\"")->goToKey("\"children\"")->index(i)->goToKey("\"data\"")->goToKey("\"title\"")->getString());
        std::string author = removeQuote(val->goToKey("\"data\"")->goToKey("\"children\"")->index(i)->goToKey("\"data\"")->goToKey("\"author\"")->getString());
        std::string url = removeQuote(val->goToKey("\"data\"")->goToKey("\"children\"")->index(i)->goToKey("\"data\"")->goToKey("\"url\"")->getString());
        bool sticked = val->goToKey("\"data\"")->goToKey("\"children\"")->index(i)->goToKey("\"data\"")->goToKey("\"stickied\"")->getBool();

        // Create a post and push it onto the top of the site vector
        Post newPost(title, author, url, sticked);
        site.insert(site.begin(), newPost);

        i++;
    }
};

void Reddit::showReddit(){
    for(int i = site.size() - 1; i > 0; i--){
        Post p = site.at(i);
        std::cout << p.url << std::endl;
        std::cout << p.title << std::endl;
        std::cout << "\t";
        std::cout << "By: "<< p.author << std::endl;
        std::cout << "----------------------------------------------------------------------------------------------------------------\n";
        std::cout << std::endl;
    }
}