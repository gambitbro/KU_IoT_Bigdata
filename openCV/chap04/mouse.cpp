#include "opencv2/opencv.hpp"
#include <iostream>
#include "opencv2/freetype.hpp"

using namespace cv;
using namespace std;
string folder = "/home/qq43/KIB/openCV/data/";
void onMouse(int event, int x, int y, int flags, void *);


struct MyData{
    Point ptOld;
    Point ptNew;
    Mat img;
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);

    bool flag = false;
};

int main()
{   
    MyData myData;
    myData.img = imread(folder+"lenna.bmp", IMREAD_COLOR);

    namedWindow("img");      //앞으로 img라는 이름의 윈도우를 쓰겠다 선언
    setMouseCallback("img", onMouse, (void*)&myData);

    imshow("img", myData.img);
    waitKey(0);
    destroyAllWindows();
    return 0;
}

void onMouse(int event, int x, int y, int flags, void *myData)
{
    MyData *ptr = (MyData *)myData;
    switch (event){
        case EVENT_LBUTTONDOWN:
            ptr->ptOld = Point(x, y);
            cout << "Event Left Button Down: " << x << ", " << y << endl;
            ptr->flag = true;
            break;
        case EVENT_LBUTTONUP:
            // ptNew = Point(x, y);
            cout << "Event Left Button UP: " << x << ", " << y << endl;
            ptr->flag = false;
            break;
        case EVENT_MOUSEMOVE:
            
            if(ptr->flag & EVENT_FLAG_LBUTTON){
                line(ptr->img, ptr->ptOld, Point(x, y), ptr->green, 5);
                ptr->ptOld = Point(x, y);
                imshow("img", ptr->img);
            }
            break;
    
        default:
            break;
    }
}