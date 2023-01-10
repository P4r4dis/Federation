#include "./tests_includes/test_war.hpp"
#include "./tests_includes/test_destination.hpp"



Test(Federation_Starfleet_Ship, test_constructor, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 0);
    
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n\
It is 289 m in length and 132 m in width.\n\
It can go to Warp 6!\n");
}

Test(WarpSystem_QuantumReactor, test_constructor)
{
    WarpSystem::QuantumReactor QR;

    cr_assert(QR.getStability() == true);
}

Test(WarpSystem_QuantumReactor, test_isStable)
{
    WarpSystem::QuantumReactor QR;

    cr_assert(QR.getStability() == true);
    cr_assert(QR.isStable() == true);
}

Test(WarpSystem_QuantumReactor, test_setStability)
{
    WarpSystem::QuantumReactor QR;

    cr_assert(QR.getStability() == true);
    cr_assert(QR.isStable() == true);
    QR.setStability(false);
    cr_assert(QR.getStability() == false);
    cr_assert(QR.isStable() == false);
}

Test(WarpSystem_Core, test_constructor)
{
    WarpSystem::QuantumReactor QR;
    WarpSystem::QuantumReactor QR2;

    WarpSystem::Core core(&QR);
    WarpSystem::Core core2(&QR2);

    cr_assert(core.checkReactor() == &QR);
    cr_assert(core2.checkReactor() == &QR2);

}

Test(Federation_Starfleet_Ship, test_setupCore, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 0);
    WarpSystem::QuantumReactor  QR;
    WarpSystem::Core            core(&QR);

    UssKreog.setupCore(&core);
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n\
It is 289 m in length and 132 m in width.\n\
It can go to Warp 6!\n\
USS Kreog: The core is set.\n");
}

Test(Federation_Starfleet_Ship, test_checkCore,.init=redirect_all_stdout)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 0);
    WarpSystem::QuantumReactor  QR;
    WarpSystem::Core            core(&QR);

    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n\
It is 289 m in length and 132 m in width.\n\
It can go to Warp 6!\n\
USS Kreog: The core is set.\n\
USS Kreog: The core is stable at the time.\n");
}


Test(Federation_Ship, test_constructor, .init=redirect_all_stdout)
{
    Federation::Ship Independent(150, 230, "Greok");
    
    cr_assert_stdout_eq_str("The independent ship Greok just finished its construction.\n\
It is 150 m in length and 230 m in width.\n");
}

Test(Federation_Ship, test_setupCore, .init=redirect_all_stdout)
{
    Federation::Ship Independent(150, 230, "Greok");
    WarpSystem::QuantumReactor  QR2;
    WarpSystem::Core            core2(&QR2);

    Independent.setupCore(&core2);
    cr_assert_stdout_eq_str("The independent ship Greok just finished its construction.\n\
It is 150 m in length and 230 m in width.\n\
Greok: The core is set.\n");
}

Test(Federation_Ship, test_checkCore, .init=redirect_all_stdout)
{
    Federation::Ship Independent(150, 230, "Greok");
    WarpSystem::QuantumReactor  QR2;
    WarpSystem::Core            core2(&QR2);

    Independent.setupCore(&core2);
    Independent.checkCore();
    cr_assert_stdout_eq_str("The independent ship Greok just finished its construction.\n\
It is 150 m in length and 230 m in width.\n\
Greok: The core is set.\n\
Greok: The core is stable at the time.\n");
}
/////////////////////////////////////////////////////////////////////////////////////////
//BORG
/////////////////////////////////////////////////////////////////////////////////////////
Test(Borg_Ship, test_constructor, .init=redirect_all_stdout)
{
    Borg::Ship Cube;
    
    cr_assert_stdout_eq_str("We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n\
Your biological characteristics and technologies will be assimilated.\n\
Resistance is futile.\n");
}

Test(Borg_Ship, test_setupCore, .init=redirect_all_stdout)
{
    Borg::Ship Cube;

    WarpSystem::QuantumReactor  QR2;
    cr_assert(QR2.getStability() == true);
    cr_assert(QR2.isStable() == true);

    WarpSystem::Core            core2(&QR2);
    cr_assert(core2.checkReactor() == &QR2);

    Cube.setupCore(&core2);
    cr_assert(Cube.getCore() == &core2);
    cr_assert_stdout_eq_str("We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n\
Your biological characteristics and technologies will be assimilated.\n\
Resistance is futile.\n");
}


