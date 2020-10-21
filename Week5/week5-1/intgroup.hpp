#ifndef INTGROUP_HPP
#define INTGROUP_HPP

#include <iostream>

class intgroup{
private:
    int set[10];
    int used;
public:
    intgroup(){
        for( int i = 0; i < 10; i++ ){
            set[i] = 0;
        }
        used = 0;
    }

    void add(int newInt){
        for( int i = 0; i < used; i++ ){
            if( set[i] == newInt ){
                return;
            }
        }
        if( used < 10 ){
            set[used] = newInt;
            used++;
        }
    }

    void remove(int removeInt){
        for( int i = 0; i < used; i++ ){
            if( set[i] == removeInt ){
                used--;
                for( int j = i; j < used; j++ ){
                    set[j] = set[j+1];
                }
            }
        }
    }

    bool contains(int check){
        for( int i = 0; i < used; i++ ){
            if( check == set[i] ){
                return true;
            }
        }
        return false;
    }

    friend std::ostream & operator<<( std::ostream & lhs, const intgroup & rhs ){
        for( int i = 0; i < rhs.used; i++){
            lhs << rhs.set[i] << ", ";
        }
        return lhs;
    }

};


#endif //INTGROUP_HPP