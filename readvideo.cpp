#include<iostream>
#include <opencv2/opencv.hpp> 
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

//void ReadMovie(std::string, std::string);



// Read Movie function
void ReadMovie(std::string &file_name, std::string &classifier ){

  // VideoCapture class constructor : open file
  VideoCapture video(file_name);

  // Check if the file has been opened.
  if(!video.isOpened()){
    std::cout << "Failed to open vdieo file.\n";
    return ;
  }

  //Create Window
  cv::namedWindow("hoge", 1);

  //Classifer definition
  std::cout << "classifier: " << classifier << "\n";
  CascadeClassifier cascade(classifier);
//  cascade.load(classifier);

  if(cascade.empty()){
    std::cout << "Failed to load classifier\n";
    return ;
  }

  vector<Rect> faces;


  while(1){
    Mat frame;
    // Get fram from video instance.
    video >> frame;

    //detect object
    cascade.detectMultiScale(frame, faces, 1.1, 3, 0, Size(20,20));
    int i;
    for(i=0; i<faces.size(); i++)
      rectangle(frame, Point(faces[i].x,faces[i].y),Point(faces[i].x + faces[i].width,faces[i].y + faces[i].height),Scalar(0,200,0),3,CV_AA);


    //Show frame to "hoge" window.
    cv::imshow("hoge",frame);

    if(waitKey(30) >= 0) break;
  }

}

int main(int argc, char const *argv[])
{

  std::string file_n = argv[1];
  std::string classifier_n = argv[2];
  ReadMovie(file_n, classifier_n);

return 0;
}

