// @file MinStack.java
// @desc 用一个stack来实现，push和pop的时候更新最小值
// @auth hatlonely(hatlonely@gmail.com)
// @vers 1.0
// @date 2014-11-13

package hl;

import java.util.Stack;
import java.util.Collections;

public class MinStack {
    private Stack<Integer> dataStack_;
    private int minVal_ = 0;

    public MinStack() {
        dataStack_ = new Stack<Integer>();
        minVal_ = Integer.MAX_VALUE;
    }

    public void push(int x) {
        dataStack_.push(x);
        if (x < minVal_) {
            minVal_ = x;
        }
    }

    public void pop() {
        if (minVal_ == dataStack_.peek()) {
            dataStack_.pop();
            if (dataStack_.size() == 0) {
                minVal_ = Integer.MAX_VALUE;
            } else {
                minVal_ = Collections.min(dataStack_);
            }
        } else {
            dataStack_.pop();
        }
    }

    public int top() {
        return dataStack_.peek();
    }

    public int getMin() {
        return minVal_;
    }
}
