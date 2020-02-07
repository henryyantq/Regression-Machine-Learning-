# Regression(Machine Learning Basic)
A ML-method-based regression programme.

注意：
1、这个项目暂未完成，有意者可以协助完成此项目；
2、这个项目仅用于学习和研究使用，使用此项目得到的模型数据在未经允许的情况下不得公开发表；
3、这个项目是在重造车轮。对于ML的应用型初学爱好者而言没有较大意义，仅供了解回归模型训练的工作原理和程序实现；
4、对于应用型ML开发爱好者，完全可以使用Keras等高度封装的ML代码进行神经网络训练。

对于回归模型训练，主要包含以下三个步骤：
1、初始化模型（函数）
2、选择一个可以评估模型优劣的评估函数（Goodness Function）
3、通过迭代找到最优的模型（函数）

（以二维样本空间的一次函数回归为例）
Step 1：
- 初始化模型参数，这里是指一次回归函数的k和b；
- 假设有 N 个训练样本，每个训练样本可以表示为(x,y0)，将所有的x带入，得到对应的所有y值；
- 这里，所有的y值是指通过初始的模型参数初始化的模型计算得到的y(x)，所有的y0是训练样本的实际值。
Step 2：
- 计算上述所有y和y0的方差（Loss Function）
- 一般为了防止过拟合（Overfitting），会让Loss Function正则化（Regularize），具体方式为：设定一个正则化参数λ，再该例中用λ乘以k的平方；
- 注意，λ值并非越大越好，过大的λ会导致欠拟合（Underfitting）。λ一般选择10-1000之间的数字；
Step 3：
- 在该例中，寻找最优模型的方式是寻找最优的k和b，即通过Loss Function计算得到的Loss最小；
- 我们定义Loss Function为L，设定一个学习率η，从初始的k和b开始，令L分别对k和b求偏导，得到新的k'和b'，其值分别为k（b）减η乘以L对k（b）的偏导；
- 上述步骤被称为梯度下降（Gradient Descent）。重复梯度下降的步骤直到k和b不再变化或在极其有限的范围内小幅度震荡，此时得到的k和b为最优解；
- 注意，上一步骤中的最优解严格意义上为局部最优解（Local Optimal），然而在类似较为简单的案例中，局部最优解即为全局最优解；
- 更高效的梯度下降方案还有很多，在此不多举例；
- 至此，模型训练初步完成。如果发现训练结果错误率较高或训练效率较低，可以选择修改正则化参数或学习率。
- 以上是最基础的的模型训练和调试方案。





