#include "catch.hpp"
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"


#ifdef CATCH_CONFIG_MAIN
TEST_CASE("TESTING numberTheory Class"){
    numberTheory nT;
    ReallyLongInt* d = new ReallyLongInt();
    ReallyLongInt* x = new ReallyLongInt();
    ReallyLongInt* y = new ReallyLongInt();

    SECTION("Extended Eulid Algorithm"){
        ReallyLongInt a(5);
        ReallyLongInt b(3);
        nT.extendedEulid(a, b, d, x, y);

        INFO("1 = 5*(-1)+3*(2)")
        REQUIRE(d->equal(1));
        REQUIRE(x->equal(-1));
        REQUIRE(y->equal(2));

        a = ReallyLongInt(5);
        b = ReallyLongInt(5);
        nT.extendedEulid(a, b, d, x, y);
        INFO("5 = 5*(0)+5*(1)")
        REQUIRE(d->equal(5));
        REQUIRE(x->equal(0));
        REQUIRE(y->equal(1));

        b = ReallyLongInt(-3);
        nT.extendedEulid(a, b, d, x, y);
        INFO("-1 = 5*(1)+-3*(2)")
        REQUIRE(d->equal(-1));
        REQUIRE(x->equal(1));
        REQUIRE(y->equal(2));

        a = ReallyLongInt(3);
        b = ReallyLongInt(5);
        nT.extendedEulid(a, b, d, x, y);
        INFO("1 = 3*(2)+5*(-1)")
        REQUIRE(d->equal(1));
        REQUIRE(x->equal(2));
        REQUIRE(y->equal(-1));

        a = ReallyLongInt(20);
        b = ReallyLongInt(5);
        nT.extendedEulid(a, b, d, x, y);
        INFO("5 = 20*(0)+5*(1)")
        REQUIRE(d->equal(5));
        REQUIRE(x->equal(0));
        REQUIRE(y->equal(1));
        
        delete d;
        delete x;
        delete y;
    }
}

#endif
