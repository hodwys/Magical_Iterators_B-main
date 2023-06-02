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

        bool static is_prime(int num){
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
        // void sort_prime(int * start, int* end){
        //   while (start<= end)
        //   {
            
        //   }
          
        // }

        public:

            bool operator==(const MagicalContainer& other) const {
                return mystical_elements == other.mystical_elements;
            }

            MagicalContainer(){}

            void addElement(int num_to_add){
                for(int element : mystical_elements){
                    if(num_to_add == element){
                        return;
                    }
                }

                mystical_elements.push_back(num_to_add);


                if(is_prime(num_to_add)){
                    //prime_vector.push_back(&num_to_add);

                    int *pointer = new int(num_to_add);
                    prime_vector.push_back( pointer );

                }
                sort(mystical_elements.begin(),mystical_elements.end());
                sort(prime_vector.begin(), prime_vector.end(), [](int* a, int* b) {return *a < *b;});
            }




// void MagicalContainer::addElement(int num) {
//     auto it = std::lower_bound(container.begin(), container.end(), num);
//     container.insert(it, num);
//     if(isPrime(num))
//     {

//     }
// }

            void removeElement(int num_to_remove){
                bool remov =  false;
                for(auto i= mystical_elements.begin(); i!=mystical_elements.end();i++){
                    if(*i == num_to_remove){
                        mystical_elements.erase(i);
                        i--;
                        remov = true;
                        if(is_prime(num_to_remove)){
                            int* elementToRemove = &num_to_remove;
                            auto it = std::find(prime_vector.begin(), prime_vector.end(), elementToRemove);
                            prime_vector.erase(it);
                            delete elementToRemove;
                            // prime_vector.erase(&num_to_remove);
                        }

                    }
                }
                // sort(mystical_elements.begin(),mystical_elements.end());
                // sort(prime_vector.begin(), prime_vector.end(), [](int* a, int* b) {return *a < *b;});
                if(!remov){
                    throw runtime_error("imposible to remov");

                }
            }
         
            int size() {
                return static_cast<int>(mystical_elements.size());
            }

            vector<int>& get_vector(){
                return mystical_elements;
            }

            const vector<int*>& get_prime(){
                //sort(prime_vector.begin() , prime_vector.end());
                return prime_vector;
            }

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
                    // Move constructor implementation
                }

                // Move assignment operator
                MagicalContainer& operator=(MagicalContainer&& other) noexcept {
                    if (this != &other){
                        this->mystical_elements = other.mystical_elements;
                    }
                    return *this;
                }
                


        //public:

            class AscendingIterator{
                 
                MagicalContainer &container;
                //vector<MagicalContainer*> &container;
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
    
                    int& operator*() const {
                        return container.get_vector()[(curr_index)];
                    }
    

                    //Destructor
                    ~AscendingIterator() = default;

                    // Copy constructor
                    AscendingIterator(const AscendingIterator& other) :container(other.container),curr_index(other.curr_index){
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


            class PrimeIterator{

                int curr_index;
                MagicalContainer &container;

                public:

                PrimeIterator(MagicalContainer &container): container(container), curr_index(0){
                    // vector<int> is_prime_vector ={};
                    // for(size_t i = 0; i<container.size(); i++){
                    //     if(is_prime(container.get_vector()[i])){
                    //         is_prime_vector.push_back(container.get_vector()[i]);
                    //     }
                    // }
                    // sort(is_prime_vector.begin(),is_prime_vector.end());

                    // container.set_mystical_elements(is_prime_vector);
                }


                PrimeIterator& begin() {
                    this->curr_index = 0;
                    return *this;
                }
                PrimeIterator end(){
                    this->curr_index = container.get_prime().size();
                    return *this; 
                }


//Copy constructor
                PrimeIterator(const PrimeIterator& other_container) : container(other_container.container) ,curr_index( other_container.curr_index ){} //Copy constructor

                int& operator*() const {
                   // cout<<"rgrh"<<endl;
                    return *(container.get_prime()[static_cast<vector<int>::size_type>(curr_index)]);
                }

                PrimeIterator& operator++(){
                    // Increment the index
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



                 // Default destructor
                ~PrimeIterator() = default;

            

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
                        *this = other.container;
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

            class SideCrossIterator{
                 
                MagicalContainer &container;
                int curr_right ;
                int curr_left;
                bool right ;
                bool left ;
                

                public:

                bool get_right(){
                    return this->right;
                }
                bool get_left(){
                    return this->left;
                }                
                void set_right(bool chenge){
                    this->right = chenge;
                }
                
                void set_left(bool chenge){
                    this->left = chenge;
                }

                SideCrossIterator(MagicalContainer &container): container(container), curr_right(container.get_vector().size()-1), curr_left(0), left(true), right(false){

                //     int ijk = 0;
                //     size_t beagin = 0;
                //     size_t end = container.get_vector().size()-1;
                //     //vector<int> cross ={};
                // //    sort(container.get_vector().begin(),container.get_vector().end());


                //     while(beagin <= end){

                //         if (beagin == end){
                //             cross.push_back(container.get_vector()[beagin]);
                //             break;
                //         }
                //         if(ijk % 2 == 0){
                //             cross.push_back(container.get_vector()[beagin]);
                //             beagin++;
                //         }

                //         else{
                //             cross.push_back(container.get_vector()[end] );
                //             end--;
                //         }
                //         ijk++;
                //     }
            
                //               container.set_mystical_elements(cross);
                 }
          
                 SideCrossIterator begin() {
                   this->curr_right = container.get_vector().size()-1;
                    this->curr_left = 0;
                    return *this;
                }
                 SideCrossIterator end(){
                   this->curr_left =  container.get_vector().size();
                    this->curr_right =0;
                    return *this;        
                }


            int& operator*(){

                if(get_right()){

                    return container.get_vector()[static_cast<vector<int>::size_type>(curr_right)];
                }
                else{
  
                    return container.get_vector()[static_cast<vector<int>::size_type>(curr_left)];
                }
            }

            SideCrossIterator& operator++(){
                // Increment the index
                if(curr_right ==  0 && curr_left == this->container.get_vector().size()){
                    throw runtime_error("in the end");
                }

                if(get_right()){
                    set_right(false);
                    set_left(true);
                    curr_right --;
                }
                else{
                    set_right(true);
                    set_left(false); 
                    curr_left++;
                }
                if(curr_right < curr_left){
                    curr_left = container.get_vector().size();
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


            ~SideCrossIterator() = default;

                // Copy constructor
                SideCrossIterator(const SideCrossIterator& other): container(other.container), curr_left(other.curr_left), curr_right(other.curr_right), right(other.right), left(other.left) {
                    // Copy constructor implementation
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
                       *this = other.container;
                        curr_right = other.curr_right;
                        curr_left = other.curr_left;
                        right = other.right;
                        left = other.left;
                    }
                    return *this;
                }

                bool operator>(const SideCrossIterator& other_iterator) const{

                    if(right){
                        return (this->right > other_iterator.right);
                    }
                    else{
                        return (this->left > other_iterator.left);                        
                    }
                }

                bool operator<(const SideCrossIterator& other_iterator) const{

                    if(right){
                        return (this->right < other_iterator.right);
                    }
                    else{
                        return (this->left < other_iterator.left);                        
                    }
                }
                
            };
    }; 
}
# endif