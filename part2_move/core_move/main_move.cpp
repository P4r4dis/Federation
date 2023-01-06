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
    WarpSystem::Core core(&QR);
    WarpSystem::Core core2(&QR2);

    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    UssKreog.promote(&James);

    Borg::Ship Cube;
    Cube.setupCore(&core2);
    Cube.checkCore();

    return 0;
}