Test(Borg_Ship, test_checkCore, .init=redirect_all_stdout)
{
    Borg::Ship Cube;

    WarpSystem::QuantumReactor  QR2;
    cr_assert(QR2.getStability() == true);
    cr_assert(QR2.isStable() == true);

    WarpSystem::Core            core2(&QR2);
    cr_assert(core2.checkReactor() == &QR2);

    Cube.setupCore(&core2);
    cr_assert(Cube.getCore() == &core2);

    Cube.checkCore();
    cr_assert_stdout_eq_str("We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n\
Your biological characteristics and technologies will be assimilated.\n\
Resistance is futile.\n\
Everything is in order.\n");
}

Test(Federation_Starfleet_Captain, test_CTOR)
{
    Federation::Starfleet::Captain  James("James T. Kirk");

    cr_assert(James.getName() == "James T. Kirk");
}

Test(Federation_Starfleet_Captain, test_getAge_and_setAge)
{
    Federation::Starfleet::Captain  James("James T. Kirk");

    James.setAge(5);
    cr_assert(James.getAge() == 5);

}


Test(Federation_Starfleet_Ship, test_promote, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 0);
    Federation::Starfleet::Captain  James("James T. Kirk");

    UssKreog.promote(&James);
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n\
It is 289 m in length and 132 m in width.\n\
It can go to Warp 6!\n\
James T. Kirk: I’m glad to be the captain of the USS Kreog.\n");
}

Test(Federation_Starfleet_Ensign, test_CTOR, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ensign   Ensign("Pavel Chekov");
    
    cr_assert_stdout_eq_str("Ensign Pavel Chekov, awaiting orders.\n");
}

////////////////////////////////////////////////////////////////////////

Test(Destination, test_enum)
{
    // Test that the enumeration values are correct
    cr_assert_eq(EARTH, 0);
    cr_assert_eq(VULCAN, 1);
    cr_assert_eq(UNICOMPLEX, 2);

    // Test that we can assign values to the enumeration
    Destination home;

    home = EARTH;
    cr_assert_eq(home, EARTH);

    home = VULCAN;
    cr_assert_eq(home, VULCAN);

    home = UNICOMPLEX;
    cr_assert_eq(home, UNICOMPLEX);
}

Test(Destination, test_CTOR_enum)
{
    Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 0);
    cr_assert(UssKreog.getLocation() == EARTH);
    cr_assert(UssKreog.getHome() == EARTH);
    Federation::Ship                Independent(150, 230, "Greok");
    cr_assert(Independent.getLocation() == VULCAN);
    cr_assert(Independent.getHome() == VULCAN);

    Borg::Ship                      Cube;
    cr_assert(Cube.getLocation() == UNICOMPLEX);
    cr_assert(Cube.getHome() == UNICOMPLEX);

}

