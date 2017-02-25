#Problem:-<br>
<b>You are given thee integers a,b,m. Writes a b times on a board in a row to form large number. Say it become x. Output the value 
of x modulo m.</b><br>
<b>Example :- a=12,b=2,m=17 then x=1212 and x%m=5.</b><br>
<b>So 5 is our answer.</b><br>
#Constraints:-<br>
<b>0 < a <=1000</b><br>
<b>0 < b <=1000000000000</b><br>
<b>0 < n <=1000000000</b><br>
#Solution:-<br>
<b>Let us think what will happen if a will be written in a row.</b><br>
<b>Consider a=2017</b><br>
<b>Written twice :- 20172017=2017*10<sup>4</sup>+2017</b><br>
<b>Written thrice :- 201720172017=20172017*10<sup>4</sup>+2017</b><br>
<b>and so on continued...</b><br>
<b>We get the value of each step from the value of previous step. Mathematically this recurrence can be written as</b><br>
<b>S<sub>n</sub>=x*S<sub>n-1</sub>+a where x=10<sup>Number of digits in a</sup></b><br>
<b>We can solve this problem by Matrix Exponentiation as follows :</b><br>
<b>     Let a 2*2 matrix be MAT whose values are MAT[0][0]=x%m where x=10<sup>Number of digits in a</sup>,MAT[0][1]=MAT[1][1]=1,MAT[1][0]=0</b><br>
<b>Multiply MAT with column matrix with 2*1 column matrix PREV whose values are PREV[0][0]=S<sub>n</sub> where S<sub>n</sub>=Solution and PREV[1][0]=a</b><br>
<b>Save this multiplication in 2*1 column matrix RESULT whose values will be S<sub>n+1</sub>(Your answer) and a.</b><br>
