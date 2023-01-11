#ifndef         __ADMIRAL__
# define        __ADMIRAL__

#include <string>
namespace       Federation
{
    namespace   Starfleet
    {
        class   Admiral
        {
            private:
                std::string             _name;
            public:
                Admiral(std::string     name);
                ~Admiral(void);
                std::string             getName(void);
        };
    }
}
#endif //       !__ADMIRAL__