import torch
from PIL import Image

# Load a pre-trained model
model = torch.hub.load('ultralytics/yolov5', 'yolov5s')

# Load an image
img = Image.open('image.jpg')

# Perform object detection
results = model(img)

# Print results
results.print()
