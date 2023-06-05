#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include "MagicalContainer.hpp"
using namespace std;
namespace ariel{


    bool MagicalContainer:: is_prime(int num){
        if(num == 2 || num==3){
            return true;
        }
        if(num <=1){
            return false;
        }
        for(int j = 2; j<=sqrt(num); j++){
            if(num % j ==0){
                return false;
            }
        }
        return true;
    }

    void MagicalContainer::addElement(int num_to_add){
        for(int element : mystical_elements){
            if(num_to_add == element){
                return;
            }
        }
        auto place =lower_bound(mystical_elements.begin(), mystical_elements.end(), num_to_add);

        mystical_elements.insert( place,num_to_add);

        if(is_prime(num_to_add)){

            int *pointer_prime = new int(num_to_add);

            auto place_prime = lower_bound(this->get_prime().begin(), this->get_prime().end(), pointer_prime , [](const int* firse, const int* second) { return *firse < *second; });

            prime_vector.insert(  place_prime,pointer_prime );

        }
    }


    void MagicalContainer::removeElement(int num_to_remove){
            bool remov =  false;
            for(auto i= mystical_elements.begin(); i!=mystical_elements.end();i++){
                if(*i == num_to_remove){
                    mystical_elements.erase(i);
                    i--;
                    remov = true;
                    if(is_prime(num_to_remove)){
                        int* elementToRemove = new int(num_to_remove);
                        auto ite = std::find(prime_vector.begin(), prime_vector.end(), elementToRemove);
                        prime_vector.erase(ite);
                        delete elementToRemove;
                    }
                }
            }

            if(!remov){
                throw runtime_error("imposible to remov");
            }
        }

    int MagicalContainer::size(){
        return static_cast<int>(mystical_elements.size());
    }

    vector<int>& MagicalContainer:: get_vector(){
        return mystical_elements;
    }

        const vector<int*>&  MagicalContainer::get_prime(){
        return prime_vector;
    }
};