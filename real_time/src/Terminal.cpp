#include "Terminal.hpp"

/**
 * Retrieves the size of the terminal window.
 *
 * @return The size of the terminal window as a `struct winsize` object.
 */
struct winsize Terminal::getTerminalSize()
{
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &_terminal_size);
    return _terminal_size;
}

/**
 * Clears the terminal screen.
 * This function uses escape sequences to clear the screen and move the cursor to the top-left corner.
 */
void Terminal::clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}

/**
 * Calibrates the frames per second (FPS) of the terminal.
 *
 * @param delay The delay in microseconds to calibrate the FPS.
 */
void Terminal::calibrateFPS(useconds_t delay)
{
    usleep(delay);
}
