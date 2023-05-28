import cv2
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_digits
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier

# Load a dataset of hand-written digits for simplicity (replace this with your own dataset)
digits = load_digits()
X = digits.images
y = digits.target

# Flatten the images
n_samples = len(X)
X = X.reshape((n_samples, -1))

# Split into train/test
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.5, shuffle=False)

# Fit a k-NN classifier
knn = KNeighborsClassifier()
knn.fit(X_train, y_train)

# Test the classifier on an image
test_image = cv2.imread('test_sign.jpg', cv2.IMREAD_GRAYSCALE)
test_image = cv2.resize(test_image, (8, 8)).reshape((1, -1))
print("Predicted sign:", knn.predict(test_image))
