import numpy as np
from sklearn.model_selection import train_test_split

X, y = np.arange(10).reshape((5,2)), range(5)

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.33, random_state=42)


print(f"X_train: \n{X_train}")
print(f"X_test: \n{X_test}")
print(f"y_train: \n{y_train}")
print(f"y_test: \n{y_test}")