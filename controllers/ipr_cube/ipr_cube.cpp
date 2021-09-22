// Copyright 1996-2020 Cyberbotics Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Description:   Simple program to handle a cube with the IPR

#include "IPR.hpp"

#include <webots/Robot.hpp>
#include <webots/Camera.hpp>
#include <iostream>
#include<windows.h>

using namespace webots;
using namespace std;

#define OBJECT_NUMBER 4

double gGrabPosition[] = {3.00660, -1.35619, 1.19083, -3.24647, -2.94524, 0.727475, -0.727475};
double gDropPosition[] = {5.09282, 0.00000, 3.08698, -1.34990, -2.82252, 0.727475, -0.727475};
double gDropPosition1[] = {1.09282, 0.00000, 3.08698, -1.34990, -2.82252, 0.727475, -0.727475};

int main(int argc, char **argv) {
  IPR *ipr = new IPR();
  int co[6] = {1,0,0,1,1};
 
  Camera *camera = ipr->getCamera("camera");
  camera->enable(10*32);
  int width = camera->getWidth();
  int height = camera->getHeight();
  cout<<"vlaaaaaaaaaaaaaaaaaaaa"<<endl;
  cout<<width<<endl;
  cout<<height<<endl;
  cout<<"vlaaaaaaaaaaaaaaaaaaaa"<<endl;
  
  
  
  // const unsigned char *_image = camera->getImage();
  // cout<<">>>>>>>><<<<<<<< "<<(void *)_image<<endl;
  
  int x=32, y=32;
  for(int kk=0; kk<5; kk++){
    
    
    
    const unsigned char *image = camera->getImage();
    int r=0, g=0, b=0;
    if(image != NULL) {
      r = camera->imageGetRed(image, width, x, y);
      g = camera->imageGetGreen(image, width, x, y);
      b = camera->imageGetBlue(image, width, x, y);
      
      // cout<<"------>>"<<g<<endl;
      cout<<r<<" "<<g<<" "<<b<<endl;
      
    }

    ipr->grabCube(gGrabPosition);
    if(co[kk] % 2 == 0){
      ipr->dropCube(gDropPosition);
    }
    else{
      ipr->dropCube(gDropPosition1);  
    }
    ipr->moveToInitPosition();
    
    
 //   for(int ii=0;ii<10000;ii++){
 //     int r = 2323232/ii;
 //   }
    
  }
  delete ipr;
  return 0;
}
