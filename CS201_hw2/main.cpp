#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
using namespace std;
int maxSubSum2( const vector<int> & a) {
    int maxSum = 0;

    for(int i = 0 ; i < a.size() ; i++){
        int thisSum = 0;
        for(int j = i ; j < a.size() ; j++){
            thisSum += a[j];

            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}
int maxSubSum1( const vector <int> &a )
{
    int maxSum = 0;
    for (int i = 0 ; i < a.size(); i++ )
        for ( int j = i ; j < a.size() ; j++)
    {
        int thisSum = 0 ;
        for (int k = i ; k <= j ; k++)
            thisSum += a[k] ;
        if (thisSum > maxSum)
            maxSum = thisSum;
    }
    return maxSum;
}
int maxSubSum4(const vector <int> &a)
{
    int maxSum = 0 , thisSum=0;
    for(int j = 0; j < a.size() ; j++)
    {
        thisSum += a[j];

        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0 ;
    }

    return maxSum;
}
int maxSumRec(  const vector<int> &a, int left, int right )
{
    if( left == right ) // Basecase
        if (a[left] > 0)
            return a[left];
        else
            return 0;
    int center = (left + right) / 2;
    int maxLeftSum = maxSumRec( a, left, center );
    int maxRightSum = maxSumRec( a, center+1,right );

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for( int i = center; i >= left; i-- )
    {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;

    }
    int maxRightBorderSum = 0, rightBorderSum = 0;
    for ( int j = center + 1; j <= right; j++)
    {
        rightBorderSum += a[j];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    //return max3( maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum );
    return max(max(maxLeftSum,maxRightSum), (maxLeftBorderSum + maxRightBorderSum) );
}
int maxSubSum3( const vector<int> &a )
{
    return maxSumRec( a, 0, a.size() - 1 );
}
int main(){
// Variables
std::chrono::time_point< std::chrono::system_clock > startTime;
std::chrono::duration< double, milli > elapsedTime;

// Array for Input Sizes
int inputSizesForTest[13] = {10,50,100,500,1000,5000,10000,50000,100000,500000,1000000,2000000,3000000};

srand(time(NULL));


vector<int> bag(inputSizesForTest[11]);


for(int i = 0 ; i < inputSizesForTest[11] ; i++){
    // Initializing random value
    bag[i] = rand();
}
startTime = std::chrono::system_clock::now();
maxSubSum4(bag);
//maxSubSum3(bag);
//maxSubSum2(bag);
//maxSubSum1(bag);
elapsedTime = std::chrono::system_clock::now() - startTime;
cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;



return 0;
}

