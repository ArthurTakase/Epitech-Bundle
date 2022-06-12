#include "Ncurses/DisplayNcurses.hpp"
#include "SFML/DisplaySFML.hpp"

bool isGraphical(int ac, char **av) 
{
    if (ac > 1)
        for (int i = 1; i != ac; i++) {
            if (!strcmp(av[i], "-g"))
                return true;
        }
    return false;
}

int main(int argc, char **argv)
{
    srandom(time(NULL));
    if (isGraphical(argc, argv)) {
        DisplaySFML Kreog(argc, argv);
        Kreog.display();
        return 0;
    }
    DisplayNcurses Kreog(argc, argv);
    while (Kreog.display());
    return 0;
}