Test(Destination, test_move)
{
    Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 0);
    WarpSystem::QuantumReactor      QR;
    WarpSystem::Core                core(&QR);

    UssKreog.setupCore(&core);
    cr_assert(UssKreog.getLocation() == EARTH);
    cr_assert(UssKreog.getHome() == EARTH);

    cr_assert(UssKreog.move(4, VULCAN) == true, "Move function returned false");
    cr_assert(UssKreog.getLocation() == VULCAN, "Incorrect location");

    cr_assert(UssKreog.move(5) == true, "Move function must returned true");
    cr_assert(UssKreog.getLocation() == EARTH, "Correct location is EARTH");

    cr_assert(UssKreog.move(UNICOMPLEX) == true, "Move function must returned true");
    cr_assert(UssKreog.getLocation() == UNICOMPLEX, "Correct location is UNICOMPLEX");

    cr_assert(UssKreog.move() == true, "Move function must returned true");
    cr_assert(UssKreog.getLocation() == EARTH, "Correct location is EARTH");

    Federation::Ship                Independent(150, 230, "Greok");
    Independent.setupCore(&core);
    cr_assert(Independent.getLocation() == VULCAN);
    cr_assert(Independent.getHome() == VULCAN);

    cr_assert(Independent.move(1, EARTH) == true, "Move function returned true");
    cr_assert(Independent.getLocation() == EARTH, "Incorrect location");

    cr_assert(Independent.move(1) == true, "Move function must returned true");
    cr_assert(Independent.getLocation() == VULCAN, "Correct location is VULCAN");

    cr_assert(Independent.move(UNICOMPLEX) == true, "Move function must returned true");
    cr_assert(Independent.getLocation() == UNICOMPLEX, "Correct location is UNICOMPLEX");

    cr_assert(Independent.move() == true, "Move function must returned true");
    cr_assert(Independent.getLocation() == VULCAN, "Correct location is VULCAN");

    Borg::Ship                      Cube;
    Cube.setupCore(&core);
    cr_assert(Cube.getLocation() == UNICOMPLEX);
    cr_assert(Cube.getHome() == UNICOMPLEX);

    cr_assert(Cube.move(1, EARTH) == true, "Move function returned true");
    cr_assert(Cube.getLocation() == EARTH, "Incorrect location");

    cr_assert(Cube.move(5) == true, "Move function must returned true");
    cr_assert(Cube.getLocation() == UNICOMPLEX, "Correct location is UNICOMPLEX");

    cr_assert(Cube.move(VULCAN) == true, "Move function must returned true");
    cr_assert(Cube.getLocation() == VULCAN, "Correct location is VULCAN");

    cr_assert(Cube.move() == true, "Move function must returned true");
    cr_assert(Cube.getLocation() == UNICOMPLEX, "Correct location is VULCAN");
}

////////////////////////////////////////////////////////////////////////////

Test(War, test_shield)
{
    Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 0);
    cr_assert(UssKreog.getShield() == 100);
    UssKreog.setShield(50);
    cr_assert(UssKreog.getShield() == 50);
    // Federation::Ship                Independent(150, 230, "Greok");
    // Borg::Ship                      Cube;
}

Test(War, test_torpedo_zero, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 0);
    cr_assert(UssKreog.getTorpedo() == 0);
    UssKreog.setTorpedo(50);
    cr_assert(UssKreog.getTorpedo() == 50);
    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n\
It is 289 m in length and 132 m in width.\n\
It can go to Warp 6!\n");
}

Test(War, test_torpedo_zero2, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship     UssKreog;

    cr_assert_stdout_eq_str("The ship USS Entreprise has been finished.\n\
It is 289 m in length and 132 m in width.\n\
It can go to Warp 6!\n");
}

Test(War, test_torpedo, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 50);

    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n\
It is 289 m in length and 132 m in width.\n\
It can go to Warp 6!\n\
Weapons are set: 50 torpedoes ready.\n");
}

Test(War, test_fire, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 50);
    Federation::Starfleet::Captain  James("James T. Kirk");
    UssKreog.promote(&James);
    Borg::Ship Cube;

    UssKreog.fire(70, &Cube);
    UssKreog.fire(50, &Cube);
    cr_assert(Cube.getShield() == 0);
    UssKreog.fire(1, &Cube);

    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n\
It is 289 m in length and 132 m in width.\n\
It can go to Warp 6!\n\
Weapons are set: 50 torpedoes ready.\n\
James T. Kirk: I’m glad to be the captain of the USS Kreog.\n\
We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n\
Your biological characteristics and technologies will be assimilated.\n\
Resistance is futile.\n\
Kreog: No more torpedo to fire, James T. Kirk!\n\
Kreog: Firing on target. 0 torpedoes remaining.\n\
Kreog: No enough torpedoes to fire, James T. Kirk!\n");
}

Test(War, test_fire2, .init=redirect_all_stdout)
{
    Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 1);
    Federation::Starfleet::Captain  James("James T. Kirk");
    UssKreog.promote(&James);
    Borg::Ship Cube;

    UssKreog.fire(&Cube);
    cr_assert(Cube.getShield() == 50);
    UssKreog.fire(&Cube);

    cr_assert_stdout_eq_str("The ship USS Kreog has been finished.\n\
It is 289 m in length and 132 m in width.\n\
It can go to Warp 6!\n\
Weapons are set: 1 torpedoes ready.\n\
James T. Kirk: I’m glad to be the captain of the USS Kreog.\n\
We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n\
Your biological characteristics and technologies will be assimilated.\n\
Resistance is futile.\n\
Kreog: Firing on target. 0 torpedoes remaining.\n\
Kreog: No enough torpedoes to fire, James T. Kirk!\n");
}

