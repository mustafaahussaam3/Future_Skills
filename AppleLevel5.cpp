#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "api.h"

namespace solution {
  using namespace api;
  using namespace std;

  class Solution : public SolutionInterface {
    public:
      Solution(APICaller* api) {
        this->api = api;
        std::cout << "Press run code to see this in the console!\n";
        // You can initiate and calculate things here
      }

      /**
       * Executes a single step of the apple pickers logical loop. This
       * function will be called repeatedly until the levels goal has been
       * reached or untill the update limit has been reached
       */
      string update(map<string, string> state) {
        // Write your code here
        // for (auto& i : state){
        //   std::cout <<i.first << "->"<< i.second << std::endl;
        // }
      parse = state.at("player") ;
      std::string subst = parse.substr(1,1);
      x = stof(subst);
      std::cout <<x << std::endl;
      // x = state.at("say0");
      // y = state.at("say1");
      // std::cout << x << " "<< y <<std::endl;
      
      return w[x];
      }
    
    private:
      APICaller* api;
      std::vector<std::string>w {"walk 1", "walk 1", "pick"};
      int i;
      std::string parse;
      float x;
  };
}