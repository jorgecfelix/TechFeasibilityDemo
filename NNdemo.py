from mlxtend.classifier import NeuralNetMLP
import numpy as np
import pandas as pd


dataset = pd.read_csv('test_dot.csv',header=None)

x=dataset.iloc[0:36,1].values
x=np.where(x=='border',2,0)
X=dataset.iloc[0:36,[0,0]].values

X=X[:,1:]

N_output=3
N_features=1
N_hidden=10
Epochs=1000
Eta=0.01
Random_state=1
NN= NeuralNetMLP(n_output=N_output, n_features=N_features,
                 n_hidden=N_hidden,epochs=Epochs,
                 eta=Eta,
                 random_state=Random_state)
# print(NN.shuffle)

NN.fit(X,x)
# print X
y_pred = NN.predict(X)

for i in range(len(y_pred)):
    if(i%6==0):
        print
    print(y_pred[i]),