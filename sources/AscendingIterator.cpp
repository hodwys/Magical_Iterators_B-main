#include "MagicalContainer.hpp"
using namespace std;
namespace ariel{



    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator:: begin(){
        this ->set_curr_index(0);
        return *this;
    }

    int& MagicalContainer::AscendingIterator:: operator*(){
        return this->get_container().get_vector()[static_cast<vector<int>::size_type>(this->get_curr_index())];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator:: operator++(){

        if(this->get_curr_index() == this->get_container().get_vector().size()){
            throw runtime_error("in the end");
        }
        this->set_curr_index(this->get_curr_index()+1);
        return *this;
    }
}