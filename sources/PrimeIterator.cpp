#include "MagicalContainer.hpp"
using namespace std;
namespace ariel{

                    

MagicalContainer:: PrimeIterator& MagicalContainer::PrimeIterator:: begin(){
    this->set_curr_index(0);
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator:: end(){
this->set_curr_index((int)(this->get_container().get_prime().size()));
return *this; 
}

int& MagicalContainer::PrimeIterator:: operator*(){
return *(get_container().get_prime()[static_cast<vector<int>::size_type>(get_curr_index())]);
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator:: operator++(){
if(get_curr_index() == this->get_container().get_prime().size()){
    throw runtime_error("in the end");
}
this->set_curr_index(this->get_curr_index()+1);
return *this;
}
}