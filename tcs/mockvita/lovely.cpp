/*Tcs Cart
Problem Description
TCS Cart is an online company that sells planks. Unlike typical planks with predefined shapes and sizes, TCS Cart allows you to order planks for custom shapes.

The custom shape must be a convex polygon, represented by its vertex coordinates. When a custom shape is ordered, it must be cut from a standard rectangular plank. The leftover part of the rectangular plank is considered waste and sent for recycling.

TCS Cart offers rectangular planks in all sizes, with both length and width values being integers. When a customer orders a custom shape, we must select the size of the rectangular plank to minimize waste.

It is specified that the minimum dimensions (both length and breadth) required for the custom shape will be floating-point values, not integers.

Constraints
3 <= N <= 15

0 <= X, Y <= 50.00

Input
The first line consists of an integer N, representing the number vertices of the custom shape.

The following N lines contain two space-separated floating-point values representing the x and y coordinates of each vertex in anti-clockwise direction, with the values having two decimal places.

Output
Print two integers separated by space representing the sides of rectangular plank required, with small value first.

Time Limit (secs)
1

Examples
Example1

Input

4

0.00 0.00

2.00 1.00

2.00 2.00

1.00 0.00

Output

1 3

Explanation

The input shape is drawn in green. The brown rectangular box in the image represents the plank. A 1x3 plank is sufficient to cut out the shape with minimal waste. Hence print 1 3 as output.

Example 2

Input

3

0.00 0.00

1.50 0.50

2.00 2.00

Output

1 3

Explanation

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@3624da92:image2.png

The input shape is drawn in green. The brown rectangular box in the image represents the plank. A 1x3 plank is sufficient to cut out the shape with minimal waste. Hence print 1 3 as output.*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll n;
    cin>>n;
    vector<vector<double>> v(n,vector<double>(2));
    for(ll i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1];
    }

    return 0;
}