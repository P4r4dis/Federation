#include "../part4_commander/includes/Federation.hpp"
#include "../part4_commander/includes/WarpSystem.hpp"
#include "../part4_commander/includes/Borg.hpp"

int     main(void)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 10);
    Federation::Ship Independent(150, 230, "Greok");
    WarpSystem::QuantumReactor QR;
    WarpSystem::QuantumReactor QR2;
    WarpSystem::Core core(&QR);
    WarpSystem::Core core2(&QR2);

    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    Independent.setupCore(&core2);
    Independent.checkCore();
    
    QR.setStability(false);
    QR2.setStability(false);
    UssKreog.checkCore();
    Independent.checkCore();

    // UssKreog.~Ship();
    // Independent.~Ship();
    // QR.~QuantumReactor();
    // QR2.~QuantumReactor();
    // core.~Core();
    // core2.~Core();

    /// PART1 BORG /////////////////////////////////////////////////
    /// MAIN FUNCTION 
    // Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
    // Federation::Starfleet::Captain James("James T.Kirk");
    // Federation::Starfleet::Ensign Ensign("Pavel Chekov");
    // WarpSystem::QuantumReactor QR;
    // WarpSystem::QuantumReactor QR2;
    // WarpSystem::Core core(&QR);
    // WarpSystem::Core core2(&QR2);

    // UssKreog.setupCore(&core);
    // UssKreog.checkCore();
    // UssKreog.promote(&James);

    // Borg::Ship Cube;
    // Cube.setupCore(&core2);
    // Cube.checkCore();

    return 0;
}
