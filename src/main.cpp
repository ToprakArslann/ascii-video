#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
using namespace cv;


string ascii_chars = " .,:ilwW";
char get_ascii_char(int brightness){
    int index = (brightness * (ascii_chars.length() - 1) / 255);
    return ascii_chars[index];
}

int main(){
    VideoCapture cap("input.mp4");

    int widthFrame = cap.get(CAP_PROP_FRAME_WIDTH);
    int heightFrame = cap.get(CAP_PROP_FRAME_HEIGHT);
    int width = 250;
    int height = 50;
    height = (width * heightFrame / widthFrame) * 0.5;
    width = (width * widthFrame / heightFrame) * 0.5;
    
    if(!cap.isOpened()) {
        cerr << "Cant open video!" << endl;
        cin.get();
        return -1;
    }
    
    Mat frame, gray_frame, resized_frame;

    while (cap.read(frame)){
        cvtColor(frame, gray_frame, COLOR_BGR2GRAY);
        resize(gray_frame, resized_frame, Size(width,height));

        string ascii_art;
        for (int y = 0; y < resized_frame.rows; y++){
            for (int x = 0; x < resized_frame.cols; x++){
                int brightness = resized_frame.at<uchar>(y, x);
                ascii_art += get_ascii_char(brightness); 
            }
            ascii_art += "\n";
        }

        cout << system("cls") << ascii_art;
        this_thread::sleep_for(chrono::milliseconds(33));
    }
    return 0;
}

