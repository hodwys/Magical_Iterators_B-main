#include "MagicalContainer.hpp"
using namespace std;
namespace ariel{

    // Move assignment operator
    MagicalContainer::highIterator&  MagicalContainer::highIterator:: operator=(highIterator&& other) noexcept {
        if (this != &other) {

        container = other.container;
        curr_index = other.curr_index;
        curr_right = other.curr_right;
        right = other.right;
        left = other.left;

        other.curr_index =0;
        other.curr_right =0;
        other.left = false;
        other.right = false;
        }
        return *this;
    }

    bool  MagicalContainer::highIterator:: get_right() const{
        return this->right;
    }
    bool MagicalContainer::highIterator:: get_left() const{
        return this->left;
    }
    void  MagicalContainer::highIterator:: set_right(bool right){
        this->right = right;
    }
    void  MagicalContainer::highIterator:: set_left(bool left){
        this->left = left;
    }

    int  MagicalContainer::highIterator:: get_curr_index() const{
        return this->curr_index;
    }
    void  MagicalContainer::highIterator:: set_curr_index(int other_index){
        this->curr_index = other_index;
    }
    int  MagicalContainer::highIterator:: get_curr_right() const{
        return this->curr_right;
    }

    void  MagicalContainer::highIterator:: set_curr_right(int other_index){
        this->curr_right = other_index;
    }
    MagicalContainer&  MagicalContainer::highIterator::get_container() const{
        return this->container;
    }

    MagicalContainer::highIterator& MagicalContainer::highIterator:: end(){
    this ->curr_index =int( this->container.get_vector().size());
    this->set_curr_right(0);
    return *this;
    }

    bool MagicalContainer::highIterator:: operator>(const highIterator& other_iterator) const{

        if(right){
            return ((int)(this->right) > (int)(other_iterator.right));
        }
        return ((int)(this->curr_index) >(int)( other_iterator.curr_index));                        
    }

    bool MagicalContainer::highIterator:: operator<(const highIterator& other_iterator) const{

        if(right){
            return ((int)(this->right) < (int)(other_iterator.right));
        }
        return (this->curr_index < other_iterator.curr_index);                        
    }

    bool MagicalContainer::highIterator:: operator==(const highIterator& other) const{
        if(typeid(*this) != typeid(other)){
            throw runtime_error("diffrent iterators, error in ==");
        }
        return ((this->curr_index == other.curr_index));
    }

    // Inequality comparison operator
    bool MagicalContainer::highIterator:: operator!=(const highIterator& other) const {
        return !(*this == other);
    }

    // Copy assignment operator
    MagicalContainer::highIterator& MagicalContainer::highIterator:: operator=(const highIterator& other) {

        if(this->container != other.get_container()){
            throw std::runtime_error("containers are not the same");
        }

        if (this != &other) {
            this->container = other.container;
            this->curr_index = other.curr_index;
            this->curr_right = other.curr_right;
            this->left = other.left;
            this->right = other.right;
        }
        return *this;
    }




}