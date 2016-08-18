# test_module_naoqi
Simple module for testing, developed using the new naoqi framework.
You can run it on a remote computer or directly on the robot's CPU.  
- [Reference](http://doc.aldebaran.com/2-4/dev/tutos/create_a_new_service.html#dev-tuto-create-service)  

This module contains two simple functions:
* `sayHelloWord()` : when called, the robot says "Hello word!";
* `getJointValues (std::vector<std::string> jointNames)`: when called, the position angles of the joints defined in jointNames vector are returned.

Once the module is running (in remote or in the robot) you can call the previous functions. You can find an example here:[test_client_naoqi](https://github.com/jokla/test_client_naoqi).



## Prerequisites:
* Install [Python](http://doc.aldebaran.com/2-4/dev/python/install_guide.html) and the C++ SDK ([Instruction Here](http://jokla.me/robotics/install-sdk-c-naoqi/)) 
*  If you are interested to run the module locally:
  * Download the Cross Toolchain 2.4.3 Linux 64
  * Create a toolchain for the cross compilation (I have called `atom_2_4`) ([Instructions](http://doc.aldebaran.com/2-4/dev/cpp/install_guide.html#e-compile-and-run-an-example))
## Instructions:  
* Clone the repository in your workspace:
`$ git@github.com:jokla/test_module_naoqi.git `

### Run the module in remote

* Configure remote module:  
`$ qibuild configure -c toolchain_2_4`  
* Build:
`$ qibuild build -c toolchain_2_4`
* Run the module in remote (change the argument `--qi-url`  with your robot ip and port):  
`$  ./build-toolchain_2_4/sdk/bin/myservice --qi-url=tcp://127.0.0.1:9559`    
 Arguments reference: [link](http://doc.aldebaran.com/2-4/dev/libqi/guide/qi-app-arguments.html)

### Run the module locally 

* Configure local module:  
`$ qibuild configure -c atom_2_4`  
* Build:
`$ qibuild build -c atom_2_4`
* Create pkg:  
`$ qipkg make-package test_module.pml -c atom_2_4`
* Deploy in Pepper:  
`$ qipkg deploy-package test_module-0.1.0.pkg --url nao@127.0.0.1`
