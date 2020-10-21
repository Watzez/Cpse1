#ifndef COS_SIN_LOOKUP_HPP
#define COS_SIN_LOOKUP_HPP
#include <cmath>

class cos_lookup{
private:
    std::array< float, 60 > values;
public:

    constexpr cos_lookup():
        values{}
    {
        for( int i = 0; i < 60; i ++ ){
            values[i] = cos( i * 6 * 3.14159265 / 180.0);
        }
    }

    constexpr float get( int n ) const{
        return values[ n ];
    }
};


class sin_lookup{
private:
    std::array< float, 60 > values;
public:

    constexpr sin_lookup():
        values{}
    {
        for( int i = 0; i < 60; i ++ ){
            values[i] = sin( i * 6 * 3.14159265 / 180.0);
        }
    }

    constexpr float get( int n ) const{
        return values[ n ];
    }
};



#endif //COS_SIN_LOOKUP_HPP