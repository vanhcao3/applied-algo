#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;             // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// A function used by sort() to sort an array of
// points with respect to the first point
bool compare(Point p1, Point q1, Point p2, Point q2)
{
    // Find orientation
    int o = orientation(p1, q1, p2);
    if (o == 0)
        return (q1.x - p1.x) * (q1.x - p1.x) + (q1.y - p1.y) * (q1.y - p1.y) <
               (q2.x - p1.x) * (q2.x - p1.x) + (q2.y - p1.y) * (q2.y - p1.y);
    return (o == 2);
}

// Prints convex hull of a set of n points.
vector<Point> convexHull(vector<Point> points, int n)
{
    // There must be at least 3 points
    if (n < 3)
        return {};

    // Initialize Result
    vector<Point> hull;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    int p = l, q;
    do
    {
        // Add current point to result
        hull.push_back(points[p]);

        // Search for a point 'q' such that orientation(p, x,
        // q) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            // If i is more counterclockwise than current q, then
            // update q
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;

    } while (p != l); // While we don't come to first point

    // Return the convex hull
    return hull;
}

// To check if a point lies inside the convex hull
bool isInside(vector<Point> hull, Point p)
{
    int n = hull.size();
    if (n < 3)
        return false;

    for (int i = 0; i < n; i++)
    {
        int next = (i + 1) % n;
        if (orientation(hull[i], hull[next], p) != 2)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convexHull(points, n);

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        Point p;
        cin >> p.x >> p.y;
        cout << (isInside(hull, p) ? 1 : 0) << endl;
    }

    return 0;
}