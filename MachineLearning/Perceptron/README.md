A perceptron is an algorithm that acts as a simple model of our brain to recognise and discriminate against data to obtain a single identifying function for a set of data.

In other words, it is a function that takes in a set of sample data with valid output values (eg: various features of houses and the price the house sold for) and then outputs a function that returns an accurate prediction for other data (eg: estimate a houses cost based on its features.)

Here is an example of what values can be inputted for the perceptron to return a valid function

```python
max_epochs = Maximum number of iterations before the function gives up trying to create a perceptron

weights = [2, -4] # The initial weight assigned to each data point

bias = 0 # The bias for each weight (a positive value means to favour one value whilst negative means to oppose it)

learning_rate = 0.5 # The rate at which the perceptron learns and adapts is model. Too low value can cause the perceptron to constantly undervalue the data and not adapt within the max_epochs. However, too high a value can cause the perceptron to overvalue the data and never adapt to an accurate model.

examples = []  # The data specified as a list of tuples. The first item in each tuple is the data which itself is another tuple of values and the second item in the tuple is the output value of this data. In this case, the value is either 0 or 1.
examples.append((0,0),0)
examples.append((0,1),0)
examples.append((1,0),0)
examples.append((1,1),1)

max_epochs = 50 # The maximum number of attempts before the function gives up
```

Here is an example of the code performing against the following data

```python
classifier = learn_perceptron(weights, bias, examples, learning_rate, 50)
if not classifier:
  print("No model could be learnt.")
else:
  print(classifier((0,0)))
  print(classifier((0,1)))
  print(classifier((1,0)))
  print(classifier((1,1)))
  print(classifier((2,2)))
  print(classifier((-3,-3)))
  print(classifier((3,-1)))
```

This code is already contained in the python file so just run it to see how it performs
