#include <iostream>
#include <vector>
#include <utility>

int main()
{  
    std::vector<std::pair<int,std::string>> myVector;
    myVector.push_back(std::make_pair<int,std::string>(1,"Mustafa"));   
    myVector.emplace_back(2,"Hussam");
    myVector.emplace_back(2," ");
    myVector.emplace_back(2,"Mohamed");

    for(auto element : myVector)
    {
        std::cout << element.first << " ";
        std::cout << element.second << std::endl;
    }
    return 0;
}