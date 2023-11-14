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

       for (auto& i : state)
      {
        std::cout <<i.first << "->"<< i.second << std::endl;
      }
        

      position_parse = state.at("player") ;
      px = position_parse.substr(1,1);  
      py = position_parse.substr(3,1);
      x_p = stof(px);
      y_p = stof(py);
      
      apple_parse = state.at("apples") ;
      opIndex = apple_parse.find(",");
      ax = apple_parse.substr(opIndex -1,1);
      ay = apple_parse.substr(opIndex +1,1);
      
      x_a = stof(ax);
      y_a = stof(ay);
      
      x = x_p - x_a;
      y = y_p - y_a;
        
        if (x > 0)
        {
          return w[3];
        }
        
        if (x < 0)
        {
          return w[1];
        }

        if (y > 0)
        {
          return w[0];
        }
         
        if (y < 0)
        {
          return w[2];
        }
        if ( x == 0 && y == 0)
        {
          return w[4];
        }
       
      
        return "foo";
      }
      
  
    private:
      APICaller* api;
      int opIndex;
      std::vector<std::string>w {"walk 0", "walk 1", "walk 2", "walk 3", "pick"};
      std::string position_parse, apple_parse,px,py,ax,ay;
      float x_a, y_a, x_p, y_p,x,y;

  };
}