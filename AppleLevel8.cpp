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
        

      map<string, string> m(api->getStaticData());
      for (auto i : m){
        std::cout<< i.first << " " << i.second << std::endl;
      }
      
      for (auto i : state){
        std::cout<< i.first << " " << i.second << std::endl;
      }
      
      string::iterator it;
      
      obstacle_parse = m.at("obstacles");
      ob_index = obstacle_parse.find(",");
      ox = obstacle_parse.substr(ob_index -1,1);
      oy = obstacle_parse.substr(ob_index +1,1);
      x_o = stof(ox);
      y_o = stof(oy);
      
      if (it != obstacle_parse.end()) 
      {
        obstacle_parse.erase(0,7) ;
      }
      
      position_parse = state.at("player") ;
      px = position_parse.substr(1,1);  
      py = position_parse.substr(3,1);
      x_p = stof(px);
      y_p = stof(py);
      
      apple_parse = state.at("apples") ;
      ap_index = apple_parse.find(",");
      ax = apple_parse.substr(ap_index -1,1);
      ay = apple_parse.substr(ap_index +1,1);
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
      int ap_index, ob_index;
      std::vector<std::string>w {"walk 0", "walk 1", "walk 2", "walk 3", "pick"};
      std::string position_parse, apple_parse, obstacle_parse, px, py, ax, ay, ox, oy;
      float x_a, y_a, x_p, y_p, x_o, y_o, x, y;

  };
}