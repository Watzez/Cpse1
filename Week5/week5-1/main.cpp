#define CATCH_CONFIG_MAIN
#include "../../Catch2/single_include/catch2/catch.hpp"

#include "intgroup.hpp"

TEST_CASE( "Constructor and print empty set" ){
    intgroup test;
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "" );
}

TEST_CASE( "Add values" ){
    intgroup test;
    test.add( 1 );
    test.add( 2 );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "1, 2, ");
}

TEST_CASE( "Add used values" ){
    intgroup test;
    test.add( 1 );
    test.add( 2 );
    test.add( 1 );
    test.add( 2 );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "1, 2, ");
}

TEST_CASE( "Remove unused number" ){
    intgroup test;
    test.add( 1 );
    test.add( 2 );
    test.remove( 3 );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "1, 2, ");
}

TEST_CASE( "Remove used number" ){
    intgroup test;
    test.add( 1 );
    test.add( 2 );
    test.remove( 1 );
    std::stringstream output;
    output << test;
    REQUIRE( output.str() == "2, ");
}

TEST_CASE( "contains" ){
    intgroup test;
    test.add( 1 );
    REQUIRE( test.contains( 1 ) );
}

TEST_CASE( "does not contain" ){
    intgroup test;
    test.add( 1 );
    REQUIRE( !test.contains( 2 ) );
}