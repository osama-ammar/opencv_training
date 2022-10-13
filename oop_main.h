
//making annotator in oop format for best practice and control]
#include <cstdio>
// good practice for classes is to make 2 files the header (contain functions and variables declarations (prototypes)  and source file
#ifndef MYIMAGE_H  //if not defined 
#define MYIMAGE_H_H  // define

class MyImage{

	public:



	
        //each image will have 3 landmarks ...each landmark has x,y positions
        int landmark_1[2]={0,0};
        //int landmark_2[2]= {0,0};
        //int landmark_3[2]={0,0};



        void set_landmark(int x, int y){
            landmark_1[0] = x;
            landmark_1[1] = y;
            //printf("landmark position: ",x,y);
    
        }



    	MyImage() // constractor
        {

        };

	
};

#endif //MYCLASS_H
















    return 0 ;
};












