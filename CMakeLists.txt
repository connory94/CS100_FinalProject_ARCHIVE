CMAKE_MINIMUM_REQUIRED(VERSION 2.8)


include_directories(Biomes)


add_subdirectory(googletest)
include_directories(googletest/googletest/include)

ADD_EXECUTABLE(allBiomeTests
    test/Biome_test.cpp
    Biomes/TremorousCaves.cpp
    Biomes/StarterForest.cpp
    Biomes/KingsLand.cpp
    Biomes/DesertOfDeath.cpp
    Biomes/Pathways.cpp
    Biomes/shop.cpp
    Player/Inventory.cpp
    Player/Player.cpp
    combatCMake/combatSrc/enemy.cpp
    combatCMake/combatSrc/oasisguard.cpp
    combatCMake/combatSrc/sandworm.cpp
    combatCMake/combatSrc/sunkwarden.cpp
    combatCMake/combatSrc/gatekeeper.cpp
    combatCMake/combatSrc/villcultist.cpp
    combatCMake/combatSrc/madking.cpp
    combatCMake/combatSrc/gobgrunt.cpp
    combatCMake/combatSrc/cabinspirit.cpp
    combatCMake/combatSrc/overbat.cpp
    combatCMake/combatSrc/crygolem.cpp
    combatCMake/combatSrc/queenspider.cpp
    combatCMake/combatSrc/character.cpp
    combatCMake/combatSrc/darkgobshaman.cpp
)

target_link_libraries(allBiomeTests
    gtest
    gtest_main
)

TARGET_LINK_LIBRARIES(allBiomeTests gtest)
TARGET_COMPILE_DEFINITIONS(allBiomeTests PRIVATE gtest_disable_pthreads=ON)


include_directories(ScreenDisplay/header)
include_directories(ScreenDisplay/src)
include_directories(ScreenDisplay/test)

ADD_EXECUTABLE(allDisplayTests
    ScreenDisplay/test/test.cpp
    ScreenDisplay/src/ReadScreenFile.cpp
    ScreenDisplay/src/ScreenDisplay.cpp
    ScreenDisplay/src/Hotbar.cpp
)

target_link_libraries(allDisplayTests
    gtest
    gtest_main
)

TARGET_LINK_LIBRARIES(allDisplayTests gtest)
TARGET_COMPILE_DEFINITIONS(allDisplayTests PRIVATE gtest_disable_pthreads=ON)

include_directories(combatCMake/combatHeader)
include_directories(Player)

ADD_EXECUTABLE(allCombatTests
    test/combatTest.cpp
    combatCMake/combatSrc/character.cpp
    combatCMake/combatSrc/cplayer.cpp
    combatCMake/combatSrc/enemy.cpp
    combatCMake/combatSrc/combat.cpp
    combatCMake/combatSrc/combatdisplay.cpp
    Player/Inventory.cpp
    Player/Player.cpp
)

target_link_libraries(allCombatTests
    gtest
    gtest_main
)

TARGET_LINK_LIBRARIES(allCombatTests gtest)
TARGET_COMPILE_DEFINITIONS(allCombatTests PRIVATE gtest_disable_pthreads=ON)


ADD_EXECUTABLE(allPlayerTests
    test/PlayerTests.cpp
    Player/Inventory.cpp
    Player/Player.cpp
    Player/Boots.h
    Player/DefensePotion.h
    Player/HealthPotion.h
    Player/Shield.h
    Player/SpeedPotion.h
    Player/Staff.h
    Player/StrengthPotion.h
    Player/Sword.h
)

target_link_libraries(allPlayerTests
    gtest
    gtest_main
)

TARGET_LINK_LIBRARIES(allPlayerTests gtest)
TARGET_COMPILE_DEFINITIONS(allPlayerTests PRIVATE gtest_disable_pthreads=ON)