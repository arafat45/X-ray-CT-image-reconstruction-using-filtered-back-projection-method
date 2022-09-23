# X-ray-CT-image-reconstruction-using-filtered-back-projection-method
To reconstruct an object inside an unit circle firstly the projection data from the object is calculated by following equation:
𝑔(𝑡,ϴ)= ∫𝑓(𝑥,𝑦)𝑑𝑠𝐿(𝑡,𝛳)
Here 𝑔(𝑡,ϴ) is the projection data and 𝑓(𝑥,𝑦) is the function. Then fourier transform of the projection data at variable t is given by following equation: 
𝐺𝛳(ω)= ∫𝑔(𝑡,𝛳)𝑒−𝑗𝜔𝑡𝑑𝑡∞−∞
In this model as a filter shepp filter is used. The equation of the shepp filter is given by the following equation:
𝑄𝑠(ω)=|2𝐵𝛱𝑠𝑖𝑛𝛱ω2𝐵|Π(ω2𝐵) 
Then the operation of the filter in the frequancy domain is done and inverse fourier transform is done. Then the convolution between the filter and projection data is calculated in the projection data domain. Then the original image f(x,y) is obtain the back projection of the convoluted projection data using the following equation: 
𝑓(𝑥,𝑦)= ∫∫𝑔(𝑡,𝛳)ℎ(𝑥𝑐𝑜𝑠𝛳+𝑦𝑠𝑖𝑛𝛳−𝑡)𝑑𝑡𝑑𝛳𝑡𝑚𝑎𝑥−𝑡𝑚𝑎𝑥𝛱0
When |t|>tmax, 𝑔(𝑡,𝛳)=0
Here, ℎ(𝑥𝑐𝑜𝑠𝛳+𝑦𝑠𝑖𝑛𝛳−𝑡) is the filter function.
