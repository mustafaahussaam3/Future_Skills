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
       * Generate Pascal's Triangle by calculating binomial coeffcients (n over
       * k) = n!/(k!*(n-k)!) if n > 0, (0 over 0) = 1. Returns a list of
       * strings where each string represents one row in the triangle as space-
       * separated values, ie ['1', '1 1', '1 2 1']. Parameter n is the number
       * of rows to generate. Allowed range for n is [1, 12], ie 1 <= n <= 12.
       * For values outside this range, return an empty list.
       */
      int factorial (int x){ return (x == 1 || x == 0) ? 1 : x * factorial(x-1);}   
      
      vector<string> generatePascalTriangleBinomial(int n)
      {
        // Write your code here
        vector<string> returnValue;
          if ( n <= 0 || n > 12 ){
              return returnValue;
          }
      
          for (int nth = 0 ; nth < n ; ++nth )
          {
            string r = "";
              for (int kth = 0; kth <= nth  ; ++kth)
              { 
                  r += to_string(factorial(nth) / (factorial(kth) * factorial(nth - kth))) + " ";
              } 
              r.pop_back();
              returnValue.push_back(r);
          }

        return returnValue;
      }

      /**
       * Generate Pascal's Triangle by calculating (n, k) = (n-1, k) + (n-1,
       * k-1) (replace with 0 if out of range). Returns a list of strings where
       * each string represents one row in the triangle as space-separated
       * values, ie ['1', '1 1', '1 2 1']. Parameter n is the number of rows to
       * generate. Allowed range for n is [1, 12], ie 1 <= n <= 12. For values
       * outside this range, return an empty list.
       */
      vector<string> generatePascalTriangleSummation(int n)
      {
        
            // Write your code here
        vector<string> returnValue;
          if ( n <= 0 || n > 12 ){
              return returnValue;
          }
      
         for (int nth = 0; nth < n; ++nth)
           {
              string r = "";
              int val = 1; 
      
              for (int kth = 0; kth <= nth; ++kth) 
              {
                r += to_string(val) + " ";
                val = val * (nth - kth) / (kth + 1);
              }
      
              r.pop_back();
              returnValue.push_back(r);
           }



        return returnValue;
      }

    private:
      APICaller* api;
  };
}