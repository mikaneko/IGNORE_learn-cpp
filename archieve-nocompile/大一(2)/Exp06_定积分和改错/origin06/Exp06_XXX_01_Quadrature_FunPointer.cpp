/*
题目：实验17，二、2，用求积分近似法，编程求函数在指定区间的定积分。
编程要求：
-  模仿P213,例6.13，面向过程的方式实现通用性代码。
-  将函数指针作为割线法函数的参数，调用时指向不同函数，实现通用性。
-  添加合适的头文件。
-  为检验结果，用近似法对下列被积函数进行定积分计算。

   sin(x)，      下限为 0.0 ，上限为π/2；    [-cosx]=0-(-1)=1                              
   exp(x)，      下限为 0.0 ，上限为 1.0；   [exp(x)]=2.718281828459045-1=1.718281828459045 
   4.0/(1+x*x)， 下限为 0.0 ，上限为 1.0。   [4.0arctan(x)]=pi=3.141592653589794            
   
-  完成了上面三个函数的测试后，可以自行构造函数，设置求积区间，并完成求积计算。
-  矩形法rectangle为课本范例，是本次作业的基本要求。
-  学有余力的同学分别用：矩形法rectangle，梯形法ladder，辛普森法Simpson进行定积分计算，
   并比较积分精度。
*/



