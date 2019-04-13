## Face Detection-in-OpenFrameworks-OpenCV wiki;

With the following code you can perform face detection in openFrameworks. For this the openCV x openFrameworks library is used. 

For running this code all you need are the header files and the files containing the actual code, as well as the HAAR Classifiers which can be found in the _bin folder_.


### In order to get this code running, make sure that you set the right location for the HAAR Classifiers in your ofApp.cpp file. If not, it will throw an error. 
In the setup method, you can find _face_cascade.load_ and _eye_cascade.load_ these are the locations where you want to change path to your local path to the HAAR classifiers.

## Why use an eye classifier and a face classifier for face detection?
By creating a cascade of different classifiers, you drastically improve the accuracy of your system. When you're only considering the face classifier, a lot of false positives can occurs (the system thinks it's a face, but it's actually not).
When first trying to detect a face, and then trying to detect if there are eyes, the system has to pass 2 tests before it can say it has detected a face. You might wonder, what if I want to use other criteria to detect a face (or a person)? Just import the according classifier and add it to the code like already done with the previous examples. Here is a link that contains some useful [HAAR Classifiers](https://github.com/opencv/opencv/tree/master/data/haarcascades)
