#include <opencv2/opencv.hpp>
#include "Terminal.hpp"

/**
 * @brief Converts a resized frame to grayscale ASCII art.
 * 
 * This function takes a resized frame as input and converts it to grayscale ASCII art.
 * Each pixel value in the resized frame is mapped to a corresponding ASCII character based on its intensity.
 * The resulting ASCII art is returned as a string.
 * 
 * @param resized_frame The resized frame to be converted to grayscale ASCII art.
 * @return The grayscale ASCII art representation of the resized frame.
 */
std::string adapt_to_grayscale(cv::Mat resized_frame)
{
    std::string ascii_art = "";
    
    for(int i = 0; i < resized_frame.rows; i++) {
        for(int j = 0; j < resized_frame.cols; j++) {
            int pixel_value = resized_frame.at<uchar>(i, j);
            switch (pixel_value)
            {
                case 0 ... 35:
                    ascii_art += " ";
                    break;
                case 36 ... 75:
                    ascii_art += ".";
                    break;
                case 76 ... 115:
                    ascii_art += "+";
                    break;
                case 116 ... 155:
                    ascii_art += "*";
                    break;
                case 156 ... 200:
                    ascii_art += "#";
                    break;
                default:
                    ascii_art += "@";
                    break;
            }
        }
        ascii_art += "\n";
    }
    return ascii_art;
}

/**
 * @brief Displays a video frame by frame in ASCII art format on the terminal.
 * 
 * @param video The cv::VideoCapture object representing the video to be displayed.
 * @param term The Terminal object used for displaying the video.
 */
void display_video(cv::VideoCapture video, Terminal term)
{
    cv::Mat frame;
    cv::Mat gray_frame;
    cv::Mat resized_frame;
    bool return_value;
    __UINT_FAST32_TYPE__ fps;
    std::string ascii_art = "";
    struct winsize terminal_size = term.getTerminalSize();

    while (true) {
        return_value = video.read(frame);

        if (return_value == false)
            break;

        cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);
        cv::resize(gray_frame, resized_frame, cv::Size(terminal_size.ws_col, terminal_size.ws_row));

        ascii_art = adapt_to_grayscale(resized_frame);
        std::cout << ascii_art;

    }
    video.release();
}

/**
 * @brief The main function of the program.
 * 
 * @param ac The number of command-line arguments.
 * @param av An array of command-line arguments.
 * @return int The exit status of the program.
 */
int main()
{
    cv::VideoCapture video;
    Terminal term;

    video = cv::VideoCapture(0);
    if (!video.isOpened())
    {
        std::cerr << "Error: Camera not found." << std::endl;
        exit(1);
    }
    display_video(video, term);
}