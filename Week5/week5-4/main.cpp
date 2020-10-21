#define CATCH_CONFIG_MAIN
#include "../../Catch2/single_include/catch2/catch.hpp"

#include "intgroup.hpp"

TEST_CASE( "Constructor and print empty set int" ){
    intgroup<int, 8> test;
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "" );
}

TEST_CASE( "Constructor and print empty set char" ){
    intgroup<char, 10> test;
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "" );
}

TEST_CASE( "Add values int" ){
    intgroup<int, 7> test;
    test.add( 1 );
    test.add( 2 );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "1, 2, ");
}

TEST_CASE( "Add values char" ){
    intgroup<char, 8> test;
    test.add( 'a' );
    test.add( 'b' );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "a, b, ");
}

TEST_CASE( "Add used values int" ){
    intgroup<int, 6> test;
    test.add( 1 );
    test.add( 2 );
    test.add( 1 );
    test.add( 2 );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "1, 2, ");
}

TEST_CASE( "Add used values char" ){
    intgroup<char, 6> test;
    test.add( 'a' );
    test.add( 'a' );
    test.add( 'b' );
    test.add( 'c' );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "a, b, c, ");
}

TEST_CASE( "Remove unused number" ){
    intgroup<int, 10> test;
    test.add( 1 );
    test.add( 2 );
    test.remove( 3 );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "1, 2, ");
}

TEST_CASE( "Remove unused char" ){
    intgroup<char, 10> test;
    test.add( 'a' );
    test.add( 'b' );
    test.remove( 'c' );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "a, b, ");
}

TEST_CASE( "Remove used number" ){
    intgroup<int, 10> test;
    test.add( 1 );
    test.add( 2 );
    test.remove( 1 );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "2, ");
}

TEST_CASE( "Remove used number char" ){
    intgroup<char, 10> test;
    test.add( 'a' );
    test.add( 'b' );
    test.remove( 'a' );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "b, ");
}

TEST_CASE( "contains" ){
    intgroup<int, 10> test;
    test.add( 1 );
    REQUIRE( test.contains( 1 ) );
}


TEST_CASE( "contains char" ){
    intgroup<char, 3> test;
    test.add( 'a' );
    REQUIRE( test.contains( 'a' ) );
}

TEST_CASE( "does not contain" ){
    intgroup<int, 10> test;
    test.add( 1 );
    REQUIRE( !test.contains( 2 ) );
}

TEST_CASE( "does not contain char" ){
    intgroup<char, 4> test;
    test.add( 'a' );
    REQUIRE( !test.contains( 'b' ) );
}

TEST_CASE( "max char test" ){
    intgroup<char, 10> test;
    test.add( 'a' );
    test.add( 'b' );
    REQUIRE( test.max() == 'b' );
}

TEST_CASE( "max int test" ){
    intgroup<int, 10> test;
    test.add( 1 );
    test.add( 2 );
    REQUIRE( test.max() == 2 );
}

TEST_CASE( "std array char 3" ){
    intgroup< std::array<char,3>, 10> test;
    test.add( {'W', 'T', 'F'});
    test.add( {'D', 'A', 'K'});
    test.add( {'T', 'A', 'K'});
    test.add( {'L', 'N', 'G'});
    std::stringstream output;
    output << test.max();
    REQUIRE( output.str() == "W, T, F, " );
}