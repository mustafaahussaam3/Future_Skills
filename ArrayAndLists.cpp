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
       * A tree has already been planted at index 1. Place a plant on any
       * unoccupied index by using the API function "place plant".
       */
      void level1() {
        // Write your code here
        api->placePlant("tree", 2);
        
      }

      /**
       * There is an uncompleted hedge with a hole in it. Fix the hole in the
       * hedge by planting a bush at the correct index.
       */
      void level2() {
        // Write your code here
         api->placePlant("bush", 1);
      }

      /**
       * A new hedge has to be planted. Place a plant at all indexes in the row
       * to form a hedge according to this specification:
       * "tree","tree","bush","tree","tree".
       */
      void level3() {
        // Write your code here
        api-> placePlant("tree",0);
        api-> placePlant("tree",1);
        api-> placePlant("bush",2);
        api-> placePlant("tree",3);
        api-> placePlant("tree",4);

      }

      /**
       * Instead of planting one plant at a time, plant all at once using
       * "place hedge". The plant order remains the same:
       * "tree","tree","bush","tree","tree".
       */
      void level4() {
        // Write your code here
        std::vector<string>plants {"tree","tree","bush","tree","tree"};
        api->placeHedge(plants);
      }

      /**
       * There are already some bushes planted in this hedge. Complete the
       * hedge by planting bushes in all empty locations. Use place hedge to
       * complete it, using an empty string string (ie ””) to indicate
       * positions where nothing needs to be planted.
       */
      void level5() {
        // Write your code here
        std::vector<string>plants {"bush","bush","","","bush"};
        api->placeHedge(plants);
        
      }

      /**
       * Plant a hedge according to the specification in the parameter "hedge
       * directions". Hedge directions is an array of integers with length 5
       * specifying what should be planted and in what order. A '1' signifies a
       * tree, a '2' signifies a bush and a '0' signifies nothing should be
       * planted at that location. Example: The array [1, 0, 2, 0, 0] means a
       * tree should be planted at index 0 and a bush at index 2. Write a
       * function that will map this array of integers to the correct strings,
       * and then use the api to place a hedge using those strings.
       */
      void level6(vector<int> hedgeDirections) 
      {
       std::map<int,string>x ; 
       std::vector<string>pla;
       x[1] = "tree" ;
       x[2] = "bush" ;
       x[0] = "" ;
        for(auto i : hedgeDirections)
        {
          if (i == 1)
          {
           pla.push_back(x.at(1));
          }
          else if (i == 2)
          {
            pla.push_back(x.at(2));
          }
          else 
          {
            pla.push_back(x.at(0));
          }
        }
        api->placeHedge(pla);
 
      }

    private:
      APICaller* api;

  };
}