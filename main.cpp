// FCAI – Programming 1 – 2022 - Assignment 3
// Program Name: CS112-203-2nd – S8 - 20210273 - 20210013 - 20210112 - A3FULL.cpp
// Last Modification Date: 23/4/2022
// Omar Mohammad Fayek - 20210273 - A
// Ahmed Gehad Mansour - 20210013 - A
// Hazem Amr Said - 20210112 - A
// Teaching Assistant: Abdulrahman Abdulmonem
// Purpose: applying different filters on grey images
//-------------------------------------------------
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
// declaring some variable to use
unsigned char image[SIZE][SIZE];
unsigned char second_image[SIZE][SIZE];
unsigned char temp_image[SIZE][SIZE];
unsigned char new_image[SIZE][SIZE];
unsigned char new_image2[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];
unsigned char newimage2[SIZE][SIZE];
unsigned char tempImage2[SIZE][SIZE];
// declaring functions to do something

void loadImage ();          // to load an image
void loadImage2 ();         // to load second image
void load_new_Image();      // function to load a new image to save the shrinked image
void saveImage ();          // to save an image
void black_and_white();     // to turn the image into black and white
void invert();              // to invert an image
void merge_images ();       // to merge the image
void flip();                // to flip an image
void lighten_darken();      // to lighten or darken an image
void detectEdges();
void blur_an_image ();      // to blur an image
void shrink_an_image();     // to shrink an image
void savenew_Image ();      // to save the rotated image
void RotateImage90();       // to rotate the image by 90 deg
void RotateImage180();      // to rotate the image by 180 deg
void RotateImage270();      // to rotate the image by 270 deg
void savenew_Image ();      // to save the enlarged image
void enlarge();             // to enlarge the image
void shuffle();		    // to shuffle an image
void mirror();		    // to mirror an image
int main()
{
      int choice; //declaring a variable typed integer
      cout << "Ahlan ya user ya habibi \n"
      "What filter you want to use (GREY IMAGES)?\n(1)  - Black and White Image\n(2)  - Invert an Image\n"
      "(3)  - Merge two Images\n(4)  - Flip an Image\n(5)  - Rotate an Image\n(6)  - Lighten or Darken an Image"
      "\n(7)  - Detect Image Edges\n(8)  - Enlarge an Image\n(9)  - Shrink an Image"
      "\n(10) - Mirror an Image\n(11) - Shuffle an Image\n(12) - Blur an Image\nPress 0 to Exit\n";


      cin >> choice;  // getting input from the user
      // checks if he entered a valid input or not
      while (choice > 12 || choice < 0){
            cout << "invalid input \n";
            cin >> choice;}

      //check if his/her choice matches the filter index
      if (choice == 0){
            return 0;
      }
      else if (choice == 1){
            loadImage();
            black_and_white();
            saveImage();
      }
      else if (choice == 2){
            loadImage();
            invert();
            saveImage();
      }
      else if (choice == 3){
            loadImage();
            loadImage2 ();
            merge_images();
            saveImage();
      }
      else if (choice == 4){
            loadImage();
            flip();
            saveImage();
      }
      else if (choice == 5){
        int ans;
        cout << "1 - Rotate by 90 degree\n"
            "2 - Rotate by 180 degree\n"
            "3 - Rotate by 270 degree\n";

            cin >> ans;
            if(ans == 1)
            {
                loadImage();
                RotateImage90();
                saveImage();
            }
            else if(ans == 2)
            {
                loadImage();
                RotateImage180();
                saveImage();
            }
            else if(ans == 3)
            {
                loadImage();
                RotateImage270();
                saveImage();
            }
      }
      else if (choice == 6){
            loadImage();
            lighten_darken();
            saveImage();
      }
      else if (choice == 7){
            loadImage();
            detectEdges();
            saveImage();
      }
      else if (choice == 8){
            loadImage();
            enlarge ();
            savenew_Image();
      }

      else if (choice == 9){
            loadImage();
            shrink_an_image();
            saveImage();
      }
      else if (choice == 10){
            loadImage();
            mirror();
            saveImage();
      }
      else if (choice == 11){
            loadImage();
            shuffle();
            saveImage();
      }
      else if (choice == 12){
            loadImage();
            blur_an_image();
            saveImage();
      }

return 0;
}
void loadImage () {             // to load the image
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}
//----------------------------
void loadImage2 () {            // to load the second image
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image two file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, second_image);
}
//---------------------------
void saveImage () {             // to save the image
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
//---------------------------
void savenew_Image (){          //to save an image
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, newimage);
}
//---------------------------
void savenew_Image2 (){         // to save another new image
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, newimage2);
}
//---------------------------
// filter number 1 Black and White image
void black_and_white() {
  long average=0;
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            average += image[i][j];//average has the number of all of the pixels of the full image
        }
    }
    average /= (SIZE*SIZE);// average here is the pure grey in the image
    for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE ;j++){
        if (image[i][j] > average)// if the colour of the pixel is more than the average which is pure grey. SO, it will make out of the average, the black colour
                image[i][j] = 255;
            else                // if the colour of the pixel is less than the average which is pure grey. SO, it will make out of the average,the white colour
                image[i][j]=0;
    }

        }
   }
