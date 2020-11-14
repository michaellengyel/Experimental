# Experimental
TBD

Used Links:

Setting up cmake   
https://www.youtube.com/watch?v=SYgESCQeGJY   
Setting up cmake to include subrepositories and making .sh scripts   
https://www.youtube.com/watch?v=ED-WUk440qc   
Building opencv from src on Ubuntu (Build with opencv_contrib)   
https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html   

Dependencies Quick Guide:   

sudo apt update && sudo apt install -y cmake g++ wget unzip   
wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip   
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/master.zip   
unzip opencv.zip   
unzip opencv_contrib.zip   
mkdir -p build && cd build   
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-master/modules ../opencv-master   
cmake --build .   
sudo make install   


