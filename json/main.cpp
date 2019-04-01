  
#include "json.hpp"
#include "reddit.hpp"
#include <iostream>
#include <vector>
#include <typeinfo>

int
main()
{
  std::istreambuf_iterator<char> first(std::cin);
  std::istreambuf_iterator<char> last;
  std::string s(first, last);  

  json::Value* subreddit = json::parse(s);

  json::Value* posts = subreddit->goToKey("\"data\"")->goToKey("\"children\"");

std::cout << std::endl;
  Reddit reddit(subreddit);
  reddit.showReddit();

}
