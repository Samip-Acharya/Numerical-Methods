#include <iostream>
#include <math.h> 
using namespace std; 

typedef struct Data
{
    float x; 
    float y; 
}Data; 

class LinearRegression
{ 
        Data *dataArray; 
        int size; 
        float xMean; 
        float yMean;
        float m,b; //m = slope and b = y-intercept
    public: 
        LinearRegression()
        {
            this->dataArray = NULL; 
            this->size = -1;
            this->xMean = 0; 
            this->yMean = 0; 
            this->m = 0; 
        }
        void train(Data *dataArray, int size)
        {
            this->dataArray = dataArray; 
            this->size = size; 
            for(int i = 0; i<size; i++)
            {
                xMean += dataArray[i].x; 
                yMean += dataArray[i].y; 
            }
            xMean /= size; 
            yMean /= size;
            float num,den; 
            num=den=0; 
            for(int i = 0; i<size; i++)
            {
                num += (dataArray[i].x-xMean) * (dataArray[i].y-yMean); 
                den += pow((dataArray[i].x - xMean),2); 
            }
            m = num/den; 
            b = yMean - m*xMean; 
            cout << "The best fit line is:" << endl << "y = " << m << "x + " << b << endl; 
        }
        void predict(float x)
        {
            cout << "Output corresponding to " << x << " is " << m*x + b << endl; 
        }
};

int main()
{
    //Inputting Data
    int n; 
    cout << "Enter the number of datasets" << endl; 
    cin >> n; 
    Data *dataArray = new Data[n]; 
    for(int i=0;i<n;i++)
    {
        Data temp; 
        cout << "Node " << i << ":" << endl; 
        cout << "x: " << endl;  
        cin >> temp.x; 
        cout << "y: " << endl;  
        cin >> temp.y; 
        dataArray[i] = temp; 
    }

    //Creating,training and deploying model
    LinearRegression *model = new LinearRegression; 
    model->train(dataArray,n); 
    float val; 
    cout << "Enter the value of x for which you want to predict y" << endl; 
    cin >> val; 
    model->predict(val); 
    delete[] dataArray; 
    return 0;
}