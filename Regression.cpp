#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

double randR() {
    double factor = ((double)(rand())) / (double)(RAND_MAX);
    double sgn;
    if (rand() % 2 == 1) sgn = 1;
    else sgn = -1;
    double main = rand();
    return sgn * (main + factor);
}


class regressionModel {
    double **samples;
    int dimensions;
    int sampleNum;
    int highestPow;
public:
    regressionModel(int d, int s) {
        dimensions = d;
        sampleNum = s;
        samples = new double* [dimensions + 2];
        for (int i = 0; i < dimensions + 2; i++)
            samples[i] = new double [sampleNum];
        for (int i = 0; i < sampleNum; i++) {
            for (int j = 0; j < dimensions + 1; j++) {
                if (j != dimensions)
                    cout << "第" << i << "组" << "训练数据的第" << j << "维分量 = ";
                else
                    cout << "第" << i << "组" << "训练数据的实际映射值 = ";
                cin >> samples[j][i];
            }
            samples[dimensions + 1][i] = 0;
        }
    }
    void showSample(int num);
    int getDim();
    int getSamNum();
    int getHiPow();
    double initFunc(double *weighs, double bias, int hp, int num);
}
;


inline void regressionModel::showSample(int num) {
    cout << "数据" << num << "的各维度变量值如下：" << endl;
    for (int i = 0; i < dimensions + 2; i++) {
        if (i < dimensions)
            cout << "X" << i + 1 << " = " << samples[i][num - 1] << endl;
        else if (i == dimensions)
            cout << "Y（训练值）= " << samples[i][num - 1] << endl;
        else
            cout << "Y（实际值）= " << samples[i][num - 1] << endl;
    }
}

inline int regressionModel::getDim() {
    return dimensions;
}

inline int regressionModel::getSamNum() {
    return sampleNum;
}

inline int regressionModel::getHiPow() {
    return highestPow;
}

inline double regressionModel::initFunc(double *weighs, double bias, int hp, int num) {
    highestPow = hp;
    bias = randR();
    weighs = new double [highestPow * dimensions];
    for (int i = 0; i < highestPow * dimensions; i++)
        weighs[i] = randR();
    double sum = 0;
    for (int j = 0; j < dimensions; j++)
        for (int i = 1; i <= highestPow; i++)
            sum += pow(samples[num - 1][j], i) * weighs[j * dimensions + i - 1];
    sum += bias;
    return sum;
}


int main () {
    
}
