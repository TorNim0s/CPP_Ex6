#include "doctest.h"
#include "sources/League.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Custom Team"){
    vector<Team*> teams;

    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test1")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test2")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test3")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test4")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test5")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test6")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test7")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test8")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test9")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test10")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test11")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test12")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test13")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test14")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test15")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test16")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test17")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test18")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test19")));
    CHECK_NOTHROW(teams.emplace_back(new Team(0.5, "test20")));

    League league(teams);
    CHECK_NOTHROW(league.startLeague());
    CHECK_THROWS(league.startLeague());
    
    CHECK_NOTHROW(league.showStatistics());
}

TEST_CASE("Empty Team"){
    League league;
    
    CHECK_NOTHROW(league.startLeague());
    CHECK_THROWS(league.startLeague());
    
    CHECK_NOTHROW(league.showStatistics());
}