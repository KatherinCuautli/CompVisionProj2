Author: Katherin Cuautli
CSCI 49369 - Computational Vision

# Provide short descriptions of your algorithms / problem you encountered.

p1

 For Program 1, I found that the best threshold value would be at 138 because using values below 
 this caused rounder edges among the objects and an overally blobbier look to the objects. This is 
 because the threshold value is too small making the condition of which pixels that "pass" too high.
 In other words, we don't want to let too many pixels pass and become white because it looses the 
 sharpness of the objects.
 However, I discovered that using a threshold value above 138 resulted in fuzzier images and an 
 overall loss of the objects in the image due to scratch like visuals across the objects. This is 
 because not enough pixels were able to pass the threshold condition resulting in a loss of important
 details of the objects.


p2

 For program 2 I had a hard time figuring out how to set up the inputs for the command line because 
 I am not very familiar with terminal commands. I had to make sure I was accessing the images from the 
 right folder and giving them program specific names so that I could read them and then edit them in 
 the way I wanted. 
 Unfortunately, I could not figure out how to make both objects of the image appear after I put the binary
 two_objects image through the sequential labeling alogrithm. I would get an image with one gray-scaled 
 object, and even after messing around with the threshold, the second object just would not appear. However, 
 in the many_objects image, all objects would appear except for one that looked faint in color.
 
p3
 ...


