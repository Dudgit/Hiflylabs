#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>


auto my_searching_function(std::string what_to_find, std::string find_whitin,double price) {
    int drink_existed = 0;
    auto pricegiver = [price](std::string drink){
        std::cout<<"This drink will cost "<<price <<"Ft"<<std::endl;
    
    };

    auto searching=[pricegiver,what_to_find,find_whitin,price,&drink_existed](){
        size_t my_bool = find_whitin.find(what_to_find);
        if(my_bool != std::string::npos){
            pricegiver(what_to_find);
            drink_existed++;
            }
    };
    searching();
    return drink_existed;
}


int searchin(std::string drink){
    int i =0;
    i+=my_searching_function("Cola",drink,340);
    i+=my_searching_function("Tonic",drink,320);
    i+=my_searching_function("Sprite",drink,330);
    i+=my_searching_function("Natur Aqua",drink,250);
    return i;
}

int main(int, char**) {


    std::cout<< "What kind of drink would you like?" <<std::endl;
    std::string string_object;
    

    while(1){
        std::cin>> string_object;
        int i =searchin(string_object);
        if(i<1){std::cout<<"Please select a real drink"<<std::endl;}
        std::cout<<"Please type exit if you are finished"<<std::endl;
        size_t my_bool = string_object.find("exit");
        if(my_bool != std::string::npos){exit(0);}

    }
}