// filter number 2 invert an image
void invert() {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         image[i][j] = 255 - image[i][j];
      }
   }
}

// filter number 3 merge two images
void merge_images() {

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
        //merge two images
        int avg = (image[i][j] + second_image[i][j])/2;
        image[i][j] = avg;
    }
  }
}
// filter number 4 flip an image
void flip(){
    int num;
   	cout << "1-Vertical\n2-Horizontal \n";
   	cin >> num;

   	if(num == 1)//it will rotate the photo around the vertical (y-axis)
	       {
   		for (int i = 0;i < SIZE; i++){
   			 for (int j = 0;j < SIZE/2; j++)
   				 {
    			   long temp = image[i][j];//temp refers to the  full image with all of the pixels in it
    			   image[i][j] = image[i][255 - j];//here we change the column upside down by changing the first pixel in the columnn with the last one and so on
 		   			image[i][255 - j] = temp;}

   	     }
	   }
	   else if (num == 2)//it will rotate the photo aroud the horizontal (x-axis)
	   {
	   		for (int i=0; i < SIZE/2; i++){
   			 for (int j=0; j < SIZE; j++)
   				 {
    			   long temp = image[i][j];//temp refers to the  full image with all of the pixels in it
    			   image[i][j] = image[255-i][j];//here we change the row by changing the first pixel in the row with the last one and so on
 		   			image[255-i][j]= temp;}
   	     }
	   }
}
// filter 5 rotate an image
void RotateImage90()
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=i; j<SIZE; j++)
        {
            int temp = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = temp;
        }
    }
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<(SIZE/2); j++)
        {
            int temp = image[i][j];
            image[i][j] = image[i][SIZE-1-j];
            image[i][SIZE-1-j] = temp;
        }
    }
}
//______________________________________________________________
void RotateImage180()
{
    for(int i=0; i<2; i++)
    {
        RotateImage90();
    }
}
//_______________________________________________________________
void RotateImage270()
{
    for(int i=0; i<3; i++)
    {
        RotateImage90();
    }
}
// filter number 6 lighten or darken an image
void lighten_darken(){

    // declaring choice typed string
    char choice[10];
    cout << "lighten(1) or darken(2)? \n" << endl;
    cin.getline(choice, 10, '\n');

    // checks if the input is valid or not
    while(strlen(choice) != 1){
        cin.getline(choice, 10, '\n');}

    //check if the input is bigger than one and smaller than four
    while ((int)choice[0] > 51 || (int)choice[0] < 49)
        cin.getline(choice, 10, '\n');

    // converting array into integer
    int converted_choice = atoi(choice);

    // here we lighten the image
    if (converted_choice == 1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = (image[i][j] + 255)/2;}
        }
    }
    // here we darken the image
    else if (converted_choice == 2){

        for (int i = 0; i < SIZE; i++){
          for (int j = 0; j < SIZE; j++)
            {
            image[i][j] /= 2;}
        }
     }
}
//filter number 7 detect image edges
void detectEdges() {
    for (int i = 0; i < SIZE; i++) {
       for (int j = 0; j < SIZE; j++) {
           if (image[i][j] > 127)
               image[i][j] = 255;
           else
                image[i][j] = 0;
       }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if(image[i][j]!=image[i+1][j])
                image[i][j]=0;
            else
                image[i][j]=255;
        }
    }
}
// filter number 8 enlarge an image
void enlarge(){
    int quarter ;
    cout<<"Please Enter the number of quarter : ";
    cin>>quarter;
    if(quarter == 1){
        for (int i=0 ;i<=SIZE/2;i++){
            for (int j=0 ;j<=SIZE/2;j++){
                newimage[i*2][j*2]=image[i][j];
                newimage[i*2][j*2+1]=image[i][j];
                newimage[i*2+1][j*2]=image[i][j];
                newimage[i*2+1][j*2+1]=image[i][j];
            }
        }
    }
    else if(quarter == 2){
        for (int i=0 ;i<=SIZE/2;i++){
            for (int j=SIZE/2 ;j<=SIZE;j++){
                newimage[i*2][j*2]=image[i][j];
                newimage[i*2][j*2+1]=image[i][j];
                newimage[i*2+1][j*2]=image[i][j];
                newimage[i*2+1][j*2+1]=image[i][j];
            }
        }
    }
    else if(quarter == 3){
        for (int i=0 ;i<SIZE/2;i++){
            for (int j=0 ;j<=SIZE/2;j++){
                newimage[i*2][j*2]=image[i+127][j];
                newimage[i*2][j*2+1]=image[i+127][j];
                newimage[i*2+1][j*2]=image[i+127][j];
                newimage[i*2+1][j*2+1]=image[i+127][j];
            }
        }
    }
    else if(quarter == 4){
        for (int i=0 ;i<SIZE/2;i++){
            for (int j=SIZE/2 ;j<SIZE;j++){
                newimage[i*2][j*2]=image[i+127][j];
                newimage[i*2][j*2+1]=image[i+127][j];
                newimage[i*2+1][j*2]=image[i+127][j];
                newimage[i*2+1][j*2+1]=image[i+127][j];
            }
        }
    }
}


