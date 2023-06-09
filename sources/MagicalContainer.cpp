
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

        auto iter = std::lower_bound(mystical_elements.begin(),mystical_elements.end(),num_to_remove);

        if(iter == mystical_elements.end() || *iter != num_to_remove){
            throw std::runtime_error("Elements not found");
        }
        mystical_elements.erase(iter);

        if(is_prime(num_to_remove)){ 
            int plase = 0;
            for (size_t i = 0; i < prime_vector.size(); ++i) {
                
                if (*(prime_vector[i]) != num_to_remove) {
                    plase++;
                }
                else{
                    break;
                }
            }
            auto ite = prime_vector.begin() + plase;
            delete *ite;  // Deallocate the memory for the element being removed
            prime_vector.erase(ite);  // Remove the element from the vector
        

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