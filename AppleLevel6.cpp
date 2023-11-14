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
        
      //state review
      
        for (auto& i : state){
          std::cout <<i.first << "->"<< i.second << std::endl;
        }
        
      //Parsing 
      
      position_parse = state.at("player") ;  //saving the string at player indecxx
      px = position_parse.substr(1,1);  //parse the string at position 1 and taking one element
      py = position_parse.substr(3,1);
      x_p = stof(px);
      y_p = stof(py);
      
      apple_parse = state.at("apples") ;
      ax = apple_parse.substr(1,1);
      ay = apple_parse.substr(3,1);
      x_a = stof(ax);
      y_a = stof(ay);
      
      
      if (x_a == x_p){
        
          const_x = y_a - y_p ;
          if(const_x > 0){
            return w[2];
          }
          else if (const_x < 0){
            return w[0];
          }
          else {
            return w[4];
          }
  
      }
      
      else if (y_a == y_p){
        
        const_y = x_a - x_p ;
        if(const_y > 0){
          return w[1];
        }
        else if (const_y < 0){
          return w[3];
        }
        else {
          return w[4];
        }
        
      }
      
      // std::cout <<x_p <<" "<< y_p <<" "<< x_a <<" "<< y_a <<" "<< std::endl;
      
      //level 4
      
      // x = state.at("say0");
      // y = state.at("say1");
      // std::cout << x << " "<< y <<std::endl;
      
      //return values
       return " ";
      }
    
    private:
      APICaller* api;
      std::vector<std::string>w {"walk 0", "walk 1", "walk 2", "walk 3", "pick"};
      int i;
      std::string position_parse, apple_parse,px,py,ax,ay;
      float x_a, y_a, x_p, y_p, const_x, const_y;
      
  };
}