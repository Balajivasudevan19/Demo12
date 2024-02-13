#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <pthread.h>

using namespace std;
using namespace cv;

// Thread data structure
struct ImageData {
  Mat image;
  string imagePath;
};

// Thread function to read an image
void* readImage(void* data) {

  ImageData* imageData = (ImageData*)data;

  try {

    imageData->image = imread(imageData->imagePath);

    if (!imageData->image.data) {
      throw runtime_error("Error reading image: " + imageData->imagePath);
    }
     cout<<"image data read successfully...."<<endl;

  } 
       catch (const exception& e)
 {
    cerr << e.what() << endl;
  }
  return nullptr;
}

// Thread function to display an image
void* showImage(void* data) {

  ImageData* imageData = (ImageData*)data;
  namedWindow("Image", WINDOW_AUTOSIZE);
  imshow("Image", imageData->image);

  waitKey(0);
  destroyWindow("Image");
  return nullptr;
}

int main(int argc,char*argv[]) {
  // Get image paths from command line arguments
  if (argc < 2) {
    cerr << "Usage: ./pthread_opencv <image_path>" << endl;
    return 1;
  }

  // Create image data structure
  ImageData imageData;
  imageData.imagePath = argv[1];

  // Create threads for reading and displaying image
  pthread_t readThread, showThread;
  pthread_create(&readThread, NULL, readImage, &imageData);
  pthread_create(&showThread, NULL, showImage, &imageData);

  // Wait for both threads to finish
  pthread_join(readThread, NULL);
  pthread_join(showThread, NULL);

  return 0;
}