Test(Federation_Ship, test_getCore)
{
    Federation::Ship Independent(200, 100, "Entreprise");

    WarpSystem::QuantumReactor  QR2;
    cr_assert(QR2.getStability() == true);
    cr_assert(QR2.isStable() == true);

    WarpSystem::Core            core2(&QR2);
    cr_assert(core2.checkReactor() == &QR2);

    Independent.setupCore(&core2);
    cr_assert(Independent.getCore() == &core2);
}

// Test(SickKoala, ctorDefault) {

//         std::string     name;
//         SickKoala       sickKoala;

//         cr_assert(zero(str, name));
//         cr_assert(eq(str, name, ""));
//         cr_assert_str_empty(name.data());
//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
// }

// Test(SickKoala, ctorCustom) {

//         SickKoala       sickKoala("SickKoala");

//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
// }

// Test(SickKoala, ctorDefault_and_dtor,  .signal=SIGPIPE, .init=redirect_all_stdout) {
//         SickKoala sickKoala;
//         sickKoala.~SickKoala();
//         cr_assert_stdout_eq_str("Mr.SickKoala: Kreooogg!! I'm cuuuured!\n");
// }

// Test(SickKoala, ctorCustom_and_dtor,  .signal=SIGPIPE, .init=redirect_all_stdout) {
//         SickKoala sickKoala("SickKoala");
//         sickKoala.~SickKoala();
//         cr_assert_stdout_eq_str("Mr.SickKoala: Kreooogg!! I'm cuuuured!\n");
// }

// Test(poke, stdcout_poke_function, .signal=SIGPIPE, .init=redirect_all_stdout) {
//         SickKoala sickKoala("SickKoala");

//         sickKoala.poke();
//         cr_assert_stdout_eq_str("Mr.SickKoala: Gooeeeeerrk!!\n");
// }

// Test(takeDrug, strParameter_eq_MarsStrings_and_stdcout_caught,
//         .init=redirect_all_stdout)
// {
//         std::string     _name("SickKoala");
//         std::string     string = "Mars";
//         std::string     s_mars("Mars");
//         bool            return_value;

//         cr_assert(eq(str,string, s_mars));
//         if (string == s_mars)
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Mars, and it kreogs!\n");

//         }


// }

// Test(takeDrug, strParameter_notEq_MarsStrings_and_stdcout_caught,
//         .init=redirect_all_stdout)
// {
//         std::string     _name("SickKoala");
//         std::string     string = "Buronzand";
//         std::string     s_mars("Mars");
//         bool            return_value;

//         cr_assert(not(eq(str,string, s_mars)));
//         if (string == s_mars)
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Mars, and it kreogs!\n");

//         } else
//         {
//                 return_value = false;
//                 cr_assert(return_value == false);
//                 std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog!\n");                
//         }
// }

// Test(takeDrug, strParameter_eq_BuronzandStrings_and_stdcout_caught,
//         .init=redirect_all_stdout)
// {
//         std::string     _name("SickKoala");
//         std::string     string = "Buronzand";
//         std::string     s_buronzand("Buronzand");
//         bool            return_value;

//         cr_assert(eq(str,string, s_buronzand));
//         if (string == s_buronzand)
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": And you'll sleep right away!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: And you'll sleep right away!\n");

//         } else {
//                 cr_log_error("FAIL");
//                 cr_fail();

//         }
// }

// Test(takeDrug, strParameter_notEq_BuronzandStrings_and_stdcout_caught,
//         .init=redirect_all_stdout)
// {
//         std::string     _name("SickKoala");
//         std::string     string = "BuronzanD";
//         std::string     s_buronzand("Buronzand");
//         bool            return_value;

//         cr_assert(not(eq(str,string, s_buronzand)));
//         if (string == s_buronzand)
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": And you'll sleep right away!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: : And you'll sleep right away!\n");

//         } else {
//                 return_value = false;
//                 cr_assert(return_value == false);
//                 std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog!\n");
//         }
// }

