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
       * Write a method that takes a list of integers as input and find the
       * largest product of 2 consecutive numbers in the list. Return the index
       * of the first number which give the largest product.
       */
      int level1IndexForMaxProduct(vector<int> integerList) {
        // Write your code here
         long unsigned int i = 0 ;
         int x = 0 ;
         int prod = 0;
         while ( i < integerList.size())
         {
           if (prod < (integerList[i]*integerList[i+1]))
           {
             prod = integerList[i] * integerList [i+1];
             x = i;
           }
           i++;
         }
        return x;
      }

      /**
       * Write a method that takes a list of integers and n as input and find
       * the largest product of n consecutive numbers in the list. Return the
       * index of the start of the numbers which give the largest product.
       */
      int level2IndexForMaxProduct(vector<int> integerList, int n) {
        // Write your code here
        int y = 0 ;
        for(long unsigned int j = 0; j <= integerList.size() -n; ++j)
        { 
          for (long unsigned int i = j; i < n + j  ; ++i)
          {
            p = p * integerList[i];
          }
          arr[1] = p;
          if(arr[1] > arr[0])
          {
            arr[0] = arr[1];
            y = j;
          }
          p = 1;
        }
        
      return y;
      }

    private:
      APICaller* api;
      std::vector <int> virt;
      int arr[2] = {0,0};
      int p = 1; 


  };
}