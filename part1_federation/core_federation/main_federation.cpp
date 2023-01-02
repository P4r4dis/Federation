#include "../includes/my_federation.hpp"
#include "../includes/WarpSystem.hpp"


int     main(void)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
    // Federation::Ship Independent(150, 230, "Greok");
    WarpSystem::QuantumReactor QR;
    if (QR.getStability() == true)
        std::cout << "getStability == true" << std::endl;
    if (QR.isStable() == true)
        std::cout << "isStable == true" << std::endl;

    // WarpSystem::QuantumReactor QR2;
    // WarpSystem::Core core(&QR);
    // WarpSystem::Core core2(&QR2);

    // UssKreog.setupCore(&core);
    // UssKreog.checkCore();
    // Independent.setupCore(&core2);
    // Independent.checkCore();
    
    // QR.setStability(false);
    // QR2.setStability(false);
    // UssKreog.checkCore();
    // Independent.checkCore();

    return 0;
}
