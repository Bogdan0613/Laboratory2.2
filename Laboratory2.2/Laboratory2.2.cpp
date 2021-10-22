#include<iostream>
#include<cmath>
using namespace std;
static void extracted(float amount, float *coordinate1, float *coordinate2) {
    for(int i=0; i<amount; i++){
        cout<<"Enter the x coordinate of the "<<i+1<<" top:";
        cin>> coordinate1[i];
        cout<<"Enter the y coordinate of the "<<i+1<<" top:";
        cin>> coordinate2[i];
    }
}

int main(){
    float amount, max_y, max_x;
    float length_max, length;
    float x_middle, y_middle, is_cicle=0;
    float radius;
    cout<<"Enter the amount of the sides:";
    cin>>amount;
    float* coordinate1 = new float [amount];
    float* coordinate2 = new float [amount];
    extracted(amount, coordinate1, coordinate2);
    for(int i=1; i<amount;i++){
        coordinate1[0]; //беремо одну довільну точку та вимірюємо довжину до інших
        coordinate2[0];// найбільша довжина це й буде діаметр можливого кола
        length=(coordinate1[0]-coordinate1[i])*(coordinate1[0]-coordinate1[i]) + (coordinate2[0]-coordinate2[i])*(coordinate2[0]-coordinate2[i]);
        if(i==0){
            length_max=length;
            max_x=coordinate1[i];
            max_y=coordinate2[i];
        }
        if(length>=length_max){
            length_max=length;
            max_x=coordinate1[i];
            max_y=coordinate2[i];
        }
    }
    x_middle=(max_x+coordinate1[0])/2; //координати імовірного центра описаного кола
    y_middle=(max_y+coordinate2[0])/2;
    for(int i=1;i<amount;i++){
        length=(coordinate1[i]-x_middle)*(coordinate1[i]-x_middle) + (coordinate2[i]-y_middle)*(coordinate2[i]-y_middle);
        if(length!=length_max/4){//якщо довжини не співпадають то не можна описати коло
            cout<<"This pollynom can't be outlined with any circle!";
            is_cicle=0;
            break;
        }else{
            is_cicle=1;
        }
    }
    if(is_cicle==1){
        cout<<"The circle exists"<<endl<<"Coordinates of the circle center:";
        cout<<"x="<<x_middle<<endl<<"y="<<y_middle<<endl;
        float a= 0.5;
        radius=pow(length_max,a);
        cout<<"Radius="<<radius<<endl;
    }
}
