# Pollution-prediction-algorithm

The algorithm design and structure. 

 

One of the key features of our project is to implement raw data into prediction sets. 

The reason behind the prediction functions is to generate a pollution outcome for a time and space T (seconds), S (x, y – GPS coordinates). 

Then the algorithm processes all the information gathered and filters it down into the most possible outcome. 

 

The functionality of processing the raw data and trying to generate a function that best represents the input data is detailed in the lines below. 

By using a Polynomial class for a given dot on a bidimensional plane (x, y), the class returns a polynomial function f(x). 

The Polynomial class is to be intersected with other mathematical classes such as exponential, decaying exponential, sinusoidal, etc. Each of these classes, similar to the Polynomial class should return a generated function f(x) for the given bidimensional plane (x, y). The intersection class brings together all the generated functions for that dot and inserts them in an array. 

In a class called IO. We input all the data sets for each sensor. That results in a matrix input of the form [dataSensor[1], dataSensor[2], ... dataSensor[n]], where the dataSensor is a list of dot(x, y) pairs. Such as dataSensor(1) = [(120, 10), (130, 10), (140, 11), (150, 10)]. 

As stated above for each of the individual pairs in each individual list of dataSensors, we compute some possible mathematical functions. 

Each sensor generates multiple results of which only one must be the best approximation. We then make a comparison and check how many of these functions correspond with one another. 

The function with the highest frequency (or the highest number of appearances) is selected and we are being presented with the function that best matches that sensor's behavior.  

The last step is that we can use the produced function for each sensor and approximate any future, present or past pollution value. In the form “HH:MM:SS(time) | P (pollution value)”.  

![7533ea19-49ec-4b9c-a211-447b61a1ec10](https://user-images.githubusercontent.com/78736806/165167648-c33a02d0-cde7-4431-abcb-1aa964ebcd13.jpg)
![1Input3Outputs](https://user-images.githubusercontent.com/78736806/165167546-c3d5b6b4-1d43-41ee-964b-44470249112f.jpg)
![1Input3OutputsWorkedExample](https://user-images.githubusercontent.com/78736806/165167549-b7144f2f-bfc8-4c7a-ab20-7b13856919e0.jpg)
![3Inputs3OutputsContinuation](https://user-images.githubusercontent.com/78736806/165167551-cab68529-0c64-459c-bf5f-21ef113d4d6c.jpg)
![3Inputs9OutputsWorkedExample](https://user-images.githubusercontent.com/78736806/165167554-e1a4d8f0-670f-40c7-ada4-f8e8b609ed80.jpg)
![5Inputs15Outputs](https://user-images.githubusercontent.com/78736806/165167560-9f333023-7139-4ff9-8899-fad13e7b95af.jpg)
[Project Log Book Alex.docx](https://github.com/sagemat/Pollution-prediction-algorithm/files/8557913/Project.Log.Book.Alex.docx)
