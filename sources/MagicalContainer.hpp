# ifndef MAGICALCONTAINER_HPP
# define MAGICALCONTAINER_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
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

            class AscendingIterator{
                 
                MagicalContainer &container;
                size_t curr_index;

                public:
                AscendingIterator(MagicalContainer &container): container(container), curr_index(0){
                }
            
                AscendingIterator begin(){
                    this ->curr_index = 0;
                    return *this;
                }
                AscendingIterator end(){
                    this->curr_index = container.get_vector().size();
                    return *this;
                }

                //Destructor
                ~AscendingIterator() = default;

                // Copy constructor
                AscendingIterator(const AscendingIterator& other) :container(other.container),curr_index(other.curr_index){
                }

                int& operator*() const {
                    return container.get_vector()[(curr_index)];
                }

                // Copy assignment operator
                AscendingIterator& operator=(const AscendingIterator& other) {
                    if(this->container != other.container){
                        throw runtime_error (" not the same iterator");
                    }
                    if (this != &other){
                        *this = other.container;
                        this->curr_index = other.curr_index;
                    }
                    return *this;
                }

                    // Move constructor
                    AscendingIterator(AscendingIterator&& other) noexcept : container(other.container), curr_index(other.curr_index) {
                    }

                // Move assignment operator
                AscendingIterator& operator=(AscendingIterator&& other) noexcept {

                    if (this != &other){
                        this->container = move(other.container);
                        this->curr_index = other.curr_index;
                        return *this;
                    }
                    return *this;
                }
                 
                AscendingIterator& operator++(){
                    if(curr_index == this->container.get_vector().size()){
                        throw runtime_error("in the end");
                    }
                    this->curr_index++;
                    return *this;
                }

                bool operator==(const AscendingIterator& other_iterator) const {
                    if(this->container == other_iterator.container){
                        bool eqa = (curr_index == other_iterator.curr_index);
                        return eqa;
                    }
                        return false;
                }

                bool operator!=(const AscendingIterator& other_iterator) const {
                    return !(curr_index == other_iterator.curr_index);
                }

                bool operator>(const AscendingIterator& other_iterator) const{
                    return (this->curr_index > other_iterator.curr_index);
                    }

                bool operator<(const AscendingIterator& other_iterator) const{
                    return (this->curr_index < other_iterator.curr_index);
                    }
            };
/////////////////////////////////////////////////////////////////////////////////////////

            class PrimeIterator{

                int curr_index;
                MagicalContainer &container;

                public:

                PrimeIterator(MagicalContainer &container): container(container), curr_index(0){
                }


                PrimeIterator& begin() {
                    this->curr_index = 0;
                    return *this;
                }
                PrimeIterator& end(){
                    this->curr_index = static_cast<int>(container.get_prime().size());
                    return *this; 
                }


                //Copy constructor
                PrimeIterator(const PrimeIterator& other_container) : container(other_container.container) ,curr_index( other_container.curr_index ){} //Copy constructor
                 
                 // Default destructor
                ~PrimeIterator() = default;

                int& operator*() const {
                    return *(container.get_prime()[static_cast<vector<int>::size_type>(curr_index)]);
                }

                PrimeIterator& operator++(){
                    if(curr_index == this->container.get_prime().size()){
                        throw runtime_error("in the end");
                    }
                    this->curr_index++;
                    return *this;
                }

                bool operator==(const PrimeIterator& other) const{

                    return curr_index == other.curr_index;
                }

                bool operator!=(const PrimeIterator& other) const{
                    return !(curr_index == other.curr_index);
                }

            
                // Copy assignment operator
                PrimeIterator& operator=(const PrimeIterator& other) {
                    if(this->container != other.container){
                        throw runtime_error (" not the same iterator");
                    }
                    if (this != &other){
                        *this = other.container;
                        this->curr_index = other.curr_index;
                    }
                    return *this;
                }

                // Move constructor
                PrimeIterator(PrimeIterator&& other) noexcept: container(other.container), curr_index(other.curr_index){
                }

                // Move assignment operator
                PrimeIterator& operator=(PrimeIterator&& other) noexcept {
                 
                    if (this != &other){
                        this->container = move(other.container);
                        this->curr_index = other.curr_index;
                    }
                    return *this;
                }

                bool operator>(const PrimeIterator& other_iterator) const{
                    return (this->curr_index > other_iterator.curr_index);
                }

                bool operator<(const PrimeIterator& other_iterator) const{
                    return (this->curr_index < other_iterator.curr_index);
                }
            };
