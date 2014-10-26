#include <cassert>
#include "max_points_on_a_line.h"

class TestSolution {
public:
    static void test1() {
        std::vector<Point> vp;
        vp.push_back(Point(-1, -1));
        vp.push_back(Point(2, 2));
        vp.push_back(Point(2, 4));
        vp.push_back(Point(2, 8));
        vp.push_back(Point(2, 9));
        vp.push_back(Point(-3, -3));
        vp.push_back(Point(-3, -3));
        assert(_solution.maxPoints(vp) == 4);
    }
    static void test2() {
        std::vector<Point> vp;
        vp.push_back(Point(0, -12));
        vp.push_back(Point(5, 2));
        vp.push_back(Point(2, 5));
        vp.push_back(Point(0, -5));
        vp.push_back(Point(1, 5));
        vp.push_back(Point(2, -2));
        vp.push_back(Point(5, -4));
        vp.push_back(Point(5, -4));
        vp.push_back(Point(3, 4));
        vp.push_back(Point(-2, 4));
        vp.push_back(Point(-1, 4));
        vp.push_back(Point(0, -5));
        vp.push_back(Point(0, -8));
        vp.push_back(Point(-2, -1));
        vp.push_back(Point(0, -11));
        vp.push_back(Point(0, -9));
        assert(_solution.maxPoints(vp) == 6);
    }
    static void test3() {
        std::vector<Point> vp;
        vp.push_back(Point(1, 1));
        vp.push_back(Point(1, 1));
        vp.push_back(Point(1, 1));
        assert(_solution.maxPoints(vp) == 3);
    }
    static void test4() {
        std::vector<Point> vp;
        vp.push_back(Point(3, 3));
        vp.push_back(Point(2, 2));
        vp.push_back(Point(5, 5));
        vp.push_back(Point(2, 2));
        assert(_solution.maxPoints(vp) == 4);
    }

private:
        static Solution _solution;
};

Solution TestSolution::_solution;


int main() {
    TestSolution::test1();
    TestSolution::test2();
    TestSolution::test3();
    TestSolution::test4();

    return 0;
}
