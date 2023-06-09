#include "MagicalContainer.hpp"
using namespace std;
namespace ariel{

                  
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator:: begin() {
        this->set_curr_right((int) (get_container().get_vector().size()-1));
        this->set_curr_index(0);
        return *this;
    }

    int& MagicalContainer::SideCrossIterator:: operator*(){

        if(this->get_right()){

            return get_container().get_vector()[static_cast<vector<int>::size_type>(this->get_curr_right())];
        }
        return get_container().get_vector()[static_cast<vector<int>::size_type>(this->get_curr_index())];
    }

    MagicalContainer::SideCrossIterator&  MagicalContainer::SideCrossIterator:: operator++(){
        // Increment the index
        if(get_curr_right() ==  0 && this->get_curr_index() == this->get_container().get_vector().size()){
            throw runtime_error("in the end");
        }

        if(this->get_right()){
            this->set_right(false);
            this->set_left(true);
            this->set_curr_right(this->get_curr_right() -1);
        }
        else{
            this->set_right(true); 
            this->set_left(false);
            this->set_curr_index(this->get_curr_index()+1);
        }
        if(get_curr_right() < this->get_curr_index()){
            this->set_curr_index(static_cast<int>(get_container().get_vector().size()));
            this->set_curr_right(0);
        }
        return *this;
    }

}