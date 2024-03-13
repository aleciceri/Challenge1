# Challenge1
Alessandro Ciceri, 225331

The repository is organized as following:
  - Classic: it contains the code for the basic request of the challenge, so the Armijo method with given function and gradient
  - FD_Gradient: it contains the code for the case where in the main is only defined the function and not its gradient, it is implemented a Finite Difference method to obtain the gradient each iteration of the minimization procedure
  - Heavy-ball: it contains the code with the implementation of the heavy-ball method, implementing also the possibility for the user to choose which method to use for the value of the learning rate

To run the wanted method, go in the respectively folder, then it is sufficient to type 'make', then './main'

In the following part I'll describe the folders content one by one 
## Classic
  In this folder there is the Makefile, the main and then the header and source code of functions, where are declared and defined all the methods. 
  
  In the main there is the definition of the function which minimum point is wanted and its gradient, along with all the needed parameters and the call of the method defined to find the minimum.
  
  In functions there is the method armijo to find the minimum point using vectors of arbitrary dimension, and other methods and operator to make the code easier to read. 
  
  The code is divided in these file to make it easier to read and more tidy. In the armijo method you can find the do while loop for the update of the approximated minimum point, with the requested conditions in the while loop. 

## FD_Gradient
  In this folder there is the Makefile, the main and then the header and source code of functions, where are declared and defined all the methods. 
  
  In the main there is the definition of the function which minimum point is wanted, along with all the needed parameters and the call of the method defined to find the minimum. 
  
  In functions there is the method armijo to find the minimum point using vectors of arbitrary dimension, and other methods and operator to make the code easier to read. 
  
  The code is divided in these file to make it easier to read and more tidy. In the armijo method you can find the do while loop for the update of the approximated minimum point, with the requested conditions in the while loop. 
  
  For the computation of the gradient I've applied a centered Euler method componentwisely. 

## Heavy-ball
  In this folder there is the Makefile, the main and then the header and source code of functions, where are declared and defined all the methods. 
  
  In the main there is the definition of the function which minimum point is wanted and its gradient, along with all the needed parameters and the call of the method defined to find the minimum. 
  
  In functions there is the method heavy_ball to find the minimum point using vectors of arbitrary dimension, and other methods and operator to make the code easier to read. 
  
  In this folder it is implemented the heavy-ball method. The code also has the possibility to choose which method to use for the learnign rate $\alpha$ in the update rule: 
    - '0' means you want a constant learning rate 
    - '1' means you want an exponentially decreasing learnign rate 
    - '2' means you want a linearly decreasing learning rate 
    
  For the decreasing condition in the struct I've insterted a parameter mu that has the same meaning as the one present in the challend pdf on Webeep. 
  
  The default value is 0, so a constant learning rate, and it is important to remark that it takes into consideration only the first char value of the first input after ./main, so if you type more than 1 char character or more than 1 input, the rest will be discarded. Since we have a default value, it holds if you don't give an input or if the first char of your input is different from '0','1' or '2'.



TO USE MUPARSER INCLUDE -I../../../../../pacs-examples/Examples/include in makefile, maybe you have to change the number of ../



  
