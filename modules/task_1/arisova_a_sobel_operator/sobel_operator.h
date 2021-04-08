// Copyright 2021 Arisova Anastasia

#ifndef MODULES_TASK_1_ARISOVA_A_SOBEL_OPERATOR_SOBEL_OPERATOR_H_
#define MODULES_TASK_1_ARISOVA_A_SOBEL_OPERATOR_SOBEL_OPERATOR_H_

#include <cmath>
#include <vector>

struct MyImage {
    std::vector<int> data;
    int rows = 0;
    int columns = 0;

    MyImage(const std::vector<int>& data, int rows, int columns) : data(data), rows(rows), columns(columns) {
    }

    MyImage(int rows, int columns) : data(rows * columns, 0), rows(rows), columns(columns) {
    }

    const int& operator()(int x, int y) const {
        return data[x * columns + y];
    }
    int& operator()(int x, int y) {
        return data[x * columns + y];
    }

    bool operator == (const MyImage& image) const {
        if (rows == image.rows && columns == image.columns)
            return true;
        return false;
    }
};

inline int clamp(int value, int min, int max) {
    if (value > max)
        return max;
    if (value < min)
        return min;
    return value;
}

#endif  // MODULES_TASK_1_ARISOVA_A_SOBEL_OPERATOR_SOBEL_OPERATOR_H_