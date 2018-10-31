'''
This function takes in a set of weights and biases and develops a perceptron for training_examples that is valid for all sample data. If such a perceptrion(function) can be found, it is returned. Otherwise None is returned.

weights = A list of the same length as the training_example data for the weights for each individual data value
bias = The bias for each weight (a positive value means to favour one value whilst negative means to oppose it.
learning_rate = The rate at which the perceptron learns and adapts is model. Too low value can cause the perceptron to constantly undervalue the data and not adapt within the max_epochs. However, too high a value can cause the perceptron to overvalue the data and never adapt to an accurate model.
max_epochs = Maximum number of iterations before the function gives up trying to create a perceptron
'''

def learn_perceptron(weights, bias, training_examples, learning_rate,
                     max_epochs):
    for epoch in range(1, max_epochs + 1):
        # print("-" * 20, "epoch:", epoch, 20 * "-")
        # print("weights: ", weights)
        # print("bias: ", bias)
        seen_error = False
        for input, target in training_examples:
            a = sum(one_input * weight for one_input, weight in zip(input, weights)) + bias
            output = 1 if a >= 0 else 0
            # print("input: {} output: {} target: {}".format(
            #  input, output, target))
            if output != target:
                seen_error = True
                # Now update the weights and bias
                weights = [weight + learning_rate * one_input * (target - output) for one_input, weight in zip(input, weights)]
                bias = bias + learning_rate * (target - output)
                # print("updating the weights and bias to: ", weights, bias)

        if not seen_error:
            def perceptron(input_vector):
                # print(input_vector)
                a = sum(one_input * weight for one_input, weight in zip(input_vector, weights)) + bias
                output = 1 if a >= 0 else 0
                return output
            return perceptron


# Example function call
weights = [2, -4]
bias = 0
learning_rate = 0.5
examples = [
  ((0, 0), 0),
  ((0, 1), 0),
  ((1, 0), 0),
  ((1, 1), 1),
  ]
max_epochs = 50

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
                                   