// Test(takeDrug, strParameter_notEq_strings_and_stdcout_caught2,
//         .init=redirect_all_stdout)
// {
//         std::string     _name("SickKoala");
//         std::string     string = "randomString";
//         std::string     s_buronzand("Buronzand");
//         std::string     s_mars("Mars");
//         bool            return_value;

//         cr_assert(not(eq(str,string, s_buronzand)));
//         cr_assert(not(eq(str,string, s_mars)));
//         if (string == s_buronzand )
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": And you'll sleep right away!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: And you'll sleep right away!\n");
//         } else if (string == s_mars)
//         {
//                 return_value = true;
//                 cr_assert(return_value == true);
//                 std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Mars, and it kreogs!\n");
//         } else
//         {
//                 return_value = false;
//                 cr_assert(return_value == false);
//                 std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
//                 cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog!\n");
//         }
// }

// Test(takeDrug, takeDrug_randomString, .signal=SIGPIPE,
//         .init=redirect_all_stdout)
// {
//         SickKoala sickKoala;

//         cr_assert(sickKoala.takeDrug("random") == false);
//         cr_assert_stdout_eq_str("Mr.SickKoala: Goerkreog!\n");
// }

// Test(takeDrug, takeDrug_marsString, .signal=SIGPIPE,
//         .init=redirect_all_stdout)
// {
//         SickKoala sickKoala;

//         cr_assert(sickKoala.takeDrug("Mars") == true);
//         cr_assert_stdout_eq_str("Mr.SickKoala: Mars, and it kreogs!\n");
// }

// Test(takeDrug, takeDrug_buronzandString, .signal=SIGPIPE,
//         .init=redirect_all_stdout)
// {
//         SickKoala sickKoala;
        
//         cr_assert(sickKoala.takeDrug("Buronzand") == true);
//         cr_assert_stdout_eq_str("Mr.SickKoala: And you'll sleep right away!\n");
// }

// Test(overDrive, strParameter_test)
// {
//         SickKoala sickKoala;
//         std::string instance;

//         cr_assert(zero(str, instance));
//         cr_assert(eq(str, instance, ""));
//         cr_assert_str_empty(instance.data());
//         instance = "Kreog! How's it going?";
//         cr_assert(not(zero(str, instance)));
//         cr_assert(not(eq(str, instance, "")));
//         cr_assert(eq(str, instance, "Kreog! How's it going?"));
//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
// }

// Test(overDrive, find_and_replace_test)
// {
//         SickKoala sickKoala;
//         std::string instance;

//         cr_assert(zero(str, instance));
//         cr_assert(eq(str, instance, ""));
//         cr_assert_str_empty(instance.data());
//         instance = "Kreog! How's it going?";
//         cr_assert(not(zero(str, instance)));
//         cr_assert(not(eq(str, instance, "")));
//         cr_assert(eq(str, instance, "Kreog! How's it going?"));
//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
//         instance.replace(instance.find("Kreog!"), sizeof(instance.find("Kreog!")) - 2, "1337!");
// }

// Test(overDrive, stdout_test, .signal=SIGPIPE, .init=redirect_all_stdout)
// {
//         SickKoala sickKoala;
//         std::string instance;

//         cr_assert(zero(str, instance));
//         cr_assert(eq(str, instance, ""));
//         cr_assert_str_empty(instance.data());
//         instance = "Kreog! How's it going?";
//         cr_assert(not(zero(str, instance)));
//         cr_assert(not(eq(str, instance, "")));
//         cr_assert(eq(str, instance, "Kreog! How's it going?"));
//         cr_assert(ne(str, sickKoala.get_name().data(), ""));
//         cr_assert(eq(str, sickKoala.get_name().data(), "SickKoala"));
//         instance.replace(instance.find("Kreog!"), sizeof(instance.find("Kreog!")) - 2, "1337!");
//         std::cout << "Mr." << sickKoala.get_name() << ": " << instance << std::endl << std::flush;
//         cr_assert_stdout_eq_str("Mr.SickKoala: 1337! How's it going?\n");
// }

// Test(overDrive, test_overDrive_memberFunction,
//         .signal=SIGPIPE, .init=redirect_all_stdout)
// {
//         SickKoala sickKoala;

//         sickKoala.overDrive("Kreog! How's it going?");
//         cr_assert_stdout_eq_str("Mr.SickKoala: 1337! How's it going?\n");
// }