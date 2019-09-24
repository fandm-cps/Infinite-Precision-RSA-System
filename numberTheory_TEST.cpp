#include "catch.hpp"
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"


#ifdef CATCH_CONFIG_MAIN
TEST_CASE("TESTING numberTheory Class"){
    numberTheory nT;

    SECTION("Extended Eulid Algorithm"){
        ReallyLongInt a(5);
        ReallyLongInt b(3);
        arrReallyLongInt tmp = nT.extendedEulid(a, b);
        INFO("1 = 5*(-1)+3*(2)")
        REQUIRE((tmp.arr[0]).toString() == "1");
        REQUIRE((tmp.arr[1]).toString() == "-1");
        REQUIRE((tmp.arr[2]).toString() == "2");

        a = ReallyLongInt(5);
        b = ReallyLongInt(5);
        tmp = nT.extendedEulid(a, b);
        INFO("5 = 5*(0)+5*(1)")
        REQUIRE((tmp.arr[0]).toString() == "5");
        REQUIRE((tmp.arr[1]).toString() == "0");
        REQUIRE((tmp.arr[2]).toString() == "1");

        b = ReallyLongInt(-3);
        tmp = nT.extendedEulid(a, b);
        INFO("-1 = 5*(1)+-3*(2)")
        REQUIRE((tmp.arr[0]).toString() == "-1");
        REQUIRE((tmp.arr[1]).toString() == "1");
        REQUIRE((tmp.arr[2]).toString() == "2");

        a = ReallyLongInt(3);
        b = ReallyLongInt(5);
        tmp = nT.extendedEulid(a, b);
        INFO("1 = 3*(2)+5*(-1)")
        REQUIRE((tmp.arr[0]).toString() == "1");
        REQUIRE((tmp.arr[1]).toString() == "2");
        REQUIRE((tmp.arr[2]).toString() == "-1");

        a = ReallyLongInt(20);
        b = ReallyLongInt(5);
        tmp = nT.extendedEulid(a, b);
        INFO("5 = 20*(0)+5*(1)")
        REQUIRE((tmp.arr[0]).toString() == "5");
        REQUIRE((tmp.arr[1]).toString() == "0");
        REQUIRE((tmp.arr[2]).toString() == "1");
    }
}

#endif