// filter number 9 shrink an image
void shrink_an_image(){

    int shrink_size;

    cout << "Enter shrink size \n(1)1/2\n(2)1/3\n(3)1/4 \n";
    cin >> shrink_size;

    //it will shrink the image to the half of its dimensions
    if (shrink_size == 1){
        for (int i = 0; i < SIZE; i += 2){
            for (int j = 0; j < SIZE; j += 2){
                image[i/2][j/2] = image[i][j];
            }
        }

        for (int i = SIZE/2; i < SIZE; i++){
            for(int j = 0; j < SIZE/2; j++){
                image[i][j] = 255;

            }
        }
        for (int i = 0; i < SIZE; i++){
            for(int j = SIZE/2; j < SIZE; j++){
                image[i][j] = 255;
            }
        }

    }
    //it will shrink the image to the third of its dimensions
    else if (shrink_size == 2){
        for (int i = 0; i < SIZE; i += 3){
            for (int j = 0; j < SIZE; j += 3){
                image[i/3][j/3] = image[i][j];
            }
        }
        for (int i = SIZE/3; i < SIZE; i++){
            for(int j = 0; j < SIZE/3; j++){
                    image[i][j] = 255;
            }
        }
        for (int i = 0; i < SIZE; i++){
            for(int j = SIZE/3; j < SIZE; j++){
                image[i][j] = 255;
            }
        }

    }
    // it will shrink the image to the forth of its dimensions
    else if (shrink_size == 3){
        for (int i = 0; i < SIZE; i += 4){
            for (int j = 0; j < SIZE; j += 4){
                image[i/4][j/4] = image[i][j];
            }
        }

        for (int i = SIZE/4; i < SIZE; i++){
            for(int j = 0; j < SIZE/4; j++){
                image[i][j] = 255;

            }
        }
        for (int i = 0; i < SIZE; i++){
            for(int j = SIZE/4; j < SIZE; j++){
                image[i][j] = 255;
            }
        }
    }
}
// filter number 10 Mirror an image
void mirror()
   {
    int x;
    cout<<"1 - right\n2 - left\n3 - up\n4 - down" << endl;
    cin>>x;
    if (x==1)
      {
       for (int i=0;i<SIZE;i++)
       {
        for (int j=0;j<SIZE/2;j++)
     {
      image[i][j] = image[i][255-j];

     }
     }
   }
   else if (x==2)
     {
     for (int i=0;i<SIZE;i++)
       {
        for (int j=0;j<SIZE/2;j++)
        {
            image[i][255-j] = image[i][j];
        }
       }
     }
    else if (x==3)
    {
       for (int i=0;i<SIZE/2;i++)
        {
            for (int j=0;j<SIZE;j++)
            {
            image[255-i][j] = image[i][j];
            }
     }
    }
    else if (x==4)
    {
       for (int i=0;i<SIZE/2;i++)
        {
            for (int j=0;j<SIZE;j++)
            {
            image[i][j] = image[255-i][j];
            }
        }
    }

}
// filter number 11 shuffle an image
void shuffle() {
    int p1,p2,p3,p4;
    cout<<"Please,Enter the number of the first quarter in the image\n";
    cin>>p1;
    if(p1==1){
        for (int i=0; i<=SIZE/2; i++) {
            for (int j=0; j<=SIZE/2; j++) {
                new_image[i][j] = image[i][j];
            }
        }
    }
    else if (p1==2){
        for(int i=0 ; i<=SIZE/2 ; i++){
            for(int j =0; j<=SIZE/2 ; j++){
                        new_image[i][j] = image[i][j+SIZE/2];
            }
        }
    }
      else if (p1==3){
        for(int i=0 ; i<=SIZE/2;i++){
            for(int j =0; j<=SIZE/2 ; j++){
                        new_image[i][j] = image[i+SIZE/2][j];
            }
        }
    }
      else if (p1==4){
        for(int i=0 ; i<=SIZE/2;i++){
            for(int j =0; j<=SIZE/2 ; j++){
                        new_image[i][j] = image[i+SIZE/2][j+SIZE/2];
            }
        }
    }
    cout<<"Please,Enter the number of the second quarter in the image \n";
    cin>>p2;
    if(p2==1){
        for (int i=0; i<=SIZE/2; i++) {
            for (int j=SIZE/2; j<=SIZE; j++) {
                    new_image[i][j] = image[i][j-SIZE/2];
            }
        }
    }
    if(p2==2){
        for (int i=0; i<=SIZE/2; i++) {
            for (int j=128; j<=SIZE; j++) {
                    new_image[i][j] = image[i][j];
            }
        }
    }
    else if (p2==3){
       for(int i=0 ; i<=SIZE/2;i++){
            for(int j =SIZE/2; j<=SIZE; j++){
                        new_image[i][j] = image[i+SIZE/2][j-SIZE/2];
            }
        }
    }
    else if (p2==4){
        for(int i=0 ; i<=SIZE/2;i++){
                for (int j =SIZE/2 ; j<=SIZE;j++){
                        new_image[i][j] = image[i+SIZE/2][j];
                }
            }
        }

    cout<<"Please,Enter the number of the third quarter in the image";
    cin>>p3;
        if(p3==1){
            for (int i=SIZE/2; i<=SIZE; i++) {
                for (int j=0; j<=SIZE/2; j++) {
                         new_image[i][j] = image[i-SIZE/2][j];
                    }
                }
            }

    else if (p3==2){
        for (int i=SIZE/2; i<=SIZE; i++) {
            for (int j=0; j<=SIZE/2; j++) {
                    new_image[i][j] = image[i-SIZE/2][j+SIZE/2];
                }
            }
        }
    else if (p3==3){
       for(int i=SIZE/2 ; i<=SIZE;i++){
            for(int j =0; j<=SIZE/2; j++){
                        new_image[i][j] = image[i][j];
            }
        }
    }
    else if (p3==4){
        for(int i=SIZE/2 ; i<=SIZE;i++){
            for(int j =0; j<SIZE/2; j++){
                        new_image[i][j] = image[i][j+SIZE/2];
            }
        }
    }
     cout <<"Please,Enter the number of the fourth quarter in the image";
     cin >>p4;
    if(p4==1){
            for (int i=SIZE/2; i<=SIZE; i++) {
                for (int j=SIZE/2; j<=SIZE; j++){
                            new_image[i][j] =image[i-SIZE/2][j-SIZE/2];
                }
            }
        }
    if(p4==2){
           for (int i=SIZE/2; i<=SIZE; i++) {
                for (int j=SIZE/2; j<=SIZE; j++) {
                         new_image[i][j] =image[i-SIZE/2][j];
                }
            }
        }
   if(p4==3){
           for (int i=SIZE/2; i<=SIZE; i++) {
                for (int j=SIZE/2; j<=SIZE; j++) {
                         new_image[i][j] =image[i][j-SIZE/2];
                }
            }
        }
    if(p4==4){
        for (int i=SIZE/2; i<=SIZE; i++) {
            for (int j=SIZE/2; j<=SIZE; j++) {
                    new_image[i][j] = image[i][j];
            }
        }
    }
}
// filter number 12 blur an image
void blur_an_image() {
  //declaring 4 variables
  int sum;
  int row1, row2, row3;

  for (int i = 1; i < SIZE-1; i++) {
    for (int j = 1; j < SIZE-1; j++) {

        row1 = image[i-1][j-1]+image[i-1][j]+image[i-1][j+1]; //first row of the 3x3 matrix
        row2 = image[i][j-1]+image[i][j]+image[i][j+1];       //second row of the 3x3 matrix
        row3 = image[i+1][j+1]+image[i+1][j]+image[i+1][j-1]; //third row of the 3x3 matrix
        sum = (row1+row2+row3) / 9;                             //extracting the average of the matrix
        image[i][j] = sum;                                    //equalling each pixel to the new value
    }
}
}