///////////////////////////////////////////////////////////////////////////////////////////
            class SideCrossIterator{
                 
                MagicalContainer &container;
                int curr_right ;
                int curr_left;
                bool right ;
                bool left ;

                public:

                    SideCrossIterator(MagicalContainer &container): container(container), curr_right(static_cast<int>(container.get_vector().size()-1)), curr_left(0), left(true), right(false){
                    }
            
                    SideCrossIterator begin() {
                    this->curr_right =static_cast<int> (container.get_vector().size()-1);
                        this->curr_left = 0;
                        return *this;
                    }
                    SideCrossIterator end(){
                    this->curr_left =  static_cast<int>(container.get_vector().size());
                        this->curr_right =0;
                        return *this;        
                    }

                    ~SideCrossIterator() = default;

                    int& operator*(){

                        if(this->right){

                            return container.get_vector()[static_cast<vector<int>::size_type>(curr_right)];
                        }
                        return container.get_vector()[static_cast<vector<int>::size_type>(curr_left)];
                    }

                    SideCrossIterator& operator++(){
                        // Increment the index
                        if(curr_right ==  0 && curr_left == this->container.get_vector().size()){
                            throw runtime_error("in the end");
                        }

                        if(this->right){
                            this->right = false;
                            this->left = true;
                            curr_right --;
                        }
                        else{
                            this->right = true; 
                            this->left = false;
                            curr_left++;
                        }
                        if(curr_right < curr_left){
                            curr_left = static_cast<int>(container.get_vector().size());
                            curr_right = 0;
                        }
                        return *this;
                    }

                    bool operator==(const SideCrossIterator& other) const{
                        if(this->container == other.container){
                            bool eqa = (curr_right == other.curr_right) && (curr_left == other.curr_left);
                            return eqa;
                        }
                        return false;
                    }

                    // Copy constructor
                    SideCrossIterator(const SideCrossIterator& other): container(other.container), curr_left(other.curr_left), curr_right(other.curr_right), right(other.right), left(other.left) {
                    }

                    // Copy assignment operator
                    SideCrossIterator& operator=(const SideCrossIterator& other) {
                        if(this->container != other.container){
                            throw runtime_error (" not the same iterator");
                        }
                        if(this->container != other.container){
                            throw runtime_error (" not the same iterator");
                        }
                        if (this != &other){
                        *this = other.container;
                            curr_right = other.curr_right;
                            curr_left = other.curr_left;
                            right = other.right;
                            left = other.left;
                        }

                        return *this;
                    }

                    // Move constructor
                    SideCrossIterator(SideCrossIterator&& other) noexcept : container(other.container), curr_left(other.curr_left), curr_right(other.curr_right), right(other.right), left(other.left){
                    }

                    // Move assignment operator
                    SideCrossIterator& operator=(SideCrossIterator&& other) noexcept {
                    
                        if (this != &other){
                            this->container = move(other.container);
                            curr_right = other.curr_right;
                            curr_left = other.curr_left;
                            right = other.right;
                            left = other.left;
                        }
                        return *this;
                    }

                    bool operator>(const SideCrossIterator& other_iterator) const{

                        if(right){
                            return (static_cast<int>(this->right) > static_cast<int>(other_iterator.right));
                        }
                        return (static_cast<int>(this->curr_left) >static_cast<int>( other_iterator.curr_left));                        
                    }

                    bool operator<(const SideCrossIterator& other_iterator) const{

                        if(right){
                            return (static_cast<int>(this->right) < static_cast<int>(other_iterator.right));
                        }
                        return (this->curr_left < other_iterator.curr_left);                        
                    }        
                };
    }; 
}
# endif