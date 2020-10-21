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

    t max(){
        t max = set[0];
        for( int i = 0; i < used; i++ ){
            if( set[i] > max ){
                max = set[i];
            }
        }
        return max;
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

std::ostream & operator<<( std::ostream & lhs, const std::array<char, 3> & rhs){
    for( int i = 0; i < 3; i++){
        lhs << rhs[i] << ", ";
    }
    return lhs;
}

template< int charsize>
bool operator>( std::array<char, charsize> & lhs, std::array<char, charsize> & rhs ){
    char lhssize = 0;
    char rhssize = 0;
    for( int i = 0; i < charsize; i++ ){
        lhssize += lhs[i];
        rhssize += rhs[i];
    }
    return lhssize > rhssize;
}

#endif //INTGROUP_HPP