# X-ray-CT-image-reconstruction-using-filtered-back-projection-method
To reconstruct an object inside an unit circle firstly the projection data from the object is calculated by following equation:
π(π‘,Ο΄)= β«π(π₯,π¦)ππ πΏ(π‘,π³)
Here π(π‘,Ο΄) is the projection data and π(π₯,π¦) is the function. Then fourier transform of the projection data at variable t is given by following equation: 
πΊπ³(Ο)= β«π(π‘,π³)πβπππ‘ππ‘βββ
In this model as a filter shepp filter is used. The equation of the shepp filter is given by the following equation:
ππ (Ο)=|2π΅π±π πππ±Ο2π΅|Ξ (Ο2π΅) 
Then the operation of the filter in the frequancy domain is done and inverse fourier transform is done. Then the convolution between the filter and projection data is calculated in the projection data domain. Then the original image f(x,y) is obtain the back projection of the convoluted projection data using the following equation: 
π(π₯,π¦)= β«β«π(π‘,π³)β(π₯πππ π³+π¦π πππ³βπ‘)ππ‘ππ³π‘πππ₯βπ‘πππ₯π±0
When |t|>tmax, π(π‘,π³)=0
Here, β(π₯πππ π³+π¦π πππ³βπ‘) is the filter function.
