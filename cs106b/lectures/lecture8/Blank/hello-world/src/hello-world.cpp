//populate a vector

//headers
#include<iostream>
#include "console.h"
#include "vector.h"
#include"gwindow.h"
#include"math.h"


using namespace std;


// display constants
static const int SCREEN_WIDTH = 600;
static const int SCREEN_HEIGHT = SCREEN_WIDTH;

//func
void drawCenterCir(GWindow& w, GPoint& center, double radius){
    w.drawOval(center.getX()-radius,center.getY()-radius,2*radius,2*radius);
}
void drawRecursive(GWindow& w, int depth, GPoint& center, double radius){
    if(depth==1){
        drawCenterCir(w,center,radius);
    }else{
        drawCenterCir(w,center,radius);

        double childdir=2.0/4*radius;
        for(int i=0;i<6;i++){
            double radiusPerDeg=2.*M_PI/360;
            double radians=childdir*radiusPerDeg;
            double dx = childdir * cos(radians);
            double dy = childdir * sin(radians);
            GPoint childcenter(center.getX()+dx,center.getY()+dy);
            drawRecursive(w,depth-1,childcenter,radius/2);
        }
    }
}


//main
int main(){
    GWindow w(SCREEN_WIDTH,SCREEN_HEIGHT);
    int depth=7;
    GPoint center(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
    drawRecursive(w,depth,center,SCREEN_HEIGHT/2);
    return 0;
}
