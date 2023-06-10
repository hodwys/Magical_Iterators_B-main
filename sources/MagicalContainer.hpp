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

            // ~MagicalContainer()= default; 
            // MagicalContainer (const MagicalContainer &other):mystical_elements(other.mystical_elements), prime_vector(other.prime_vector) {}

            // MagicalContainer& operator=(const MagicalContainer& other) {
            //         if (this != &other){
            //             this->mystical_elements = other.mystical_elements;
            //         }
            //         return *this;
            // }
            //     // Move constructor
            //     MagicalContainer(MagicalContainer&& other) noexcept {
            //     }
            //     // Move assignment operator
            //     MagicalContainer& operator=(MagicalContainer&& other) noexcept {
            //         if (this != &other){
            //             this->mystical_elements = move(other.mystical_elements);
            //         }
            //         return *this;
            //     }
                
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
                highIterator(highIterator&& other) noexcept : container(other.container), curr_index(other.curr_index),curr_right(other.curr_right),right(other.right), left(other.left) {

                    if (this != &other) {
                    other.curr_index = 0;
                    other.curr_right = 0;
                    other.left = false;
                    other.right = false;
                    }
                }

                // Move assignment operator
                highIterator& operator=(highIterator&& other) noexcept;
           
                bool get_right() const;
                bool get_left() const;
                void set_right(bool right);
                void set_left(bool left);
                int get_curr_index() const;
                void set_curr_index(int other_index);
                int get_curr_right() const;
                void set_curr_right(int other_index);
                MagicalContainer& get_container() const;

                virtual highIterator& begin()=0;
                virtual highIterator& end();
                virtual int& operator*() = 0;
                virtual highIterator& operator++() = 0;
               
                bool operator<(const highIterator& other_iterator) const; 
                bool operator>(const highIterator& other_iterator) const; 
                bool operator==(const highIterator& other) const;
                // Inequality comparison operator
                bool operator!=(const highIterator& other) const;
                // Copy assignment operator
                highIterator& operator=(const highIterator& other);
            };

/////////////////////////////////////////////////////////////////////////////////////////////////////////
            class AscendingIterator : public highIterator{
     
                public:
                    AscendingIterator(MagicalContainer &container): highIterator(container){
                    }
                
                    AscendingIterator& begin() override;
                    int& operator*() override;
                    AscendingIterator& operator++() override;

            };
/////////////////////////////////////////////////////////////////////////////////////////

            class PrimeIterator : public highIterator {

                public:

                    PrimeIterator(MagicalContainer &container): highIterator(container){
                    }

                    PrimeIterator& begin() override;
                    PrimeIterator& end() override;
                    int& operator*() override;
                    PrimeIterator& operator++() override;
            };
/////////////////////////////////////////////////////////////////////////////////////////////
            class SideCrossIterator :public highIterator{

                public:

                    SideCrossIterator(MagicalContainer &container): highIterator(container){
                    }
                     SideCrossIterator& begin() override;
                    int& operator*() override;
                    SideCrossIterator&  operator++() override;
                };
    }; 
}
# endif