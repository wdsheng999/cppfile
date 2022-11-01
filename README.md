【浙江大学 C++ 翁恺老师】 (https://www.bilibili.com/video/BV1dE41167hJ)

https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1214/
cs106b  -->2021 
介绍在issue那个b站视频

cs106b  -->2017 看这个老哥的 https://github.com/Jack-Chan-2001/CS106B
b站视频 https://www.bilibili.com/video/BV1G7411k7jG?p=1&vd_source=2f7ac3a0b8a261c464af7fbaac4c4571
网页 https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1176/


关于g++编译stanford库的问题 
由于斯坦福库中 h文件包括了一些其他cpp 导致 直接使用g++ -I StanfordCPPLib 会报错
当利用vscode的gdb调试器 会出现 需要向 task.json 中加入大量的头文件 
所以 直接利用qt打模板文件 里面qmake导入的时候已经写好了 
