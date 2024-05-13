#pragma once

#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

/**
 * @brief The Terminal class represents a terminal window.
 * 
 * This class provides functionality to interact with the terminal window,
 * such as getting the terminal size, clearing the screen, and calibrating
 * the frames per second (FPS).
 */
class Terminal {
    public:
    /**
     * @brief Get the size of the terminal window.
     * 
     * @return The size of the terminal window as a `struct winsize`.
     */
    struct winsize getTerminalSize();

    /**
     * @brief Clear the contents of the terminal screen.
     */
    void clearScreen();

    /**
     * @brief Calibrate the frames per second (FPS) of the terminal.
     * 
     * @param microseconds The time interval in microseconds between each frame.
     */
    void calibrateFPS(useconds_t microseconds);

    private:
    struct winsize _terminal_size; /**< The size of the terminal window. */
};
