#include "../includes/Federation.hpp"
#include "../includes/WarpSystem.hpp"
#include "../includes/Borg.hpp"


int     main(void)
{
    // Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
    // Federation::Ship Independent(150, 230, "Greok");
    // WarpSystem::QuantumReactor QR;
    // if (QR.getStability() == true)
    //     std::cout << "getStability == true" << std::endl;
    // if (QR.isStable() == true)
    //     std::cout << "isStable == true" << std::endl;

    // WarpSystem::QuantumReactor QR2;
    // WarpSystem::Core core(&QR);
    // if(core.checkReactor() == &QR)
    //     std::cout << "core.checkReactor is OK" << std::endl;
    // WarpSystem::Core core2(&QR2);
    // if(core2.checkReactor() == &QR2)
    //     std::cout << "core2.checkReactor is OK" << std::endl;

    // UssKreog.setupCore(&core);
    // UssKreog.checkCore();
    // Independent.setupCore(&core2);
    // Independent.checkCore();
    
    // QR.setStability(false);
    // if (QR.getStability() == false)
    //     std::cout << "getStability == false" << std::endl;
    // if (QR.isStable() == false)
    //     std::cout << "isStable == false" << std::endl;
    // QR2.setStability(false);
    // UssKreog.checkCore();
    // Independent.checkCore();

    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
    Federation::Starfleet::Captain James("James T.Kirk");
    // std::cout << "Captain::getName = " << James.getName() << std::endl;
    // James.setAge(5);
    // std::cout << "Captain::setAge and getAge = " << James.getAge() << std::endl;
    Federation::Starfleet::Ensign Ensign("Pavel Chekov");
    WarpSystem::QuantumReactor QR;
    WarpSystem::QuantumReactor QR2;
    WarpSystem::QuantumReactor QR3;
    WarpSystem::Core core(&QR);
    WarpSystem::Core core2(&QR2);
    WarpSystem::Core core3(&QR3);


    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    UssKreog.promote(&James);

    Borg::Ship Cube;
    Cube.setupCore(&core2);
    Cube.checkCore();

    std::cout   << "UssKreog.getLocation(EARTH) = " 
                << UssKreog.getLocation() << std::endl;
    std::cout   << "UssKreog.getHome(EARTH) = " 
                << UssKreog.getHome() << std::endl;

    Federation::Ship    Independent(150, 230, "Greok");
    std::cout   << "Independent.getLocation(VULCAN) = " 
                << Independent.getLocation() << std::endl;
    std::cout   << "Independent.getHome(VULCAN) = " 
                << Independent.getHome() << std::endl;
    std::cout   << "Cube.getLocation(UNICOMPLEX) = " 
                << Cube.getLocation() << std::endl;
    std::cout   << "Cube.getHome(UNICOMPLEX) = " 
                << Cube.getHome() << std::endl;

    Independent.setupCore(&core3);

    std::cout   << "UssKreog location = " << UssKreog.getLocation()
                << std::endl << "UssKreog home = " << UssKreog.getHome()
                << std::endl;
    if (UssKreog.move(4, VULCAN) == true)
    {
        std::cout   << "UssKreog location must be VULCAN = " 
                    << UssKreog.getLocation()
                    << std::endl << "UssKreog home = " << UssKreog.getHome()
                    << std::endl;
    }
    if (UssKreog.move(5) == true)
    {
        std::cout   << "UssKreog location must be EARTH = " 
                    << UssKreog.getLocation()
                    << std::endl << "UssKreog home = " << UssKreog.getHome()
                    << std::endl;
    }
    if (UssKreog.move(UNICOMPLEX) == true)
    {
        std::cout   << "UssKreog location must be UNICOMPLEX = " 
                    << UssKreog.getLocation()
                    << std::endl << "UssKreog home = " << UssKreog.getHome()
                    << std::endl;
    }
    if (UssKreog.move() == true)
    {
        std::cout   << "UssKreog location must be EARTH = " 
                    << UssKreog.getLocation()
                    << std::endl << "UssKreog home = " << UssKreog.getHome()
                    << std::endl;
    }

    /// Independent ///////////
    ///   
    /// 
    std::cout   << "Greok location = " << Independent.getLocation()
                << std::endl << "Greok home = " << Independent.getHome()
                << std::endl;
    if (Independent.move(1, EARTH) == true)
    {
        std::cout   << "Greok location must be EARTH = " 
                    << Independent.getLocation()
                    << std::endl << "Greok home = " << Independent.getHome()
                    << std::endl;
    }
    if (Independent.move(1) == true)
    {
        std::cout   << "Greok location must be VULCAN = " 
                    << Independent.getLocation()
                    << std::endl << "Greok home = " << Independent.getHome()
                    << std::endl;
    }
    if (Independent.move(UNICOMPLEX) == true)
    {
        std::cout   << "Greok location must be UNICOMPLEX = " 
                    << Independent.getLocation()
                    << std::endl << "Greok home = " << Independent.getHome()
                    << std::endl;
    }
    if (Independent.move() == true)
    {
        std::cout   << "Greok location must be VULCAN = " 
                    << Independent.getLocation()
                    << std::endl << "Greok home = " << Independent.getHome()
                    << std::endl;
    }

    /////////////////////////////////////////////////
    //Cube
    ////////////

    std::cout   << "Borgs location = " << Cube.getLocation()
                << std::endl << "Borgs home = " << Cube.getHome()
                << std::endl;
    if (Cube.move(1, EARTH) == true)
    {
        std::cout   << "Borgs location must be EARTH = " 
                    << Cube.getLocation()
                    << std::endl << "Borgs home = " << Cube.getHome()
                    << std::endl;
    }
    if (Cube.move(5) == true)
    {
        std::cout   << "Borgs location must be UNICOMPLEX = " 
                    << Cube.getLocation()
                    << std::endl << "Borgs home = " << Cube.getHome()
                    << std::endl;
    }
    if (Cube.move(VULCAN) == true)
    {
        std::cout   << "Borgs location must be VULCAN = " 
                    << Cube.getLocation()
                    << std::endl << "Borgs home = " << Cube.getHome()
                    << std::endl;
    }
    if (Cube.move() == true)
    {
        std::cout   << "Borgs location must be UNICOMPLEX = " 
                    << Cube.getLocation()
                    << std::endl << "Borgs home = " << Cube.getHome()
                    << std::endl;
    }
    
    return 0;
}
