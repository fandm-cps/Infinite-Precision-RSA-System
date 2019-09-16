#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ReallyLongInt.hpp"


#ifdef CATCH_CONFIG_MAIN
TEST_CASE("TESTING ReallyLongInt Class"){
    ReallyLongInt* test_int_a;
    ReallyLongInt* test_int_b;
    ReallyLongInt* test_int_c;

    SECTION("Default Constructor"){
        test_int_a = new ReallyLongInt();

        INFO("Using default constructor")

        REQUIRE(test_int_a->toString() == "0");

        REQUIRE(test_int_a->toStringBinary() == "0000000000000000");

        delete test_int_a;
    }

    SECTION("Sets Based On Num Constructor"){
        long long num = 0;
        test_int_a = new ReallyLongInt(num);

        INFO("Sets To Be 0")

        REQUIRE(test_int_a->toString() == "0");

        REQUIRE(test_int_a->toStringBinary() == "0");

        test_int_a = new ReallyLongInt(9223372036854775807);

        INFO("Check Max")
        REQUIRE(test_int_a->toString() == "9223372036854775807");

        REQUIRE(test_int_a->toStringBinary() == "0111111111111111111111111111111111111111111111111111111111111111");        

        test_int_a = new ReallyLongInt(-9223372036854775807);

        INFO("Check Min")
        REQUIRE(test_int_a->toString() == "-9223372036854775807");

        REQUIRE(test_int_a->toStringBinary() == "0111111111111111111111111111111111111111111111111111111111111111");
    
        delete test_int_a;
    }

    SECTION("String Constructor"){
        test_int_a = new ReallyLongInt("123456");

        INFO("Sets To Be String 123456")

        REQUIRE(test_int_a->toString() == "123456");

        REQUIRE(test_int_a->toStringBinary() == "00000000000000011110001001000000");

        delete test_int_a;
    }
    
    SECTION("Equal Test"){
        test_int_a = new ReallyLongInt("123456");
        test_int_b = new ReallyLongInt(123456);
        test_int_c = new ReallyLongInt(-1234);

        INFO("a = b")
        REQUIRE(test_int_a->equal(*test_int_b));

        INFO("a != c")
        REQUIRE_FALSE(test_int_b->equal(*test_int_c));

        delete test_int_a;
        delete test_int_b;
        delete test_int_c;
    }

    SECTION("Copy Constructor"){
        test_int_a = new ReallyLongInt("123456");
        test_int_b = new ReallyLongInt(*test_int_a);


        INFO("a = b")
        REQUIRE(test_int_a->equal(*test_int_b));
        
        INFO("b = a")
        REQUIRE(test_int_b->equal(*test_int_a));

        delete test_int_a;
        delete test_int_b;
    }
    

    SECTION("Greater Test"){
        test_int_a = new ReallyLongInt(123);
        test_int_b = new ReallyLongInt(-123);

        INFO("a > b")
        REQUIRE(test_int_a->greater(*test_int_b));
        
        INFO("a !> b")
        REQUIRE_FALSE(test_int_b->greater(*test_int_a));

        delete test_int_a;
        delete test_int_b;
    }
}

#endif