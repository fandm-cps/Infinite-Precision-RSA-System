#include "catch.hpp"
#include "ReallyLongInt.hpp"


#ifdef CATCH_CONFIG_MAIN
TEST_CASE("TESTING ReallyLongInt Class"){
    ReallyLongInt* test_int_a;
    ReallyLongInt* test_int_b;
    ReallyLongInt* test_int_c;
    ReallyLongInt* test_int_d;

    SECTION("Default Constructor"){
        test_int_a = new ReallyLongInt();

        INFO("Using default constructor")

        REQUIRE(test_int_a->toString() == "0");

        REQUIRE(test_int_a->toStringBinary() == "0");

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

        REQUIRE(test_int_a->toStringBinary() == "111111111111111111111111111111111111111111111111111111111111111");

        test_int_a = new ReallyLongInt(-9223372036854775807);

        INFO("Check Min")
        REQUIRE(test_int_a->toString() == "-9223372036854775807");

        REQUIRE(test_int_a->toStringBinary() == "111111111111111111111111111111111111111111111111111111111111111");
    
        delete test_int_a;
    }

    SECTION("String Constructor"){
        test_int_a = new ReallyLongInt("4611686018427387904");

        INFO("Sets To Be String 4611686018427387904")

        REQUIRE(test_int_a->toString() == "4611686018427387904");

        REQUIRE(test_int_a->toStringBinary() == "100000000000000000000000000000000000000000000000000000000000000");

        test_int_b = new ReallyLongInt("-4611686018427387904");


        REQUIRE(test_int_b->toStringBinary() == "100000000000000000000000000000000000000000000000000000000000000");

        delete test_int_a;
        delete test_int_b;
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


        test_int_c = new ReallyLongInt("9999999");
        test_int_d = new ReallyLongInt(123);

        INFO("c > d")
        REQUIRE(test_int_c->greater(*test_int_d));
        
        INFO("d !> c")
        REQUIRE_FALSE(test_int_d->greater(*test_int_c));

        test_int_c = new ReallyLongInt(124);
        test_int_d = new ReallyLongInt(123);

        INFO("c > d")
        REQUIRE(test_int_c->greater(*test_int_d));
        
        INFO("d !> c")
        REQUIRE_FALSE(test_int_d->greater(*test_int_c));

        test_int_a = new ReallyLongInt(-123);
        test_int_b = new ReallyLongInt(-123);

        INFO("a > b")
        REQUIRE_FALSE(test_int_a->greater(*test_int_b));

        delete test_int_a;
        delete test_int_b;
        delete test_int_c;
        delete test_int_d;
    }

    SECTION("Add Test"){
        ReallyLongInt test_int_e(3);
        ReallyLongInt test_int_f(5);

        ReallyLongInt test_int_g = test_int_e + test_int_f;
        INFO("g = e + f")
        REQUIRE(test_int_g.toString() == "8");

        test_int_e = ReallyLongInt(-5);
        test_int_f = ReallyLongInt(-8);
        test_int_g = test_int_e + test_int_f;
        INFO("g = e + f")
        REQUIRE(test_int_g.toString() == "-13");

        ReallyLongInt a(8);
        ReallyLongInt b(-9);
        ReallyLongInt c = a + b;
        REQUIRE(c.toString() == "-1");

        a = b;
        b = ReallyLongInt(8);
        c = a + b;
        REQUIRE(c.toString() == "-1");
    }

    SECTION("Sub Test"){
        ReallyLongInt a(-5);
        ReallyLongInt b(-8);
        ReallyLongInt c = a - b;
        REQUIRE(c.toString() == "3");

        a = ReallyLongInt(3);
        b = ReallyLongInt(5);
        c = a - b;
        REQUIRE(c.toString() == "-2");

        a = ReallyLongInt(8);
        b = ReallyLongInt(-9);
        c = a - b;
        REQUIRE(c.toString() == "17");

        a = b;
        b = ReallyLongInt(8);
        c = a - b;
        REQUIRE(c.toString() == "-17");
    }

    SECTION("Multi Test"){
        ReallyLongInt a(-5);
        ReallyLongInt b(-8);
        ReallyLongInt c = a.mult(b);
        REQUIRE(c.toString() == "40");

        a = ReallyLongInt(3);
        b = ReallyLongInt(5);
        c = a.mult(b);
        REQUIRE(c.toString() == "15");

        a = ReallyLongInt(8);
        b = ReallyLongInt(-9);
        c = a.mult(b);
        REQUIRE(c.toString() == "-72");

        a = b;
        b = ReallyLongInt(8);
        c = a * b;
        REQUIRE(c.toString() == "-72");
    }

    SECTION("Division Test"){
        ReallyLongInt a(-5);
        ReallyLongInt b(-8);
        ReallyLongInt q;
        ReallyLongInt r; 
        a.div(b, q, r);
        REQUIRE(r.toString() ==  std::to_string(-5%(-8)));
        REQUIRE(q.toString() ==  std::to_string(-5/(-8)));

        a = ReallyLongInt(3);
        b = ReallyLongInt(5);
        a.div(b, q, r);
        REQUIRE(r.toString() ==  std::to_string(3%(5)));
        REQUIRE(q.toString() ==  std::to_string(3/(5)));

        a = ReallyLongInt(-19);
        b = ReallyLongInt(3);
        a.div(b, q, r);
        REQUIRE(r.toString() == std::to_string(-19%(3)));
        REQUIRE(q.toString() == std::to_string(-19/(3)));

        a = ReallyLongInt(123);
        b = ReallyLongInt(-2);
        REQUIRE((a%b).toString() == std::to_string(123%(-2)));
        REQUIRE((a/b).toString() == std::to_string(123/(-2)));

        a = ReallyLongInt(123);
        b = ReallyLongInt(2);
        REQUIRE((a%b).toString() == std::to_string(123%(2)));
        REQUIRE((a/b).toString() == std::to_string(123/(2)));
    }
    
    SECTION("Negation"){
        ReallyLongInt a(3);
        a = -a;
        REQUIRE(a.toString() == "-3");
    }

    SECTION("exp Test"){
        ReallyLongInt a(3);
        ReallyLongInt b(5);

        REQUIRE(((a.exp(b)).toString()) == "243");
        REQUIRE(((a.exp(0)).toString()) == "1");  

        a = ReallyLongInt(90);
        b = ReallyLongInt(4);
    }
    SECTION("Prime Test"){
        ReallyLongInt a(5);
        ReallyLongInt b(0);
        ReallyLongInt c(6);
        REQUIRE(a.isPrime());
        REQUIRE_FALSE(b.isPrime());
        REQUIRE_FALSE(c.isPrime());
    }
}

#endif