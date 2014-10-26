// @file max_points_on_a_line_hl.hpp
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-10-26
// @desc 思路：将在同一直线上的点放到一个集合中

#include <cfloat>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "point.h"

struct line_t {
    double slope;
    double intercept;
    line_t(Point& point1, Point& point2) {
        if (point2.x - point1.x == 0) {
            slope = DBL_MAX;
            intercept = point1.x;
        } else {
            slope = static_cast<double>(point2.y - point1.y) /
                static_cast<double>(point2.x - point1.x);
            intercept = point1.y - slope * point1.x;
        }
    }
};

struct line_hash {
    size_t operator()(const line_t& line) const {
        return std::hash<double>()(line.slope * line.intercept);
    }
};

struct line_cmp {
    bool operator()(const line_t& line1, const line_t& line2) const {
        return (line1.slope == line2.slope) && (line1.intercept == line2.intercept);
    }
};

struct point_hash {
    size_t operator()(const Point& point) const {
        return std::hash<int>()((point.x << 8) + point.y);
    }
};

struct point_cmp {
    bool operator()(const Point& point1, const Point& point2) const {
        return (point1.x == point2.x) && (point1.y == point2.y);
    }
};

class Solution {
public:
    int maxPoints(std::vector<Point> &points) {
        // eg:
        //  points: [<1, 1>, <4, 5>, <4, 5>, <6, 3>, <1, 1>]
        //  points_without_repeat: [<1, 1>, <4, 5>, <6, 3>]
        //  point_times_map: {<1, 1>: 2, <4, 5>: 2, <6, 3>: 1}
        //  point_times: [2, 3, 1]
        // 点出现次数
        // 不重复点的集合
        std::vector<Point> points_without_repeat;
        std::unordered_map<Point, size_t, point_hash, point_cmp> point_times_map;
        for (Point point : points) {
            if (point_times_map.count(point) == 0) {
                point_times_map[point] = 1;
                points_without_repeat.push_back(point);
            } else {
                point_times_map[point]++;
            }
        }
        // points_without_repeat中每个点出现的次数
        std::vector<size_t> point_times;
        for (Point point : points_without_repeat) {
            point_times.push_back(point_times_map[point]);
        }

        // 两个点一定在一条直线上
        // 如果不重复点小于等于两个，则所有点都在一条直线上
        if (points_without_repeat.size() < 3) {
            return points.size();
        }

        // 将在同一直线上的点都放到一个集合中
        std::unordered_map<line_t, std::unordered_set<size_t>, line_hash, line_cmp> line_indexs_map;
        for (size_t i = 0; i < points_without_repeat.size(); i++) {
            for (size_t j = 0; j < i; j++) {
                line_t line(points_without_repeat[j], points_without_repeat[i]);
                line_indexs_map[line].insert(i);
                line_indexs_map[line].insert(j);
            }
        }

        size_t max = 0;
        // 统计每个集合中点的个数，并求出最大
        for (auto it : line_indexs_map) {
            size_t count = 0;
            for (auto index : it.second) {
                count += point_times[index];
            }
            if (count > max) {
                max = count;
            }
        }

        return max;
    }
};
