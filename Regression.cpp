//2019-nCoV 模型训练
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

inline double randR() {
	double factor = ((double)(rand())) / (double)(RAND_MAX);
	double sgn;
	if (rand() % 2 == 1) sgn = 1;
	else sgn = -1;
	double main = rand();
	return sgn * (main + factor);
}	//随机生成一个实数


class regressionModel {
	double **samples;	//训练样本
	int dimensions;	//样本空间维数
	int sampleNum;	//训练样本数量
	int highestPow;	//回归函数的最高次幂
	double regMain;	//平滑度主值
	double learningRate;	//学习率
public:
	regressionModel(int d, int s) {
		dimensions = d;
		sampleNum = s;
		samples = new double*[dimensions + 2];
		for (int i = 0; i < dimensions + 2; i++)
			samples[i] = new double[sampleNum];
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
	}	//初始化训练样本
	void showSample(int num);
	int getDim();
	int getSamNum();
	int getHiPow();
	double initFunc(double *weighs, double bias, int hp, int num);
	double lossFunc(double regular);
	void train(char *str);
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
	weighs = new double[highestPow * dimensions];
	for (int i = 0; i < highestPow * dimensions; i++)
		weighs[i] = randR();
	regMain = 0;
	for (int i = 0; i < highestPow * dimensions; i++)
		regMain += pow(weighs[i], 2);
	double sum = 0;
	for (int j = 0; j < dimensions; j++)
		for (int i = highestPow; i >= 1; i--)
			sum += pow(samples[j][num - 1], i) * weighs[j * dimensions + highestPow - i];
	sum += bias;
		//计算回归函数的y
	samples[dimensions + 1][num - 1] = sum;
		//赋值给模型样本
	return sum;	
}	//回归函数初始化

inline double regressionModel::lossFunc(double regular) {
	double sum;
	for (int i = 0; i < sampleNum; i++)
		sum += pow(samples[dimensions][i] - samples[dimensions + 1][i], 2);
	sum += regular * regMain;
		//加入正则化参数
	return sum;
}	//计算方差

inline void regressionModel::train(char *str) {
	int label = 0;
	if (!strcmp(str, "GD")) {
		label = 1;
		cout << "设定学习率（一般为10的正整数倍）：";
		cin >> learningRate;
	}	//使用一般的Gradient Descent
	else if (!strcmp(str, "Adagrad")) {
		label = 2;
		learningRate = 100;
		cout << "初始化学习率为：100" << endl;
	}	//使用Adagrad
	cout << "【确认开始训练模型，请按Enter】" << endl;
	cin.get();
	if (label == 1) {

	}
	else {
		double rms;	//方均根值
	}
}	//训练模型（可选择两种方案）


int main() {
	
}
