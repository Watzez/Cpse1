#ifndef INTGROUP_HPP
#define INTGROUP_HPP

#include <iostream>

template< typename t, int size>
class intgroup{
private:
    t set[size];
    int used;
public:
    intgroup(){
        for( int i = 0; i < size; i++ ){
            set[i] = 0;
        }
        used = 0;
    }

    void add(t newT){
        for( int i = 0; i < used; i++ ){
            if( set[i] == newT ){
                return;
            }
        }
        if( used < size ){
            set[used] = newT;
            used++;
        }
    }

    void remove(t removeT){
        for( int i = 0; i < used; i++ ){
            if( set[i] == removeT ){
                used--;
                for( int j = i; j < used; j++ ){
                    set[j] = set[j+1];
                }
            }
        }
    }

    bool contains(t check){
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