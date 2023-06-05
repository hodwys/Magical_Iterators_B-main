# ifndef MAGICALCONTAINER_HPP
# define MAGICALCONTAINER_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <stdio.h>
#include <algorithm>
using namespace std;
namespace ariel{

    class MagicalContainer{

        vector<int> mystical_elements;
        vector<int*> prime_vector;

        bool static is_prime(int num);

        public:

            bool operator==(const MagicalContainer& other) const {
                return mystical_elements == other.mystical_elements;
            }

            MagicalContainer(){}

            void addElement(int num_to_add);

            void removeElement(int num_to_remove);

            int size();

            vector<int>& get_vector();

            const vector<int*>& get_prime();

            ~MagicalContainer()= default; 
            MagicalContainer (const MagicalContainer &other){}

            MagicalContainer& operator=(const MagicalContainer& other) {
                    if (this != &other){
                        this->mystical_elements = other.mystical_elements;
                    }
                    return *this;
            }

                // Move constructor
                MagicalContainer(MagicalContainer&& other) noexcept {
                }

                // Move assignment operator
                MagicalContainer& operator=(MagicalContainer&& other) noexcept {
                    if (this != &other){
                        this->mystical_elements = move(other.mystical_elements);
                    }
                    return *this;
                }
                
////////////////////////////////////////////////////////////////////////////////////////////////////////

            class highIterator{

                MagicalContainer &container;
                int curr_index;
                // for cross
                int curr_right;
                bool right;
                bool left;

                public:

                highIterator(MagicalContainer &container): container(container), curr_index(0),curr_right(container.size()-1),right(false), left(true) {
                }
                
                highIterator(const highIterator& other) : container(other.container), curr_index(other.curr_index) ,  curr_right(other.curr_right),right(other.right), left(other.left) {}

            
                virtual ~highIterator() = default;

                // Move constructor
                highIterator(highIterator&& other) noexcept : container(other.container), curr_index(other.curr_index),curr_right(other.curr_right),right(other.right), left(other.left) {}

                // Move assignment operator
                highIterator& operator=(highIterator&& other) noexcept {
                    if (this != &other) {
                    container = std::move(other.container);
                    curr_index = other.curr_index;
                    curr_right = other.curr_right;
                    right =other.right;
                    left= other.left;
                    }
                    return *this;
                }

                bool get_right() const{
                    return this->right;
                }
                bool get_left() const{
                    return this->left;
                }
                void set_right(bool right){
                    this->right = right;
                }
                void set_left(bool left){
                    this->left = left;
                }

                int get_curr_index() const{
                    return this->curr_index;
                }

                void set_curr_index(int other_index){
                    this->curr_index = other_index;
                }
                int get_curr_right() const{
                    return this->curr_right;
                }

                void set_curr_right(int other_index){
                    this->curr_right = other_index;
                }
                MagicalContainer& get_container() const{
                    return this->container;
                }

                virtual highIterator& begin()=0;

                virtual highIterator& end(){
                    this ->curr_index =int( this->container.get_vector().size());
                    return *this;
                }
                virtual int& operator*() = 0;

                virtual highIterator& operator++() = 0;

                bool operator>(const highIterator& other_iterator) const{

                    if(right){
                        return (static_cast<int>(this->right) > static_cast<int>(other_iterator.right));
                    }
                    return (static_cast<int>(this->curr_index) >static_cast<int>( other_iterator.curr_index));                        
                }

                bool operator<(const highIterator& other_iterator) const{

                    if(right){
                        return (static_cast<int>(this->right) < static_cast<int>(other_iterator.right));
                    }
                    return (this->curr_index < other_iterator.curr_index);                        
                }

                bool operator==(const highIterator& other) const{
                    if(typeid(*this) != typeid(other)){
                       throw std::runtime_error("diffrent iterators error in ==");
                    }

                    return (this->curr_index == other.curr_index);
                }

                // Inequality comparison operator
                bool operator!=(const highIterator& other) const {
                    return !(*this == other);
                }

                // Copy assignment operator
                highIterator& operator=(const highIterator& other) {

                    if(this->container != other.get_container()){
                        throw std::runtime_error("containers are not the same");
                    }

                    if (this != &other) {
                        this->container = other.container;
                        this->curr_index = other.curr_index;
                        set_curr_right(other.get_curr_right());
                    }
                    return *this;
                }
            };
/////////////////////////////////////////////////////////////////////////////////////////////////////////
            class AscendingIterator : public highIterator{
     
                public:
                    AscendingIterator(MagicalContainer &container): highIterator(container){
                    }
                
                    AscendingIterator& begin() override{
                        this ->set_curr_index(0);
                        return *this;
                    }
                    
                    AscendingIterator& end() override{
                        this->set_curr_index(int(this->get_container().get_vector().size()));
                        return *this;
                    }

                    int& operator*() override{
                        return this->get_container().get_vector()[static_cast<vector<int>::size_type>(this->get_curr_index())];
                    }

                    AscendingIterator& operator++() override{

                        if(this->get_curr_index() == this->get_container().get_vector().size()){
                            throw runtime_error("in the end");
                        }

                        this->set_curr_index(this->get_curr_index()+1);
                        return *this;
                    }

            };
/////////////////////////////////////////////////////////////////////////////////////////

            class PrimeIterator : public highIterator {

                public:

                    PrimeIterator(MagicalContainer &container): highIterator(container){
                    }

                    PrimeIterator& begin() override {
                            this->set_curr_index(0);
                            return *this;
                        }

                    PrimeIterator& end() override{
                        this->set_curr_index(static_cast<int>(this->get_container().get_prime().size()));
                        return *this; 
                    }

                    int& operator*() override{
                        return *(get_container().get_prime()[static_cast<vector<int>::size_type>(get_curr_index())]);
                    }

                    PrimeIterator& operator++() override{
                        if(get_curr_index() == this->get_container().get_prime().size()){
                            throw runtime_error("in the end");
                        }
                        this->set_curr_index(this->get_curr_index()+1);
                        return *this;
                    }
            };
// ///////////////////////////////////////////////////////////////////////////////////////////
            class SideCrossIterator :public highIterator{

                public:

                    SideCrossIterator(MagicalContainer &container): highIterator(container){
                    }
            
                    SideCrossIterator& begin() override {
                    this->set_curr_right(static_cast<int> (get_container().get_vector().size()-1));
                        this->set_curr_index(0);
                        return *this;
                    }
                    SideCrossIterator& end() override{
                    this->set_curr_index(static_cast<int>(get_container().get_vector().size()));
                        this->set_curr_right(0);
                        return *this;        
                    }

                    int& operator*() override{

                        if(this->get_right()){

                            return get_container().get_vector()[static_cast<vector<int>::size_type>(this->get_curr_right())];
                        }
                        return get_container().get_vector()[static_cast<vector<int>::size_type>(this->get_curr_index())];
                    }

                    SideCrossIterator& operator++() override{
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

        
                };
    }; 
}
# endif